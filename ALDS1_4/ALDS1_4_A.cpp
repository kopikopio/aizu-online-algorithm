#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // S入力
    int n;
    scanf("%d", &n);
    int S[n];
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

    // 検索
    int count = 0;
    for (int i=0; i<q; i++) {
        for (int j=0; j<n; j++) {
            if (T[i] == S[j]) {
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);    
}