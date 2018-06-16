//   * *       * *
//  * * *     * * *
// * * * *   * * * *
//* * * * * * * * * *
// * * * * * * * * *
//  * * * * * * * *
//   * * * * * * *
//    * * * * * *
//     * * * * *
//      * * * *
//       * * *
//        * *
//         *
#include <stdio.h>
int main() {
	int N = 10; //用于改变大小
	for (int i = 2; i<N / 2; i++) {
		for (int j = 0; j<N / 2 - i; j++)
			printf(" ");
		for (int j = 1; j <= i; j++) {
			printf("*");
			if (j != i)
				printf(" ");
		}
		for (int j = 1; j <= 2 * (N / 2 - i) + 1; j++)
			printf(" ");
		for (int j = 1; j <= i; j++) {
			printf("*");
			if (j != i)
				printf(" ");
		}
		printf("\n");
	}
	for (int i = N; i>0; i--) {
		for (int j = 0; j<N - i; j++)
			printf(" ");
		for (int j = 1; j <= i; j++) {
			printf("*");
			if (j != i)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

