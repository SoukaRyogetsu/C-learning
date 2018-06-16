//    *
//   * *
//  *   *
// *     *
//*       *
// *     *
//  *   *
//   * *
//    *
#include <stdio.h>
#include <math.h>
int main() {
	int N = 5;
	for (int i = 1; i <= 2 * N - 1; i++) {
		for (int j = 1; j <= abs(N - i); j++)
			printf(" ");
		printf("*");
		for (int j = 1; j <= 2 * (N - abs(N - i) - 1) - 1; j++)
			printf(" ");
		if (abs(N - i) != N - 1)
			printf("*");
		printf("\n");
	}
	return 0;
}
