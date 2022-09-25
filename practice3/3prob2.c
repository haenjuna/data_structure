//test case all clear
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int main() {
    int n, array1[MAX], array2[MAX], temp, temp1;

    scanf("%d", &n); // 입력받을 개수
    for (int i = 0; i < n; i++) {
        scanf("%d", &array1[i]); // 시작점
        scanf("%d", &array2[i]); // 끝점
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array1[j] > array1[j + 1]) {

                temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;

                temp1 = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = temp1;
            }
            else if (array1[j] == array1[j + 1]) {
                if (array2[j] > array2[j + 1]) {

                    temp1 = array2[j];
                    array2[j] = array2[j + 1];
                    array2[j + 1] = temp1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array1[i]);
        printf("%d\n", array2[i]);
    }
}