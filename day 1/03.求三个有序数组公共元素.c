#include <stdio.h>
//纯暴力求解
void comElem(int arr1[], int arr2[], int arr3[], int len1, int len2, int len3) {
	for (int a1 = 0, a2 = 0, a3 = 0; a1<len1&&a2<len2&&a3<len3;) {
		if (arr1[a1]<arr2[a2]) {
			a1++;
			if (arr2[a2]<arr3[a3]) a2++;
			else if (arr2[a2]>arr3[a3])a3++;
		}
		else if (arr1[a1]>arr2[a2]) {
			a2++;
			if (arr1[a1]<arr3[a3]) a1++;
			else if (arr1[a1]>arr3[a3])a3++;
		}
		else {
			if (arr1[a1]<arr3[a3]) { a1++; a2++; }
			else if (arr1[a1]>arr3[a3]) a3++;
			printf("%d ", arr1[a1]);
			a1++; a2++; a3++;
		}
	}
}
int main() {
	int arr1[]={ 1,2,3,4,5,6,7,8,9 };
	int arr2[]={ 2,4,6,7,9,11 };
	int arr3[]={ 1,2,5,7,8,9,11 };
	int lena = sizeof(arr1) / sizeof(int);
	int lenb = sizeof(arr2) / sizeof(int);
	int lenc = sizeof(arr3) / sizeof(int);
	comElem(arr1, arr2, arr3, lena, lenb, lenc);
	return 0;
}
