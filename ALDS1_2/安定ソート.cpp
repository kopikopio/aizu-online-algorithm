// ? 元々の配列を保持しておけばorderいらないかも

#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Card {
    char pattern; // 絵柄
    int value; // 値
    int order; // ? 安定確認用だがデータに組み込まないやり方の方がいい 0origin
};

void printCard(Card* card, int N) {
    for (int i=0; i<N-1; i++) { // ? 最後尾の要素の出力はループ外でおこなっているが、order追加した際それを忘れていて、N:2で実行しループ内に出力に追加したらうまく動いていないように見えた
        // printf("%d: ", card[i].order);
        printf("%c", card[i].pattern);
        printf("%d ", card[i].value);
    }
    // printf("%d: ", card[N-1].order);
    printf("%c", card[N-1].pattern);
    printf("%d\n", card[N-1].value);
}

void change(Card* card, int i, int j) {
    char tmpP = card[i].pattern;
    int tmpV = card[i].value;
    int tmpO = card[i].order;

    // 絵柄交換
    card[i].pattern = card[j].pattern;
    card[j].pattern = tmpP;
    // 値交換
    card[i].value = card[j].value;
    card[j].value = tmpV;
    // ? order交換
    card[i].order = card[j].order;
    card[j].order = tmpO;
}

// バブルソート
void bublleSort(Card* card, int N) {
    int flag = 1;
    int count = 0;
    while(flag) {
        flag = 0;
        for (int j=N-1; j>=1; j--) {
            if(card[j].value < card[j-1].value) {
                change(card, j, j - 1);
                flag = 1;
                count++;
            }
        }
    }
    // 整列された配列
    // printCard(card, N);
    // printf("%d\n", count);
}

// 選択ソート
void selectingSort(Card* card, int N) {
    
    int count = 0;
    for(int i=0; i<=N-2; i++) {
        int minj = i;
        for(int j=i; j<=N-1; j++) {
            if(card[minj].value > card[j].value) {
                minj = j;
            }
        }
        change(card, i, minj);
        if (i != minj) count++;
    }
    // 整列された配列
    // printCard(card, N);
    // printf("%d\n", count);
}

int isStable(Card* afters, int N) {
    for (int i = 0; i <= N - 2; i++) {
        if (afters[i].value == afters[i+1].value && afters[i].order > afters[i+1].order) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N, i, j;
    Card cards[100];
    Card cards2[100];

    // 入力値取得
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        cards[i].order = i;
        cards[i].pattern = getchar();
        // 改行・空白文字を除去
        while( cards[i].pattern == ' ' || cards[i].pattern == '\n') {
            cards[i].pattern = getchar();
        }
        scanf("%d", &cards[i].value);
    }

    // 選択ソート用に配列をコピー
    for (int i=0; i<N; i++) {
        cards2[i].order = cards[i].order;
        cards2[i].pattern = cards[i].pattern;
        cards2[i].value = cards[i].value;
    }

    // バブルソート 
    bublleSort(cards, N);
    printCard(cards, N);
    if (isStable(cards, N) == 1) printf("Stable\n");
    else printf("Not stable\n");
    // 選択ソート
    selectingSort(cards2, N);
    printCard(cards2, N);
    if (isStable(cards2, N) == 1) printf("Stable\n");
    else printf("Not stable\n");
}