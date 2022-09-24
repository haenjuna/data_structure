//테스트 데이터 모두 통과
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char word[100][20];
int n;
char temp[20];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
	}
	compare(n);
	for (int i = 0; i < n; i++) {
		printf("%s\n", word[i]);
	}
}
int compare(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strlen(word[i]) > strlen(word[j])) {
				strcpy(temp, word[i]);
				strcpy(word[i],word[j]);
				strcpy(word[j], temp);
			}
			else if (strlen(word[i]) == strlen(word[j])) {
				if (strcmp(word[i], word[j]) > 0) {
					strcpy(temp, word[i]);
					strcpy(word[i], word[j]);
					strcpy(word[j], temp);
				}
			}
		}
	}
}