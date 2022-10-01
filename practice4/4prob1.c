#define _CRT_SECURE_NO_WARINGS

#include <stdio.h>

int main(){
	int n;
	int arr[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}