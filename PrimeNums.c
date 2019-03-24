#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int used;
    int size;
} Array;

void initArray(Array *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

int main() {
    Array primes;
    int num, ITERATIONS;
    printf("Number of iterations?\n");
    scanf("%d", &ITERATIONS);
    printf("\n");

    initArray(&primes, 10);
    insertArray(&primes, 2);

    for(num=3; num<ITERATIONS;num++) {   
        int i, isprime = 1;
        for(i=0; i<primes.used; i++) {
            if(num % primes.array[i] == 0) {
                isprime = 0;
                break;
            }
        }
        if(isprime == 1) {
            insertArray(&primes, num);
            printf("%d\n", num);
        }
    }

    freeArray(&primes);
    system("pause");
    return 0;
}