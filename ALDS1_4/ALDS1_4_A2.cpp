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

    int q;
    scanf("%d", &q);

    // Tの配列を作らず、１件１件読み込みごとに検索する
    int count = 0;
    int tmp;
    for (int i=0; i<q; i++) {
        scanf("%d", &tmp);
        for (int j=0; j<n; j++) {
            if (tmp == S[j]) {
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);    
}