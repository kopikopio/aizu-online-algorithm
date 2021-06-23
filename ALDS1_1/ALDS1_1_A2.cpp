#include <stdio.h>

using namespace std;

void printA(int* A, int N) {
    for (int i=0; i<N-1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);

}

void insertionSort(int* A, int N) {
    for(int i=1; i<=N-1; i++) {
        int v = A[i];
        int insertIndex = 0;
        for(int j=i-1; j>=0; j--) {
            if(A[j] < A[i]) {
                // 見つかった!!
                insertIndex = j + 1;
                break;
            }
        }
        
        // 挿入
        for(int l = i; l>=insertIndex+1; l--) {
            A[l] = A[l-1];
        }
        A[insertIndex] = v;
        // 出力
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