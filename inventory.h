#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int num;
  char* item;
} Obj;

typedef struct{
  int itemNum;
  Obj** items;
} Invent;

void printInventory(Invent* inv);
void removeItem(Invent** inv, int index, int amount);
void addItem(Invent** inv, Obj* object);