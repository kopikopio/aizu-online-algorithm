#include <stdio.h>

using namespace std;

struct Card {
    char pattern; // 絵柄
    int value; // 値
};

void printCard(Card* card, int N) {
    for (int i=0; i<N-1; i++) {
        printf("%c", card[i].pattern);
        printf("%d ", card[i].value);
    }
    printf("%c", card[N-1].pattern);
    printf("%d\n", card[N-1].value);
}

void change(Card* card, int i, int j) {
    char tmpP = card[i].pattern;
    int tmpV = card[i].value;

    // 絵柄交換
    card[i].pattern = card[j].pattern;
    card[j].pattern = tmpP;
    // 値交換
    card[i].value = card[j].value;
    card[j].value = tmpV;
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
    printCard(card, N);
    printf("%d\n", count);
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
    printCard(card, N);
    printf("%d\n", count);
}

int checkStable(Card before, Card after) {

}
int main() {
    int N, i, j;
    Card card[100];

    // 入力値取得
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        card[i].pattern = getchar();
        // 改行・空白文字を除去
        while( card[i].pattern == ' ' || card[i].pattern == '\n') {
            card[i].pattern = getchar();
        }
        scanf("%d", &card[i].value);
    }
    printCard(card, N);

    bublleSort(card, N);
}