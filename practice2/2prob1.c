//test case all clear
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main(void) {
	char str1[20];
	char str2[20];
	scanf("%s", str1);
	scanf("%s", str2);
	int a = 0;
	
	for (int i = 0; i < strlen(str1); i++) {
		int check = 0;
		for (int j = 0; j < strlen(str2); j++) {
			if (str1[i]==str2[j]) {
				check = 1;
			}
		}
		if (check == 0) {
			a = 1;
		}
	}
	for (int i = 0; i < strlen(str2); i++) {
		int check = 0;
		for (int j = 0; j < strlen(str1); j++) {
			if (str1[i] == str2[j]) {
				check = 1;
			}
		}
		if (check == 0) {
			a = 1;
		}
	}
	if (a == 1) {
		printf("no");
	}
	else {
		printf("yes");
	}
}