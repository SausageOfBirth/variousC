#include "numString.h"
#include "inventory.h"

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

  printf("%s\n",intToString(1204567));
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
  return 0;
}
