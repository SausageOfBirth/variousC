#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct room;

typedef struct RoomObj{
  int num;
  int pick_up;
  char* item;
} RoomObj;

typedef struct RoomInven{
  int itemNum;
  RoomObj** items;
} RoomInven;

typedef struct Door{
  int passable;
  struct room* leads;
} Door;

typedef struct Doors{
  int num;
  Door** exits;
} Doors;

typedef struct Room{
  char* name;
  Doors* doors;
  RoomInven* stuff;
} Room;

void removeRoomItem(RoomInven** inv, int index, int amount);
void addRoomItem(RoomInven** inv, RoomObj* object);
void printRoomInventory(RoomInven* inv);
void printRoom(Room* room);
