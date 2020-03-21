#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int strlen_(char* cp) {
	char* cursor = cp;
	int res = 0;
	while(*cursor != '\0') {
		cursor++;
		res++;
	}

	return res;
}

int main(void) {
	int size = 5000;

	char* line = (char*)malloc(sizeof(char)*size);
	for(int i=0;i<size-1;i++) {
		line[i] = 'a';
	}

	line[size-1] = '\0';


	clock_t begin = clock();

	int sum = 0;

	for(int i=0;i<strlen_(line);i++) {
		sum += i;
	}

	clock_t end = clock();

	unsigned int millisecs = (unsigned int)((double)(end - begin) / CLOCKS_PER_SEC * 1000);

	printf("elapsed time: %ums\n", millisecs);
	
	begin = clock();

	sum = 0;

	for(int i=0;i<size;i++) {
		sum += i;
	}

	end = clock();

	millisecs = (unsigned int)((double)(end - begin) / CLOCKS_PER_SEC * 1000);

	printf("elapsed time: %ums\n", millisecs);

	free(line);

	return 0;
}


