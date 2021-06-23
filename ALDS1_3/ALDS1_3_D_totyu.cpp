#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000



int main() {

    char ground;


    int height = 0; // 深さ
    char water[20000];
    int index = 0;
    // while(scanf("%c", &ground)) {
    while(scanf("%c", &ground)) {
        if (ground == '\\') {
            water[index] = '\\';
            height += 1;
            index++;
        }
        if (ground == '/') {
            water[index] = '/';
            height -= 1;
            index++;
        }
        if (ground == '_'){
            water[index] = '_';
            index++;
        }
        if (ground == '\n') {
            water[index] = '\0';
            printf("%s\n", water);
            break;
        }
        if (height == 0) {
            water[index] = '\0';
            index = 0;
            printf("%s\n", water);
        }
        else if (height < 0) {
            index = 0;
            height = 0;
            printf("reset\n");
        }
    }
    
}