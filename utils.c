#include "utils.h"

int maxLen = 1024;
char* vowels = "aeiouy";
char* numbers[32] = {" zero"," one"," two"," three"," four"," five"," six"," seven"," eight"," nine",
                     "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                     "eighteen","nineteen"," twenty"," thirty"," fourty"," fifty"," sixty",
                     " seventy"," eighty"," ninety"," hundred"," thousand"," million"," and"};

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
      res = concat(tmp,numbers[28]);
    }
  }else if(num < 1000000){
    if((num % ((num/1000)*1000)) != 0){
      tmp = concat(res,intToString((num/1000)*1000));
      res = concat(tmp,intToString(num-((num/1000)*1000)));
    }else{
      tmp = concat(res,intToString(num/1000));
      res = concat(tmp,numbers[29]);
    }
  }else{
    if((num % ((num/1000000)*1000000)) != 0){
      tmp = concat(res,intToString((num/1000000)*1000000));
      res = concat(tmp,intToString(num-((num/1000000)*1000000)));
    }else{
      tmp = concat(res,intToString(num/1000000));
      res = concat(tmp,numbers[30]);
    }
  }
  return res;
}

int in_str(char* n, char* target){
  int n_len = lenstr(n, maxLen);
  int target_len = lenstr(target, maxLen);
  for(int i = 0; i < n_len; i++){
    char* buf = malloc(target_len+1);
    memcpy(buf, n + i, target_len);
    buf[target_len] = 0;
    if(equals(buf, target)){
      free(buf);
      return 1;
    }
    free(buf);
  }
  return 0;
}

int equals(char* a, char* b){
  int a_len = lenstr(a, maxLen);
  if(a_len != lenstr(b, maxLen)){
    return 0;
  }
  for(int n = 0; n < a_len; n++){
    if(a[n] != b[n]){
      return 0;
    }
  }
  return 1;
}

char* concat(char* str1,char* str2){
  char* res = malloc((lenstr(str1,maxLen) * sizeof(char))+(lenstr(str2,maxLen) * sizeof(char)));
  memcpy(res,str1,lenstr(str1,maxLen));
  memcpy(res+lenstr(str1,maxLen),str2,lenstr(str2,maxLen));
  res[(lenstr(str1,maxLen)+lenstr(str2,maxLen))] = 0;

  return res;
}

int lenstr(char* str, int max){
  int count = 0;
  while(count < max){
    if(str[count] == 0){
      return count;
    }
    count ++;
  }
  return count;
}

int is_vowel(char* n){
  if(lenstr(n, maxLen) > 2){
    if(n[0] == 'h' || n[0] == 'H'){
      if(n[1] == 'o' && n[2] == 'u'){
        return 1;
      }
    }
  }
  for(int i = 0; i < lenstr(vowels, maxLen); i++){
    if(n[0] == vowels[i]){
      return 1;
    }
  }
  return 0;
}
