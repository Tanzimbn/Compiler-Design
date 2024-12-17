#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE* rd;
    FILE* wt;
    rd = fopen("input.txt", "r");
    wt = fopen("output.txt", "w");

    char ch[200005], temp[20005];
    while(fgets(temp, 20000, rd)) {
        strcat(ch, temp);
        strcat(ch, " ");
    }

    int i = 0;
    while(i < strlen(ch)) {
        int yes = 0;
        while(i < strlen(ch)) {
            if(isspace(ch[i])) break;
            fprintf(wt, "%c", ch[i]);
            yes = 1;
            i++;
        }
        i++;
        if(yes) fprintf(wt, "\n");
    }
    fclose(rd);
    fclose(wt);
}
