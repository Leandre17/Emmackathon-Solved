/*
** PERSO, 2023
** emmackathon
** File description:
** ec06
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    char s[1024];
    int count = -1;
    int TF, TP, TA, CF, CP, CA = 0;
    int next = -1;

	while (scanf("%s", &s) != EOF) {
        count += 1;
        if (count == 0)
            TF = atoi(s);
        else if (count == 1)
            TP = atoi(s);
        else if (count == 2)
            TA = atoi(s);
        else if (count % 2 == 0) {
            if (s[0] == 'F')
                next = 1;
            else if (s[0] == 'P')
                next = 2;
            else if (s[0] == 'A')
                next = 3;
        } else {
            if (next == 1)
                CF += atoi(s);
            else if (next == 2)
                CP += atoi(s);
            else if (next == 3)
                CA += atoi(s);
            next = 0;
        }
	}
    if (CA <= TA && CP <= TP && CF <= TF)
        printf("oui");
    else
        printf("non");
	return 0;
}