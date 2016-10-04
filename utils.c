#include "utils.h"

int maxLen = 1024;

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
