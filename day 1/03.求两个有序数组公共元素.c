#include <stdio.h>
void comElem(int arr1[], int arr2[], int len1, int len2) {
	for (int a1 = 0, a2 = 0; a1 < len1&&a2 < len2;) {
		if (arr1[a1] < arr2[a2]) a1++;
		else if (arr1[a1] > arr2[a2]) a2++;
		else {
			printf("%d ", arr1[a1]);
			a1++; a2++;
		}
	}
}
int main() {
	int arr1[]={ 1,2,3,4,5,6,7,8,9 };
	int arr2[]={ 2,4,6,7,9,11 };
	int lena = sizeof(arr1) / sizeof(int);
	int lenb = sizeof(arr2) / sizeof(int);
	comElem(arr1, arr2, lena, lenb);
	return 0;
}
