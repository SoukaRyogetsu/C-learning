#include<stdio.h>
#include<stdlib.h>
int main() {
	char a;
	while (scanf("%c", &a) != EOF) {
		if (a>'z' || a<'a') continue;
		a -= 32;
		printf("%c", a);
	}
	return 0;
}
