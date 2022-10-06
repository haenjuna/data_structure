//test case all clear
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

int main() {
	char word[1000];
	char res[1000];
	char w[100];
	scanf("%s", word);
	int max = 0;
	int c1=0,c2 = 0;
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] != 'a' && word[i] != 'i' && word[i] != 'o' && word[i] != 'e' && word[i] != 'u') {
			res[c1] = word[i];
			c1++;
		}
		else {
			if (c1 > max) {
				for (int j = 0; j < c1; j++) {
					w[j] = res[j];
				}
				max = c1;
			}
			c1 = 0;
		}
	}
	if (c1 > max) {
		for (int j = 0; j < c1; j++) {
			w[j] = res[j];
		}
		max = c1;
	}
	for (int i = 0; i < max; i++) {
		printf("%c", w[i]);
	}
}