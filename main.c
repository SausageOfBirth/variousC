#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* numbers[31] = {"one","two","three","four","five","six","seven","eight","nine","ten",
                     "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                     "eighteen","nineteen","twenty","thirty","fourty","fifty","sixty",
                     "seventy","eighty","ninety","hundred","thousand","million","and"};

char* concat(char* str1,char* str2){
  char* res = malloc((sizeof(char)*strnlen(str1,32))+(strnlen(str2,32) * sizeof(char)));
  memcpy(res,str1,sizeof(char) * strnlen(str1,32));
  memcpy(res+strnlen(str1,32)*sizeof(char),str2,sizeof(char)*strnlen(str2,32));

  return res;
}

char* intToString(int num){
  char* res = "";
  if(num < 10){
    res = concat(res,numbers[num]);
  }

  return res;
}

int main(){
  printf("%s\n",intToString(0));
  return 0;
}
