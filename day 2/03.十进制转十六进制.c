#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int ntc(int n) {
	if (n >= 0 && n <= 9) return n + '0';
	else return n - 10 + 'a';
}
char* dth(int n, char s[]) {
	int i = 0;
	while (n != 0) {
		int r = n % 16;
		s[i++] = ntc(r);
		n /= 16;
	}
	s[i] = '\0';
	for (int j = 0; j< i / 2; j++) {
		char t = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = t;
	}
	return s;
}
int main() {
	int num;
	char s[33];
	while (scanf("%d", &num) != EOF)
		printf("%s\n", dth(num, s));
	return 0;
}
