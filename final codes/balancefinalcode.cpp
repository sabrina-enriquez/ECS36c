#include <iostream>
#include <fstream>
#include "StackLi.h"


int main(int argc, char** argv) {
  std::ifstream inFile(argv[1]);
  char symbols, unmatchedChar;
  int lineCount = 1, unmatchedLineNum;
  bool comment= false;
  bool unmatchedFound = false;
  bool unmatchedCommentEnd = false;
  bool inSet = false;
  StackLi<char> symbolsList = StackLi<char>();

  while (inFile >> std::noskipws >> symbols) {
    if (symbols == '\n') {
      lineCount++;
    }

    if (symbols == '/') {
      inFile >> std::noskipws >> symbols;
      if (symbols == '*') {
        unmatchedLineNum = lineCount;
        comment = true;
      }
      if (symbols == '/') {
        unmatchedLineNum = lineCount;
        comment = true;
      }
    }
    if (symbols == '*') {
      inFile >> std::noskipws >> symbols;
      if (symbols == '/') {
        unmatchedLineNum = lineCount;
        if (comment) {
          comment = false;
        }
        else {
          unmatchedCommentEnd = true;
        }
      }
    }

    if (comment) {
      if (symbols == '\n') {
        comment = false;
      }
    }

    if (!comment) {
      if (!unmatchedFound && (symbols == '(' || symbols == '[' || symbols == '{')) {
        symbolsList.push(symbols);
        unmatchedLineNum = lineCount;
      } else if (symbols == ')') {
        if (symbolsList.isEmpty()) {
          unmatchedFound = true;
          unmatchedChar = symbols;
          break;
        }
        if (symbolsList.top() == '(') {
          if (unmatchedFound) {
            inSet = true;
            break;
          }
          symbolsList.pop();
          continue;
        } else if (!unmatchedFound) {
          unmatchedFound = true;
          unmatchedChar = symbols;
          continue;
        }
      } else if (symbols == ']') {
        if (symbolsList.isEmpty()) {
          unmatchedFound = true;
          unmatchedChar = symbols;
          break;
        }
        if (symbolsList.top() == '[') {
          if (unmatchedFound) {
            inSet = true;
            break;
          }
          symbolsList.pop();
          continue;
        } else if (!unmatchedFound) {
          unmatchedFound = true;
          unmatchedChar = symbols;
          continue;
        }
      } else if (symbols == '}') {
        if (symbolsList.isEmpty()) {
          unmatchedFound = true;
          unmatchedChar = symbols;
          break;
        }
        if (symbolsList.top() == '{') {
          if (unmatchedFound) {
            inSet = true;
            break;
          }
          symbolsList.pop();
          continue;
        } else if (!unmatchedFound) {
          unmatchedFound = true;
          unmatchedChar = symbols;
          continue;
        }
      }
    }
//      else if (symbols == ')') {
//        if (symbolsList.top() != '(' && !symbolsList.isEmpty()) {
//          if (symbolsList.top() == '[' || symbolsList.top() == '{') {
//            unmatchedChar = symbolsList.top();
//          }
//          else {
//            unmatchedChar = symbols;
//          }
//          unmatchedLineNum = lineCount;
//          unmatchedFound = true;
//          break;
//        }
//        else if (symbolsList.isEmpty()) {
//          symbolsList.push(symbols);
//          unmatchedLineNum = lineCount;
//
//        }
//        else {
//          symbolsList.pop();
//        }
//      } else if (symbols == ']') {
//        if (symbolsList.top() != '[' && !symbolsList.isEmpty()) {
//          if (symbolsList.top() == '(' || symbolsList.top() == '{') {
//            unmatchedChar = symbolsList.top();
//          }
//          else {
//            unmatchedChar = symbols;
//          }
//          unmatchedLineNum = lineCount;
//          unmatchedFound = true;
//          break;
//        }
//        else if (symbolsList.isEmpty()) {
//          symbolsList.push(symbols);
//          unmatchedLineNum = lineCount;
//        }
//        else {
//          symbolsList.pop();
//        }
//      } else if (symbols == '}') {
//        if (symbolsList.top() != '{' && !symbolsList.isEmpty()) {
//          if (symbolsList.top() == '(' || symbolsList.top() == '[') {
//            unmatchedChar = symbolsList.top();
//          }
//          else {
//            unmatchedChar = symbols;
//          }
//          unmatchedLineNum = lineCount;
//          unmatchedFound = true;
//          break;
//        }
//        else if (symbolsList.isEmpty()) {
//          symbolsList.push(symbols);
//          unmatchedLineNum = lineCount;
//        }
//        else {
//          symbolsList.pop();
//        }
//      }
//      switch (symbols) {
//        case '(':
//          symbolsList.push(symbols);
//          break;
//        case ')':
//          if (symbolsList.top() != '(') {
//            unmatchedChar = symbolsList.top();
//            unmatchedFound = true;
//          }
//          else {
//            symbolsList.pop();
//          }
//          break;
//        case '[':
//          symbolsList.push(symbols);
//          break;
//        case ']':
//          if (symbolsList.top() != '[') {
//            unmatchedChar = symbolsList.top();
//            unmatchedFound = true;
//          }
//          else {
//            symbolsList.pop();
//          }
//          break;
//        case '{':
//          symbolsList.push(symbols);
//          break;
//        case '}':
//          if (symbolsList.top() != '{') {
//            unmatchedChar = symbolsList.top();
//            unmatchedFound = true;
//          }
//          else {
//            symbolsList.pop();
//          }
//          break;
//        case '/':
//          symbolsList.push(symbols);
//          inFile >> std::noskipws >> symbols;
//          if (symbols == '*') {
//            comment = true;
//          }
//          else {
//            symbolsList.pop();
//          }
//
//      }
//    }
//    case '*':
//      symbolsList.push(symbols);
//    inFile >> std::noskipws >> symbols;
//    if (symbols == '/') {
//      comment = false;
//    }
//    else {
//      symbolsList.pop();
//    }
//    if (symbols == '*' && symbolsList.top() =='/') {
//      comment = true;
//      }
//    if (comment == true) {
//      if (symbols == '/')
//      {
//        if (symbolsList.top() == '*') {
//          symbolsList.pop();
//          symbolsList.pop();
//        }
//      }
//  }
//
//    if (unmatchedFound) {
//      break;
//    }

    }

  if (comment) {
    std::cout << "Unmatched /* on line #" << unmatchedLineNum;
    exit(0);
  }
  if (unmatchedCommentEnd) {
    std::cout << "Unmatched */ on line #" << unmatchedLineNum;
    exit(0);
  }

  if (!inSet && unmatchedFound) {
    unmatchedChar = symbolsList.top();
  }

  if (!symbolsList.isEmpty() && !unmatchedFound) {
    unmatchedChar = symbolsList.top();
    unmatchedFound = true;
  }
//  }

  if (unmatchedFound) {
    std::cout << "Unmatched " << unmatchedChar << " on line #" << unmatchedLineNum;
  }
  else {
    std::cout << "OK";
  }
}