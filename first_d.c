#include<stdio.h>
int main(){
    char str1[100],str2[100];
    printf("Enter first string: ");
    scanf("%s",str1);
    printf("Enter second string: ");
    scanf("%s",str2);
    char final[200];
    int i;
    for(i=0; str1[i]; i++){
        final[i] = str1[i];
    }
    for(int j=0; str2[j]; j++){
        final[i] = str2[j];
        i++;
    }
    final[i] = '\0';
    printf("Final string is: %s\n",final);
    return 0;
}