#include <stdio.h>
#include <stdlib.h>

extern int data_sum(int *array, int count);

int main(void) {
    int array[60];
    int count, sum;
    char filename[256];
    FILE *data;

    printf("Enter filename: ");

    if (scanf("%255s", filename) != 1) {
        printf("Invalid filename.\n");
        return 1;
    }

    data = fopen(filename, "r");

    if (data == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    if (fscanf(data, "%d", &count) != 1 ||
        count < 0 || count > 60) {
        printf("Invalid count. Must be between 0 and 60.\n");
        fclose(data);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (fscanf(data, "%d", &array[i]) != 1) {
            printf("Invalid or missing integer.\n");
            fclose(data);
            return 1;
        }
    }

    sum = data_sum(array, count);
    printf("Sum = %d\n", sum);

    fclose(data);
    return 0;
}
