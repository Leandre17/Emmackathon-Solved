/*
** PERSO, 2023
** emmackathon
** File description:
** ec06
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct vaches_s {
    int age;
    int masse;
    char *name;
    int note;
    int count;
} vaches_t;

vaches_t **read_all()
{
   char *line = NULL;
   size_t size;
   int count = -2;
   vaches_t **vaches = NULL;
  
	while (getline(&line, &size, stdin) != -1) {
        count += 1;
        if (count == -1)
            vaches = malloc(sizeof(vaches_t *) * atoi(line));
        else {
            vaches[count] = malloc(sizeof(vaches_t));
            vaches[count]->name = strdup(strtok(line, " "));
            vaches[count]->age = atoi(strtok(NULL, " "));
            vaches[count]->masse = atoi(strtok(NULL, " "));
            vaches[count]->note = atoi(strtok(NULL, " "));
            vaches[count]->note += atoi(strtok(NULL, " "));
        }
	}
	vaches[0]->count = count;
    return vaches;
}

char *check_vache(vaches_t **vaches, int count)
{
    int best = 0;
    char *best_name = NULL;
 
    for (int i = 0; i < count + 1; i++) {
        if (vaches[i]->masse > 1500 || vaches[i]->masse < 1250)
            continue;
        if (vaches[i]->age < 2 || vaches[i]->age > 5)
            continue;
        if (vaches[i]->note > best) {
            best_name = strdup(vaches[i]->name);
            best = vaches[i]->note;
        } else if (vaches[i]->note == best) {
            best_name = strcat(best_name, " ");
            best_name = strcat(best_name, strdup(vaches[i]->name));
        }
    }
    return best_name;
}

int main() {
    vaches_t **vaches = read_all();
    int count = vaches[0]->count;
    char *best_name = check_vache(vaches, count);

    printf("%s\n", best_name);
    
    return 0;
}
