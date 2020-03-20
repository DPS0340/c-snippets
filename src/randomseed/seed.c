#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_int(const char*);

int file_write_int(int, const char*, const char*);

int main(void) {
    int write_val = get_int("주입할 랜덤 시드를 입력해 주세요.\n");

    int res = file_write_int(write_val, "seed", "w");

    if(res) {
        printf("주입 완료!\n");
    } else {
        printf("주입 실패!\n");
    }

    return 0;
}

int get_int(const char* line) {
    int res;

    if(line != NULL) {
        printf("%s", line);
    }

    scanf("%d", &res);

    return res;
}

int file_write_int(int value, const char* dest, const char* _mode) {
    char mode[20];

    if(_mode != NULL) {
        strcpy(mode, _mode);
    } else {
        strcpy(mode, "w+");
    }

    if(dest == NULL) {
        return 0;
    }

    FILE* fp = fopen(dest, mode);

    if(fp == NULL) {
        printf("fopen 실패\n");
        exit(1);
    }

    fprintf(fp, "%d", value);

    fclose(fp);

    return 1;
}

