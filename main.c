#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* numbers[32] = {" zero"," one"," two"," three"," four"," five"," six"," seven"," eight"," nine",
                     "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                     "eighteen","nineteen","twenty","thirty","fourty","fifty","sixty",
                     "seventy","eighty","ninety","hundred","thousand","million"," and "};

int maxLen = 1024;

char* concat(char* str1,char* str2){
  char* res = malloc((sizeof(char)*strnlen(str1,maxLen))+(strnlen(str2,maxLen) * sizeof(char)));
  memcpy(res,str1,sizeof(char) * strnlen(str1,maxLen));
  memcpy(res+strnlen(str1,maxLen)*sizeof(char),str2,sizeof(char)*strnlen(str2,maxLen));

  return res;
}

char* intToString(int num){
  char* res = "";
  char* tmp = "";
  if(num < 21){
    res = concat(res,numbers[num]);
  }else if(num < 100){
    if((num % ((num/10)*10)) != 0){
      res = concat((concat(res,numbers[(num/10)+18])),intToString(num-((num/10)*10)));
    }else{
      res = concat(res,numbers[(num/10)+18]);
    }
  }else if(num < 1000){
    if((num % ((num/100)*100)) != 0){
      tmp = concat(res,intToString((num/100)*100));
      tmp = concat(tmp, numbers[31]);
      res = concat(tmp,intToString(num-((num/100)*100)));
    }else{
      tmp = concat(res,numbers[(num/100)]);
      tmp = concat(tmp," ");
      res = concat(tmp,numbers[28]);
    }
  }else{
    if((num % ((num/1000)*1000)) != 0){
      tmp = concat(res,intToString((num/1000)*1000));
      res = concat(tmp,intToString(num-((num/1000)*1000)));
    }else{
      tmp = concat(res,intToString(num/1000));
      tmp = concat(tmp," ");
      res = concat(tmp,numbers[29]);
    }
  }

  return res;
}

int main(){
  printf("%s\n",intToString(120456));
  printf("%i\n",33 % 30);
  return 0;
}
