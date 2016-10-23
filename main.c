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

  RoomInven* myRoomInventory = (RoomInven*)malloc(sizeof(RoomInven));
  myRoomInventory->itemNum = 3;
  RoomObj** myRoomObjectArray = malloc(sizeof(RoomObj)*3);
  myRoomObjectArray[0] = myRoomObject1;
  myRoomObjectArray[1] = myRoomObject2;
  myRoomObjectArray[2] = myRoomObject3;
  myRoomInventory->items = myRoomObjectArray;

  printRoomInventory(myRoomInventory);
  return 0;
}
