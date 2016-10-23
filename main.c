#include "inventory.h"
#include "room.h"

int main(){

  Obj* myObject1 = (Obj*)malloc(sizeof(Obj));
  myObject1->num = 6;
  myObject1->item = "Pair of cool sunglasses";

  Obj* myObject2 = (Obj*)malloc(sizeof(Obj));
  myObject2->num = 1;
  myObject2->item = "Pretty radical new kicks";

  Invent* myInventory = (Invent*)malloc(sizeof(Invent));
  myInventory->itemNum = 2;
  Obj** myObjectArray = malloc(sizeof(Obj)*2);
  myObjectArray[0] = myObject1;
  myObjectArray[1] = myObject2;
  myInventory->items = myObjectArray;

  printInventory(myInventory);

  Obj* myObject3 = (Obj*)malloc(sizeof(Obj));
  myObject3->num = 2;
  myObject3->item = "Pair of cool sunglasses";
  addItem(&myInventory, myObject3);

  printInventory(myInventory);

  removeItem(&myInventory, 0, 5);

  printInventory(myInventory);

  removeItem(&myInventory, 0, 3);

  printInventory(myInventory);

  RoomObj* myRoomObject1 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject1->num = 1;
  myRoomObject1->item = "Pair of cool sunglasses";
  myRoomObject1->pick_up = 0;

  RoomObj* myRoomObject2 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject2->num = 1;
  myRoomObject2->item = "Hourly ringing grandfather clock";
  myRoomObject2->pick_up = 1;

  RoomObj* myRoomObject3 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject3->num = 3;
  myRoomObject3->item = "Absinthe bottle";  
  myRoomObject3->pick_up = 1;

  RoomInven* myRoomInventory1 = (RoomInven*)malloc(sizeof(RoomInven));
  myRoomInventory1->itemNum = 3;
  RoomObj** myRoomObjectArray1 = malloc(sizeof(RoomObj)*3);
  myRoomObjectArray1[0] = myRoomObject1;
  myRoomObjectArray1[1] = myRoomObject2;
  myRoomObjectArray1[2] = myRoomObject3;
  myRoomInventory1->items = myRoomObjectArray1;

  RoomObj* myRoomObject4 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject4->num = 8765;
  myRoomObject4->item = "Ball";
  myRoomObject4->pick_up = 1;

  RoomObj* myRoomObject5 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject5->num = 1;
  myRoomObject5->item = "Thoroughly used Ronald McDonald blowup doll";
  myRoomObject5->pick_up = 1;

  RoomObj* myRoomObject6 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject6->num = 5;
  myRoomObject6->item = "Finger";
  myRoomObject6->pick_up = 1;

  RoomInven* myRoomInventory2 = (RoomInven*)malloc(sizeof(RoomInven));
  myRoomInventory2->itemNum = 3;
  RoomObj** myRoomObjectArray2 = malloc(sizeof(RoomObj)*3);
  myRoomObjectArray2[0] = myRoomObject4;
  myRoomObjectArray2[1] = myRoomObject5;
  myRoomObjectArray2[2] = myRoomObject6;
  myRoomInventory2->items = myRoomObjectArray2;

  RoomObj* myRoomObject7 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject7->num = 1;
  myRoomObject7->item = "Large cheap rug";
  myRoomObject7->pick_up = 0;

  RoomObj* myRoomObject8 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject8->num = 1;
  myRoomObject8->item = "Orange bit of something on the wall";
  myRoomObject8->pick_up = 1;

  RoomObj* myRoomObject9 = (RoomObj*)malloc(sizeof(RoomObj));
  myRoomObject9->num = 3;
  myRoomObject9->item = "Boot";
  myRoomObject9->pick_up = 1;

  RoomInven* myRoomInventory3 = (RoomInven*)malloc(sizeof(RoomInven));
  myRoomInventory3->itemNum = 3;
  RoomObj** myRoomObjectArray3 = malloc(sizeof(RoomObj)*3);
  myRoomObjectArray3[0] = myRoomObject7;
  myRoomObjectArray3[1] = myRoomObject8;
  myRoomObjectArray3[2] = myRoomObject9;
  myRoomInventory3->items = myRoomObjectArray3;

  Doors* doors1 = (Doors*)malloc(sizeof(Doors));
  Doors* doors2 = (Doors*)malloc(sizeof(Doors));
  Doors* doors3 = (Doors*)malloc(sizeof(Doors));

  Door* r1Door = (Door*)malloc(sizeof(Door));
  r1Door->passable = 1;
  Door* r2Door = (Door*)malloc(sizeof(Door));
  r2Door->passable = 1;
  Door* r3Door = (Door*)malloc(sizeof(Door));
  r3Door->passable = 0;

  Room* room1 = (Room*)malloc(sizeof(Room));
  Room* room2 = (Room*)malloc(sizeof(Room));
  Room* room3 = (Room*)malloc(sizeof(Room));

  r1Door->leads = (struct room*)room1;
  r2Door->leads = (struct room*)room2;
  r3Door->leads = (struct room*)room3;

  doors1->num = 2;
  doors2->num = 2;
  doors3->num = 2;

  Door** room1DoorList = (Door**)malloc(sizeof(Door*) * 2);
  Door** room2DoorList = (Door**)malloc(sizeof(Door*) * 2);
  Door** room3DoorList = (Door**)malloc(sizeof(Door*) * 2);

  room1DoorList[0] = r2Door;
  room1DoorList[1] = r3Door;

  room2DoorList[0] = r1Door;
  room2DoorList[1] = r3Door;
 
  room3DoorList[0] = r2Door;
  room3DoorList[1] = r1Door;

  doors1->exits = room1DoorList;
  doors2->exits = room2DoorList;
  doors3->exits = room3DoorList;

  room1->name = "Foyee";
  room1->stuff = myRoomInventory1;
  room1->doors = doors1;
  room2->name = "Ballpit";
  room2->stuff = myRoomInventory2;
  room2->doors = doors2;
  room3->name = "Living Room";
  room3->stuff = myRoomInventory3;
  room3->doors = doors3;

  printRoom(room1);
  printRoom(room2);
  printRoom(room3);

  return 0;
}
