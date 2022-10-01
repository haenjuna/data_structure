//test case all clear
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000


int main(){
	int arr[10][10];
	double row[10][2];
	double col[10][2];
	int n;
	int k;
	FILE* fp = fopen("input.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d", &k);
		n = k;
		printf("%d\n", n);
		for (int i = 0; i < n; i++) {
			double sum = 0;
			for (int j = 0; j < n; j++) {
				fscanf(fp, "%d", &k);
				arr[i][j] = k;
				sum = sum + (double)k;
			}
			row[i][0] = sum / n;
		}
	}
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			sum = sum + arr[j][i];
		}
		col[i][0] = sum / n;
	}
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			double pch = (double)arr[i][j] - row[i][0];
			sum = sum +pow(pch, 2);
		}
		row[i][1] = sqrt(sum / n);
	}
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			double pch = (double)arr[j][i] - col[i][0];
			sum = sum + pow(pch, 2);
		}
		col[i][1] = sqrt(sum / n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("%0.2lf %0.2lf\n", row[i][0], row[i][1]);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			printf("%0.2lf ", col[j][i]);
		}
		printf("\n");
	}
}