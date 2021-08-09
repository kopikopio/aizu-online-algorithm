#include <stdio.h>

using namespace std;

void printA(int* A, int N) {
    for (int i=0; i<N-1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
}


void change(int* A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void selectingSort(int* A, int N) {
    
    int count = 0;
    for(int i=0; i<=N-2; i++) {
        int minj = i;
        for(int j=i; j<=N-1; j++) {
            if(A[minj] > A[j]) {
                minj = j;
            }
        }
        change(A, i, minj);
        if (i != minj) count++;
    }
    // 整列された配列
    printA(A, N);
    printf("%d\n", count);
}


int main() {
    int N, i, j;
    int A[100];

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);

    selectingSort(A, N);
}