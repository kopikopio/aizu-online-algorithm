#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* A;
int n;


void printA(int num) {
    for (int i = 0; i < num-1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[num-1]);
}

void rec(int i) {
    if(i >= n) {
        printA(n);
        return;
    }
    A[i] = 0;
    rec(i + 1);
    A[i] = 1;
    rec(i + 1);
}

int main() {

    // A入力
    // int n;
    scanf("%d", &n);
    A = new int[n];
    // int A[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    rec(0);
    // // M入力
    // int q;
    // scanf("%d", &q);
    // int M[q];
    // for (int i=0; i<q; i++) {
    //     scanf("%d", &M[i]);
    // }

 
 
}