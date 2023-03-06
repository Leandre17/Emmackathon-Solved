/*
** PERSO, 2023
** emmackathon
** File description:
** ec06
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
   char s[1024];
   float i = 0;
   int j = 0;

	while (scanf("%s", &s) != EOF)
	    i += atoi(s);
    j = i / 2;
    if (j < i / 2)
        printf("%d\n", j + 1);
    else
        printf("%d\n", j);
	return 0;
}