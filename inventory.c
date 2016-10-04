#include "inventory.h"

void removeItem(Invent** inv, int index, int amount){
  if((*inv)->itemNum == 0){
  	printf("Dude! You're like, totally out of stuff, gnarly!\n");
  	return;
  }else if((*inv)->items[index]->num > amount){
  	(*inv)->items[index]->num -= amount;
  	return;
  }

  for(int n = index; n < ((*inv)->itemNum-1); n++){
    (*inv)->items[n] = (*inv)->items[n+1];
  }
  (*inv)->itemNum --;
}

void addItem(Invent** inv, Obj* object){
  for(int n = 0; n < (*inv)->itemNum; n++){
  	if((*inv)->items[n]->item == object->item){
  	  (*inv)->items[n]->num += object->num;
  	  return;
  	}
  }
  Obj** newInventory = malloc(sizeof(Obj) * ((*inv)->itemNum+1));
  memcpy(newInventory,(*inv)->items,(*inv)->itemNum);
  newInventory[(*inv)->itemNum] = object;
  (*inv)->items = newInventory;
  (*inv)->itemNum ++;
}

void printInventory(Invent* inv){
  if(inv->itemNum == 0){
  	printf("Dude! You're like, totally out of stuff, gnarly!\n");
  	return;
  }
  char *border = malloc(108);
  memset(border, '_',107);
  border[107] = 0;

  char* upperBorder = concat(".",concat(border,"."));

  char* lowerBorder = concat("*",concat(border,"*"));

  printf("%s\n", upperBorder);
  for(int n = 0; n < inv->itemNum; n++){
  	int fillerSize = 100 - lenstr(inv->items[n]->item,maxLen);
  	char *filler = malloc(fillerSize+1);
  	memset(filler, '.',fillerSize);
  	filler[fillerSize] = 0;
  	printf("|[%i] %s %s %i|\n", n, inv->items[n]->item, filler, inv->items[n]->num);
  }
  printf("%s\n", lowerBorder);

  free(upperBorder);
  free(lowerBorder);
  free(border);
}
