#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct room;

typedef struct{
  int num;
  int pick_up;
  char* item;
} RoomObj;

typedef struct{
  int itemNum;
  RoomObj** items;
} RoomInven;

typedef struct{
  int passable;
  struct room* leads;
} Door;

typedef struct{
  char* name;
  Door** exits;
  RoomInven* stuff;
} Room;

void removeRoomItem(RoomInven** inv, int index, int amount);
void addRoomItem(RoomInven** inv, RoomObj* object);
void printRoomInventory(RoomInven* inv);
