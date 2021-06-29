#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main(int argc, char *argv[]) {
    Array primes;
    int num, ITERATIONS;
    if(argc < 2) {
        printf("Number of iterations?\n");
        scanf("%d", &ITERATIONS);
        printf("\n");
    }else {
        ITERATIONS = atoi(argv[1]);
    }
    initArray(&primes, 10);
    insertArray(&primes, 2);
    insertArray(&primes, 3);
    printf("2\n3\n");

    for(num=4; num<ITERATIONS;num++) {   
        int i, isprime = 1;
        if ( num%6 == 1 || num%6 == 5)
        {
        for(i=0; primes.array[i]<=sqrt(num); i++) {
            if(num % primes.array[i] == 0) {
                isprime = 0;
                break;
            }
            if(primes.array[i] > num / 2)
                break;
        }
        }
        else
        {
            isprime = 0;
        }
        if(isprime == 1) {
            insertArray(&primes, num);
            printf("%d\n", num);
        }
    }

    freeArray(&primes);
    //system("pause");
    return 0;
}
