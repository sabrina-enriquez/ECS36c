#include <iostream>
#include <fstream>
#include <cstdlib>
#include "QueueAr.h"
#include "StackLi.h"

int main(int argc, char** argv) {
  std::ifstream inFile(argv[1]);
  short bagNum;
  Queue<short> container = Queue<short>(atoi(argv[2]));
  StackLi<Queue<short>> plane = StackLi<Queue<short>>();
  while( inFile >> bagNum) {
    if(!container.isFull()) {
      container.enqueue(bagNum);
    }
    else if (container.isFull()) {
      plane.push(container);
      container.makeEmpty();
      container.enqueue(bagNum);
    }
  }
  // pushes the last container onto the plane
  plane.push(container);
  while(!plane.isEmpty())
  {
    Queue<short> cRemove = plane.topAndPop();
    while(!cRemove.isEmpty()) {
      std::cout << cRemove.dequeue() << " ";
    }
  }
}
