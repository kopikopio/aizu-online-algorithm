// 仮実装
// 文字のパターン数 22369620
// 4(1-4^12)/(1-4)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10;

int getKey(char* str) {

    int sum = 0;
    int weight = 1;
    while(*str != '\0') {
        // A~Dによる値
        int num;
        if (*str == 'A') num = 1;
        else if (*str == 'C') num = 2;
        else if (*str == 'G') num = 3;
        else num = 4;
        // 
        sum += num * weight;
        // 
        str++;
        weight *= 4;
    }
    return sum;
}

int main() {


    bool* dictinary = new bool[22369620];
    // 入力
    int n;
    scanf("%d", &n);
    char op[7];
    char str[13];
    for (int i=0; i<n; i++) {
        scanf("%s %s", op, str);

        if (op[0] == 'i') dictinary[getKey(str)] = true;
        else {
            if (dictinary[getKey(str)] == true) printf("yes\n");
            else printf("no\n");
        }
    }
}