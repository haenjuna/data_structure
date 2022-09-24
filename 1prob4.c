//테스트 케이스 모두 통과
#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int arr[101];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	int k;
	scanf_s("%d", &k);
	int min=100000;
	int number;
	for (int i = 0; i < n; i++) {
		int a = k - arr[i];
		if (a < 0) {
			a = -a;
		}
		if (a <= min) {
			min = a;
			number = arr[i];
		}
	}
	printf("%d", number);
}