//테스트 케이스 모두 통과
#include <stdio.h>

int main() {
		int n = 1;
		int c = 0;
		int arr[101] = { 0, };
		while (n != -1) {
			scanf_s("%d", &n);
			if (n == -1) {
				break;
			}
			for (int i = 0; i <= c; i++) {
				if (n == arr[i]) {
					printf("duplicate");
					break;
				}
				else if (n < arr[i]) {
					c++;
					for (int j = c; j >= i + 1; j--) {
						arr[j] = arr[j - 1];
					}
					arr[i] = n;
					for (int i = 0; i < c; i++) {
						printf("%d ", arr[i]);
					}
					break;
				}
				else if (arr[i] == 0) {
					c++;
					arr[i] = n;
					for (int i = 0; i < c; i++) {
						printf("%d ", arr[i]);
					}
					break;
				}
			}
			
			
		}
	}
