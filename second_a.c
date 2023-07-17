#include<stdio.h>
char sub[100];
void generate(int k,int index){
    if(index==k){
        sub[index] = '\0';
        printf("%s\n",sub);
        return;
    }
    sub[index] = '0';
    generate(k,index+1);
    sub[index] = '1';
    generate(k,index+1);
    return;
}
int main(){
    int k; 
    printf("Enter the value of k: ");
    scanf("%d",&k);
    generate(k,0);
    return 0;
}