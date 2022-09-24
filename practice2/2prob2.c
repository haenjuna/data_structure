//test case all clear
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char* name;
    char* word[100000];
    char temp[MAX];
    char insert[MAX];

    FILE* fp = NULL;

    fp = fopen("harry.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "File Open Error!\n");
        exit(1);
    }
    int a = 0;
    for (a = 0; !feof(fp); a++)
    {
        name = (char*)malloc(sizeof(char) * MAX);
        fscanf(fp, "%s", name);
        word[a] = name;
    }
    a--;

    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            if (strcmp(word[i], word[j]) > 0) {
                    strcpy(temp, word[i]);
                    strcpy(word[i], word[j]);
                    strcpy(word[j], temp);
                }
            
        }
    }
    int idx = 0;
    while (idx <= a) {
        if (strcmp(word[idx], word[idx+1]) == 0) {
            for (int i = idx + 1; i < a - 1; i++) {
                strcpy(word[i], word[i + 1]);
              }
            idx--;
            a--;
        }
        idx++;
    }
    int k = 0;
    scanf("%s", insert);
    
    for (int i = 0; i < a; i++) {
        if (strncmp(insert, word[i], strlen(insert))==0) {
            printf("%s\n",word[i]);
            k++;
        }
    }
    printf("%d", k);

    fclose(fp);

    return 0;
}