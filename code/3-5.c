#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    int num;
    char buffer[256];

    while (1) {
        if (fscanf(fp, "%d", &num) == 1) {
            sum += num;
        } else {
            if (fscanf(fp, "%255s", buffer) == EOF) {
                break;
            }
            fprintf(stderr, "invalid input %s\n", buffer);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
