#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(0));
    char alphabets[2]={'0','1'};
    char str[5][100];
    for(int i=0; i<5; i++){
        int length = rand()%20;
        for(int j=0; j<length; j++){
            int index = rand()%2;
            str[i][j] = alphabets[index];
        }
        str[i][length] = '\0';
        int count = 0;
        for(int j=0; str[i][j]!='\0'; j++){
            count++;
        }
        printf("Length of %s string is: %d\n",str[i],count);
    }
    return 0;
}