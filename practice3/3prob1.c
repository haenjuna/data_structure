#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 100

int main(){	
	int n;
	int data[MAX];
	int max;
	int add;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	int a = n;
	int temp;
	while (a != 0) {
		max = data[0];
		add = 0;
		for (int i = 0; i < a; i++) {
			if (data[i] > max) {
				max = data[i];
				add = i;
			}
		}
		temp = data[a - 1];
		data[a - 1] = max;
		data[add] = temp;
		a--;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}