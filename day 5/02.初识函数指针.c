#include <stdio.h>
#include <string.h>
//函数指针，传递一种行为，面向接口编程
void b() {
	printf("I am func b\n");
}
void a(void(*p)()) {
	p();
}
int main() {
	void(*p)();
	p = b;
	p(); //等价于(*p)();
	a(b);
	return 0;
}
