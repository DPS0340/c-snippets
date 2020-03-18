#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_int_from_file(const char*);

int main(void) {
    int seed = get_int_from_file("seed");

    printf("seed 값: %d\n", seed);

    if(seed < 0) {
        printf("seed는 음수가 될 수 없음\n");
        return 1;
    }

    srand((unsigned int) seed);

    for(int i = 0; i < 12; i++) {
      printf("%d ", rand());
      if(i % 3 == 2) {
          printf("\n");
      }
    }

    return 0;
}

int get_int_from_file(const char* src) {
    FILE* fp = fopen(src, "r");

    if(fp == NULL) {
        printf("fopen 실패\n");
        exit(1);
    }

    int res;

    fscanf(fp, "%d", &res);

    fclose(fp);

    return res;
}
