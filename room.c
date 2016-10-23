#include "room.h"

void removeRoomItem(RoomInven** inv, int index, int amount){
  if((*inv)->itemNum == 0){
  	printf("Dude! This room is like, totally empty!\n");
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

void addRoomItem(RoomInven** inv, RoomObj* object){
  for(int n = 0; n < (*inv)->itemNum; n++){
  	if((*inv)->items[n]->item == object->item){
  	  (*inv)->items[n]->num += object->num;
  	  return;
  	}
  }
  RoomObj** newRoomInvenory = malloc(sizeof(RoomObj) * ((*inv)->itemNum+1));
  memcpy(newRoomInvenory,(*inv)->items,(*inv)->itemNum);
  newRoomInvenory[(*inv)->itemNum] = object;
  (*inv)->items = newRoomInvenory;
  (*inv)->itemNum ++;
}

void printObj(RoomObj* object){
  if(object->num == 1){
    if(is_vowel(object->item[0])){
      printf("an %s", object->item);
    }else{
      printf("a %s", object->item);
    }
  }else{
    printf("%s %ss", intToString(object->num), object->item);
  }
}

void printRoomInvenory(RoomInven* inv){
  if(inv->itemNum == 0){
  	printf("Dude! This room is like, totally empty!\n");
  	return;
  }
  printf("In this room you see ");
  for(int n = 0; n < inv->itemNum; n++){
    if(n == inv->itemNum-1){
      printf(" and ");
      printObj(inv->items[n]);
    }else{
      printf(", ");
      printObj(inv->items[n]);
    }
  }
} 
