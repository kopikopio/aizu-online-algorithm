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
        // 変数初期化
        int start_index = 0;
        int end_index = n - 1;
        int left_num = (end_index - (start_index - 1)) / 2;
        int bound_index = start_index - 1 + left_num;
        // データが2つ以上ある間は2つに分けていく
        while(start_index != end_index){
            if (T[i] <= S[bound_index]) {
                // start ~ bound_index で探索
                end_index = bound_index;
                left_num = (end_index - (start_index - 1)) / 2;
                bound_index = start_index - 1 + left_num;
            } else {
                // bound_index + 1 ~ end_index で探索
                start_index = bound_index + 1;
                left_num = (end_index - (start_index - 1)) / 2;
                bound_index = start_index - 1 + left_num;
            }
        }
        // データ数が１つになった時、データが一致すれば「見つかった」となる
        if (T[i] == S[start_index]) count++;

        // 計算量は固定でnlognになる
    }
    printf("%d\n", count); 
}