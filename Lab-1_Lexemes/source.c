#include<stdio.h>
#include<stdlib.h>

int main() {
    char ch[200005], temp[20005];
    while(gets(temp)) {
        strcat(ch, temp);
        strcat(ch, " ");
    }

    printf("Print Lexemes:\n");
    int i = 0;
    while(i < strlen(ch)) {
        int yes = 0;
        while(i < strlen(ch)) {
            if(isspace(ch[i])) break;
            printf("%c", ch[i]);
            yes = 1;
            i++;
        }
        i++;
        if(yes) printf("\n");
    }
}
