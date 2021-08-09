#include <stdio.h>

using namespace std;

void printA(int* A, int N) {
    for (int i=0; i<N-1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);

}

void insertionSort(int* A, int N) {
    for (int i=1; i <= N-1; i++) {
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        printA(A, N);
    }
}

int main() {
    int N, i, j;
    int A[100];

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    printA(A, N);

    insertionSort(A, N);
}