//test case all clear
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
void show();
void colmax();
void colmin();
void rowmax();
void rowmin();
void slice();
int arr[101][101];
int n;

int main() {
	FILE* fp = fopen("data.mat", "r");
	int k;
	if (fp == NULL)
	{
		fprintf(stderr, "File Open Error!\n");
	}
	while (!feof(fp)) {
		fscanf(fp, "%d ", &k);
		n = k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fscanf(fp, "%d ", &k);
				arr[i][j] = k;
			}
		}
	}
	fclose(fp);
	char input[100];
	while (1) {
		printf("$ ");
		scanf("%s", input);
		if (strcmp(input, "show") == 0) {
			show();
		}
		if (strcmp(input, "colmax") == 0) {
			colmax();
		}
		if (strcmp(input, "colmin") == 0) {
			colmin();
		}
		if (strcmp(input, "rowmax") == 0) {
			rowmax();
		}
		if (strcmp(input, "rowmin") == 0) {
			rowmin();
		}
		if (strcmp(input, "slice") == 0) {
			int x, p, y, q;
			scanf("%d %d %d %d", &x, &p, &y, &q);
			slice(x,p,y,q);
		}
		if (strcmp(input, "exit") == 0) {
			break;
		}
	}
}
void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void colmax() {
	for (int i = 0; i < n; i++) {
		int max = -100;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] > max) {
				max = arr[j][i];
			}
		}
		printf("%d ",max);
	}
	printf("\n");
}
void colmin() {
	for (int i = 0; i < n; i++) {
		int min = 100;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] < min) {
				min = arr[j][i];
			}
		}
		printf("%d ", min);
	}
	printf("\n");
}

void rowmax() {
	for (int i = 0; i < n; i++) {
		int max = -100;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
		printf("%d ", max);
	}
	printf("\n");
}
void rowmin() {
	for (int i = 0; i < n; i++) {
		int min = 100;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
		printf("%d ", min);
	}
	printf("\n");
}
void slice(int x, int p, int y, int q) {
	for (int i = x; i < n; i = i + p) {
		for (int j = y; j < n; j = j + q) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}