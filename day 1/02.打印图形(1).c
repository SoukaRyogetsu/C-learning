//    *
//   * *
//  * * *
// * * * *
//* * * * *
// * * * *
//  * * *
//   * *
//    *
//
#include <stdio.h>
#include <math.h>
int main() {
	int N = 5;
	for (int i = 1; i <= 2 * N - 1; i++) {
		for (int j = 1; j <= abs(N - i); j++)
			printf(" ");
		for (int j = 1; j <= N - abs(N - i); j++) {
			printf("*");
			if (j != N - abs(N - i))
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
