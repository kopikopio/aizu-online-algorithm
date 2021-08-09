#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // S入力
    int n;
    scanf("%d", &n);
    int S[n+1];
    for (int i=0; i<n; i++) {
        scanf("%d", &S[i]);
    }
    // T入力
    int q;
    scanf("%d", &q);
    int T[q];
    for (int i=0; i<q; i++) {
        scanf("%d", &T[i]);
    }

    // 検索(番兵)
    int count = 0;
    int key;
    int index;
    for (int i=0; i<q; i++) {
        index = 0;
        S[n] = T[i];
        while(S[index] != T[i]) {
            index++;
        }
        if(index != n) count++;
    }
    printf("%d\n", count);    
}