#include <stdio.h>
#include <string.h>
void move(char x, char y) {
	printf("%c-->%c\n", x, y);
}
//将n个盘从one座借助two座，移到three座
void hanoi(int n, char one, char two, char three) {
	//只有一个盘子时，可以直接从one座移到three作，实现了“借助”two座移动到three座
  if (n == 1) {  
		move(one, three);
		return;
	}
	hanoi(n - 1, one, three, two);
	move(one, three);
	hanoi(n - 1, two, one, three);
}
int main() {
	hanoi(3, 'A', 'B', 'C');
	return 0;
}
