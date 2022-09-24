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

    FILE* fp = NULL;

    fp = fopen("harry.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "File Open Error!\n");
        exit(1);
    }
    int a = 0;
    while (!feof(fp))
    {
        name = (char*)malloc(sizeof(char) * MAX);
        fscanf(fp, "%s", name);
        if (strlen(name) >= 6) {
            word[a] = name;
            a++;
        }
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
    int idx2 = 0;
    int count2 = 0;
    while (idx < a) {
        int count = 0;
        idx2 = idx+1;
        if (strcmp(word[idx], word[idx2]) == 0) {
            while (strcmp(word[idx], word[idx2]) == 0) {
                count++;
                idx2++;
            }
        }
        printf("%s: %d\n", word[idx], count+1);
        idx = idx2;
        count2++;
    }
    printf("%d", count2);
   
    fclose(fp);

    return 0;
}