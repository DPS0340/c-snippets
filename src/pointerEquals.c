#include <stdio.h>

int main(void) {
	int a = 5;
	int* pa = &a;

	if(&*pa == &a) {
		printf("EQUALS");
	} else {
		printf("NOT EQUALS");
	}

	return 0;
}
