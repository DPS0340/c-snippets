#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void arr_init(int** arr, int size) {
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			arr[i][j] = rand() % 10;
		}
	}

	return;
}

void print_arr(int** arr, int size) {
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	srand(time(0));

	int size = 300;

	int** pa = (int**)malloc(sizeof(int*)*size);
	for(int i=0;i<size;i++) {
		*(pa + i) = (int*)malloc(sizeof(int)*size);
	}
	int** pb = (int**)malloc(sizeof(int*)*size);
	for(int i=0;i<size;i++) {
		*(pb + i) = (int*)malloc(sizeof(int)*size);
	}

	printf("array initialization process...\n\n");

	arr_init(pa, size);
	arr_init(pb, size);



	printf("cache hitting calculation start...\n");

	int sum = 0;

	clock_t begin = clock();

	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			sum += pa[i][j];
		}
	}

	clock_t end = clock();

	printf("result is: %d\n", sum);

	unsigned int millisecs = (unsigned int)((double)(end - begin) / CLOCKS_PER_SEC * 1000);

	printf("elapsed time: %ums\n", millisecs);

	printf("less cache hitting calculation start...\n");


	sum = 0;

	begin = clock();

	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			sum += pb[j][i];
		}
	}

	end = clock();

	printf("result is: %d\n", sum);

	millisecs = (unsigned int)((double)(end - begin) / CLOCKS_PER_SEC * 1000);

	printf("elapsed time: %ums\n", millisecs);


	for(int i=0;i<size;i++) {
		free(*(pa + i));
		free(*(pb + i));
	}

	free(pa);
	free(pb);

	return 0;
}


