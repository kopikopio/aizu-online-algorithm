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

void bublleSort(int* A, int N) {
    int flag = 1;
    int count = 0;
    while(flag) {
        flag = 0;
        for (int j=N-1; j>=1; j--) {
            if(A[j] < A[j-1]) {
                change(A, j, j - 1);
                flag = 1;
                count++;
            }
        }
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

    bublleSort(A, N);
}