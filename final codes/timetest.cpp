#include <iostream>
#include <fstream>
#include "CPUTimer.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "vector.h"
#include "SkipList.h"
vector<CursorNode <int> > cursorSpace(500001);

int getChoice() {
  int choice;
  std::cout << "Your choice >> ";
  std::cin >> choice;
  return choice;
}

void RunList(char filename[]) {
  std::ifstream inFile(filename);
  inFile.ignore( 1000, '\n');
  char op;
  int value;
  List<int> linkedList = List<int>();
//  ListItr<int> iterator = linkedList.zeroth();
  while (inFile >> op >> value) {
    if (op == 'i') {
      linkedList.insert(value, linkedList.zeroth());
//      linkedList.insert(value, iterator);
//      iterator.advance();
    }
    else if (op == 'd') {
      linkedList.remove(value);
    }
  }
}

void RunCursorList(char filename[]) {
  std::ifstream inFile(filename);
  inFile.ignore( 1000, '\n');
  char op;
  int value;
  CursorList<int> cursorList(cursorSpace);
  while (inFile >> op >> value) {
    if (op == 'i') {
      cursorList.insert(value, cursorList.zeroth());
    }
    else if (op == 'd') {
      cursorList.remove(value);
    }
  }
}

void RunStackAr(char filename[]) {
  std::ifstream inFile(filename);
  inFile.ignore( 1000, '\n');
  char op;
  int value;
  StackAr<int> stackArray = StackAr<int>(500001);
  while (inFile >> op >> value) {
    if (op == 'i') {
      stackArray.push(value);
    }
    else if (op == 'd') {
      stackArray.pop();
    }
  }
}

void RunStackLi(char filename[]) {
  std::ifstream inFile(filename);
  inFile.ignore( 1000, '\n');
  char op;
  int value;
  StackLi<int> stackList = StackLi<int>();
  while (inFile >> op >> value) {
    if (op == 'i') {
      stackList.push(value);
    }
    else if (op == 'd') {
      stackList.pop();
    }
  }
}

void RunQueueAr(char filename[]) {
  std::ifstream inFile(filename);
  inFile.ignore( 1000, '\n');
  char op;
  int value;
  Queue<int> queueArray = Queue<int>(500001);
  while (inFile >> op >> value) {
    if (op == 'i') {
      queueArray.enqueue(value);
    }
    else if (op == 'd') {
      queueArray.dequeue();
    }
  }
}

void RunSkipList(char filename[]) {
  std::ifstream inFile(filename);
  inFile.ignore( 1000, '\n');
  char op;
  int value;
  SkipList<int> skipList = SkipList<int>(0, 500001);
  while (inFile >> op >> value) {
    if (op == 'i') {
      skipList.insert(value);
    }
    else if (op == 'd') {
      skipList.deleteNode(value);
//      linkedList.remove(value);
    }
  }
}

int main() {
  int choice;
  char filename[80];

  std::cout<<"Filename >> ";
  std::cin>> filename;
  std::cout << "  ADT Menu"<< std::endl;
  std::cout << "0. Quit"<< std::endl;
  std::cout << "1. LinkedList"<< std::endl;
  std::cout << "2. CursorList"<< std::endl;
  std::cout << "3. StackAr"<< std::endl;
  std::cout << "4. StackLi"<< std::endl;
  std::cout << "5. QueueAr"<< std::endl;
  std::cout << "6. SkipList"<< std::endl;

  CPUTimer ct;
  do {
    choice = getChoice();
    ct.reset();
    switch (choice) {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename); break;
    }
    cout << "CPU time: " << ct.cur_CPUTime() << endl;
  } while(choice > 0);
  return 0;
}
