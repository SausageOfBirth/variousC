#include <stdio.h>

char* numbers[31] = {"one","two","three","four","five","six","seven","eight","nine","ten",
                     "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                     "eighteen","nineteen","twenty","thirty","fourty","fifty","sixty",
                     "seventy","eighty","ninety","hundred","thousand","million","and"};

char* intToString(int num){
  char* res = "";
  if(num < 10){
    char* resBuff = malloc(sizeof(char)*(sizeof(res)+sizeof(numbers[num])));
    for(int n = 0; n < sizeof(res)+sizeof(numbers[num]);n++){
      if(n < sizeof(res)){
        resBuff[n] = res[n];
      }else{
        resBuff[n] = numbers[num][n-sizeof(res)];
      }
    }
  }

  return res;
}

int main(){
  printf("%s\n",intToString(0));
  return 0;
}
