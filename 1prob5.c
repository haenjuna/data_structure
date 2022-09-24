//테스트 케이스 모두 통과
#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int c = 0;
	int s;
	int arr[101] = { 0, };
	for(int k=0;k<n;k++) {
		scanf_s("%d", &s);
		for (int i = 0; i <= c; i++) {
			if (s == arr[i]) {
				break;
			}
			else if (s < arr[i]) {
				c++;
				for (int j = c; j >= i + 1; j--) {
					arr[j] = arr[j - 1];
				}
				arr[i] = s;
				break;
			}
			else if (arr[i] == 0) {
				c++;
				arr[i] = s;
				break;
			}
		}
	}
	printf("%d:", c);
	for (int i = 0; i < c; i++) {
		printf(" %d", arr[i]);
	}
}
