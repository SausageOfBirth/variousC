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
    if(is_vowel(object->item)){
      printf("an %s", object->item);
    }else{
      printf("a %s", object->item);
    }
  }else{
    printf("%s %ss", intToString(object->num), object->item);
  }
}

void printRoomInventory(RoomInven* inv){
  if(inv->itemNum == 0){
  	printf("Dude! This room is like, totally empty!\n");
  	return;
  }
  printf("In this room you see; ");
  for(int n = 0; n < inv->itemNum; n++){
    if(n == inv->itemNum-1){
      printf(" and");
      printObj(inv->items[n]);
    }else if(n != 0){
      printf(", ");
      printObj(inv->items[n]);
    }else{
      printObj(inv->items[n]);
    }
  }
  printf("\n");
}

void printRoom(Room* room){
  int doorNum = room->doors->num;
  char *border = malloc(83);
  memset(border, '_',82);
  border[82] = 0;
  char* upperBorder = concat(".",concat(border,"."));
  char* lowerBorder = concat("*",concat(border,"*"));
  printf("%s\n", upperBorder);
  printf("|Your steely gaze crawls across the room like a disgusting goblin.                 |\n");
  printf("|Of objects you see;                                                               |\n");
  for(int n = 0; n < room->stuff->itemNum; n++){
    char* name = room->stuff->items[n]->item;
    if(room->stuff->items[n]->num > 1){
      char* content = malloc(maxLen);
      sprintf(content, "|[%d]%s %ss", n, intToString(room->stuff->items[n]->num), name);
      int fillerSize = 83 - lenstr(content, maxLen);
      char* filler = malloc(fillerSize+1);
      memset(filler, '.', fillerSize);
      filler[fillerSize] = 0;
      printf("%s%s|\n", content, filler);
    }else{
      char* content = malloc(maxLen);
      sprintf(content, "|[%d] %s %s", n, is_vowel(name) ? "an" : "a", name);
      int fillerSize = 83 - lenstr(content, maxLen);
      char* filler = malloc(fillerSize+1);
      memset(filler, '.', fillerSize);
      filler[fillerSize] = 0;
      printf("%s%s|\n", content, filler);
    }
  }
  printf("|You find doors leading to;                                                        |\n");
  for(int n = 0; n < room->doors->num; n++){
    Room* nextDoor = (Room*)room->doors->exits[n]->leads;
    char* content = malloc(maxLen);
    sprintf(content, "|[%d] the %s", n+room->stuff->itemNum, nextDoor->name);
    int fillerSize = 83 - lenstr(content, maxLen);
    char* filler = malloc(fillerSize+1);
    memset(filler, '.', fillerSize);
    filler[fillerSize] = 0;
    printf("%s%s|\n", content, filler); 
  }
  printf("%s\n", lowerBorder);
}
