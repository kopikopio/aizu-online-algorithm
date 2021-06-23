#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack {
    int buf[100];
    int last_index;
};

// スタック作成
Stack createStack() {
    Stack stack;
    stack.last_index = -1;
    return stack;
}

void push(Stack *stack, int val) {
    stack->buf[stack->last_index + 1] = val;
    stack->last_index++;
}
int pop(Stack *stack) {
    int val = stack->buf[stack->last_index];
    stack->buf[stack->last_index] = 0; // 無効な値を入力
    stack->last_index--;
    return val;
}

void printStack(Stack* stack) {
    if (stack->last_index == -1) {
        printf("スタックは空です\n"); // 空の場合
        return;
    }
    for(int i = 0; i <= stack->last_index - 1; i++) {
        printf("%d ", stack->buf[i]);
    }
    printf("%d\n", stack->buf[stack->last_index]);
}

int main() {

    Stack stack = createStack();

    // 入力値取得
    short maxInputSize = 7; // 最大が正の整数10の６乗
    char c[maxInputSize + 1];
    int i = 0;
    int result = 0;
    while(true) {
        char buf =  getchar();
        c[i] = buf;
        if (buf == ' ' || buf == '\n') {
            c[i] = '\0';
            int val;
            if((val = atoi(c)) > 0) push(&stack, val);
            else {
                int v2 = pop(&stack); // 後ろのオペランド
                int v1 = pop(&stack); // 前のオペランド
                if(strcmp(c, "+") == 0) {
                    result =  v1 + v2;
                    push(&stack, result);
                }
                else if(strcmp(c, "-") == 0) {
                    result =  v1 - v2;
                    push(&stack, result);
                }
                else {
                    result =  v1 * v2;
                    push(&stack, result);
                }
            }
            i = 0;
            if (buf == ' ') continue;
            if (buf == '\n') break;
        }
        i++;
    }
    printf("%d\n",result);
}

