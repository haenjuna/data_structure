//test case all clear
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

int main() {
	char k,c;
	int check = 0;
	FILE* fp = fopen("sample.html", "r");
	FILE* fs = fopen("sample.txt", "w");
	fprintf(fs, "\n");
	while (!feof(fp)) {
		fscanf(fp, "%c", &c);
		if (c == '<') {
			check = 1;
		}
		if (c == '>') {
			check = 0;
		}
		if (check == 0 && c!='>') {
			fprintf(fs,"%c", c);
		}
	}
	fclose(fp);
	fclose(fs);
}