//테스트 케이스 모두 통과
#include <stdio.h>

	int main() {
		int n;
		scanf_s("%d", &n);
		int arr[10000];
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &arr[i]);
		}
		int min1 = arr[0];
		int min2 = arr[1];
		int check = 0;
		for (int i = 0; i < n; i++) {
			if (min1 > arr[i]) {
				min1 = arr[i];
				check = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (min2 > arr[i] && check != i) {
				min2 = arr[i];
			}
		}
		printf("%d %d", min1, min2);
	}
