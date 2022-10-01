//test case all clear
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

int main(){
	int m,n,k;
	int cnt = 0;
	char* buffer = (char*)malloc(sizeof(char)*MAX);
	FILE* fp = fopen("table.txt", "r");
	FILE* fs = fopen("output.txt", "w");
	char* word[MAX];
	char word2[MAX][MAX];
	int len[MAX];
	int max[MAX];
	
	while (!feof(fp)) {
		fscanf(fp, "%d %d ", &m, &n);
		for (int i = 0; i < n; i++) {
			fgets(buffer, MAX, fp);
			word[cnt] = strdup(strtok(buffer, "&"));
			cnt++;
			for (int j = 0; j < m-2; j++) {
				word[cnt] = strdup(strtok(NULL, "&"));
				cnt++;
			}
			word[cnt] = strdup(strtok(NULL, "\n"));
			cnt++;
		}
	}
	fclose(fp);
	for (int i = 0; i < cnt; i++) {
		strcpy(word2[i] ,word[i]);
		len[i] = strlen(word2[i]);

	}
	
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < len[i]; j++) {
			if (j == 0 && word2[i][j] == ' ') {
				for (int k = j; k < len[i] - 1; k++) {
					word2[i][k] = word2[i][k + 1];
				}
				len[i]--;
				j--;
			}
			if (j > 0 && word2[i][j] == ' ' && word2[i][j - 1] == ' ') {
				for (int k = j; k < len[i] - 1; k++) {
					word2[i][k] = word2[i][k + 1];
				}
				len[i]--;
				j--;
			}
		}
	}

	for (int i = 0; i < cnt; i++) {
		if (len[i] > max[i%m]) {
			max[i%m] = len[i];
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int z = 0; z < len[c]-1; z++) {
				fprintf(fs,"%c", word2[c][z]);
			}
			if (len[c] < max[c % m]) {
				for (int k = 0; k < max[c%m] - len[c]; k++) {
					fprintf(fs," ");
				}
			}
			if (len[c] != 0) {
				fprintf(fs," ");
			}
			c++;
		}
		fprintf(fs,"\n");
	}
	fclose(fs);
}