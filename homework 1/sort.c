#include <stdio.h>
#include "stdlib.h"

#define HIGH 8
typedef int * numbers; //creates an array of ints
numbers a;

void readarray(void) {
        int i;

        for (i = 0; i < HIGH; i++) {
                scanf("%d", &a[i]); //stores the int in the numbers array
        }
}

void writearray(void) {
        int i;

        for (i = 0; i < HIGH; i++) {
                printf("%d", a[i]); //prints everything in the array
        }
        printf("\n");
}

void exchange(int * b, int * c) {
        int t;

        t = *b;

        *b = *c;

        *c = t;
}

int partition(numbers a, int y, int z){
        int i, j, k;

        k = a[y];

        i = y;

        j = z;

        while (i < j){
                while (a[j] > k)
                        --j;
                while (a[i] < k)
                        ++i;
                if (i < j)
                        exchange(&a[i], &a[j]); //uses the exchange function to swap the elements
        }
        return j;
}

void quicksort(numbers a, int m, int n) {
        int i;

        if (n > m) {
                i = partition(a, m, n);

                quicksort(a, m, i);
                quicksort(a, i+1, n);
        }
}

int main() {
        a = malloc(sizeof(int) * HIGH);

        readarray();
        quicksort(a, 0, HIGH-1);
        writearray();
        free(a);

        return 0;
}