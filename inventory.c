#include "inventory.h"
#include "numString.h"

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
  for(int n = 0; n < inv->itemNum; n++){
  	int fillerSize = 100 - strnlen(inv->items[n]->item,maxLen);
  	char *filler = malloc(fillerSize+1);
  	memset(filler, '.',fillerSize);
  	filler[fillerSize] = 0;
  	printf("[%i] %s %s %i\n", n, inv->items[n]->item, filler, inv->items[n]->num);
  }
}