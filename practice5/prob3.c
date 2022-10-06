//test case all clear
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
int arr[20][20];
void e(int x);
void se(int x);
void s(int x);
void sw(int x);


int winner=0;
int m;

int main() {
	int k;
	FILE* fp = fopen("board.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d ", &k);
		m = k;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				fscanf(fp, "%d ", &k);
				arr[i][j] = k;
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
	fclose(fp);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == arr[i+1][j]&& arr[i][j]!=0) {
				s(i, j, arr[i][j], 1);
			}
			if (arr[i][j] == arr[i + 1][j+1] && arr[i][j] != 0) {
				se(i, j, arr[i][j], 1);
			}
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] != 0) {
				e(i, j, arr[i][j], 1);
			}
			if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] != 0) {
				sw(i, j, arr[i][j], 1);
			}
		}
		if (winner != 0) {
			break;
		}
	}
	if (winner == 0) {
		printf("Not Finished");
	}
	else if (winner == 1) {
		printf("Black");
	}
	else {
		printf("White");
	}
}
void s(int i,int j,int x,int c) {
	if (c == 5) {
		winner = x;
	}
	if (arr[i+1][j] == x && c<5 && i+1<m) {
		s(i+1, j, x,c+1);
	}
}
void se(int i, int j, int x, int c) {
	if (c == 5) {
		winner = x;
	}
	if (arr[i + 1][j+1] == x && c < 5 && i + 1 < m &&j+1<m) {
		se(i + 1, j+1, x, c + 1);
	}
}
void e(int i, int j, int x, int c) {
	if (c == 5) {
		winner = x;
	}
	if (arr[i][j+1] == x && c < 5 && j + 1 < m) {
		e(i, j+1, x, c + 1);
	}
}
void sw(int i, int j, int x, int c) {
	if (c == 5) {
		winner = x;
	}
	if (arr[i + 1][j-1] == x && c < 5 && i + 1 < m && j-1>=0) {
		sw(i + 1, j-1, x, c + 1);
	}
}