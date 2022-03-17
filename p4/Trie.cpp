//
// Created by Haley Chung on 2/25/2020.
//

#include "Trie.h"

// Constructor
Trie::Trie(char *inWord) {
  word = inWord;
//  root = new TrieNode(word[0], word, NULL, NULL);
}

// Insert function (public)
void Trie::insert(const char* inWord) {
  word = inWord;
  if(root == NULL) {
    root = new TrieNode(word[0], word, NULL, NULL);
  }
  else {
    insert(root, 0);
  }
//  word = inWord;
//  insert(root, position);
}

// Find function (public) for partial matches
void Trie::find(const char* inWord, char matchingWords[100][MAX_LENGTH+1], int* count) {
  word = inWord;
  bool isPerfectMatch = false;
  int matchingPos = 0;
  // call private find function
  *count = 0;
  find(root, 0, matchingPos, 0, isPerfectMatch, matchingWords, count);
}

//// find Function (public) for perfect matches
//bool Trie::findRealWords(const char* inWord) {
//  word = inWord;
//  return findRealWords(root, position);
//}

// Insert function (private, recursive)
void Trie::insert(TrieNode* node, int pos) {
  if (word[pos] == node->letter) {
    if (node->firstChild != NULL) {
      pos++;
      insert(node->firstChild, pos);
    }
    else {
      pos++;
      TrieNode *newNode = new TrieNode(word[pos], word, NULL, NULL);
      node->firstChild = newNode;
    }
  }
  else {
    if (node->nextSib != NULL) {
      insert(node->nextSib, pos);
    }
    else {
      TrieNode *newNode = new TrieNode(word[pos], word, NULL, NULL);
      node->nextSib = newNode;
    }
  }
  /* if letter matches {
   *    if no child
   *       make a child
   *    else
   *       insert into child
   * }
   * else {
   *    if no sibling
   *      make sibling
   *    else
   *      insert into sibling
   * }
   */
}

// Find function (private, recursive) for partial matches
void Trie::find(TrieNode* node, int pos, int& matchingPos, int errorCount, bool& isPerfect, char matchingWords[100][MAX_LENGTH+1], int* count) {
  int errCt = errorCount;
  for (int i = pos; word[i] && errCt < 2; i++) {
    if (word[i] != node->nodeWord[i]) {
      errCt++;
    }
  }

  if(errCt == 0){
    isPerfect = true;
    strcpy(matchingWords[0],word);
    *count = 1;
  }
  else if(errCt < 2) {
    strcpy(matchingWords[matchingPos],node->nodeWord); //ERROR
    matchingPos++;
    (*count)++;
  }

  if(!isPerfect && word[pos] == node->nodeWord[pos]) {
    if(node->firstChild) {
      int tempPos = pos + 1;
      find(node->firstChild, tempPos, matchingPos, errorCount, isPerfect, matchingWords, count);
    }
  }
  else if (errorCount == 0) {
    if(node->firstChild) {
      int downErrorCount = errorCount + 1;
      int tempPos = pos + 1;
      find(node->firstChild, tempPos, matchingPos, downErrorCount, isPerfect, matchingWords, count);
    }
  }

  if (!isPerfect && node->nextSib) {
    find(node->nextSib, pos, matchingPos, errorCount, isPerfect, matchingWords, count);
  }
}

// find Function (private, recursive) for perfect matches
//bool Trie::findRealWords(TrieNode* node, int pos) {
//  if (word[pos] == node->letter) {
//    if (node->firstChild != NULL) {
//      pos++;
//      findRealWords(node->firstChild, pos);
//    }
//    else {
//      return false;
//    }
//  }
//  else {
//    if (node->nextSib != NULL) {
//      findRealWords(node->nextSib, pos);
//    }
//    else {
//      return false;
//    }
//  }
//  return true;
//}

void Trie::setFirstChild(TrieNode * &parent, TrieNode* child) {
  parent->firstChild = child;
} // setFirstChild()

void Trie::setNextSibling(TrieNode*& parent, TrieNode* nextSibling) {
  parent->nextSib = nextSibling;
} // setNextSibling()

TrieNode* Trie::getFirstChild(TrieNode* node) {
  return node->firstChild;
} // getFirstChild()

TrieNode* Trie::getNextSibling(TrieNode* node) {
  return node->nextSib;
} // getNextSibling()
