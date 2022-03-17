//
// Created by Haley Chung on 2/25/2020.
//

#ifndef CHECKER__TRIE_H_
#define CHECKER__TRIE_H_

#include "CheckerRunner.h"
#include <cstring>


class Trie;

class TrieNode
{
  char letter;
  char nodeWord[MAX_LENGTH+1];
  TrieNode *nextSib;
  TrieNode *firstChild;

  TrieNode();
  TrieNode(char inLetter, const char *inWord, TrieNode *nextSibling, TrieNode *firstKid)
  : letter (inLetter), nextSib(nextSibling), firstChild(firstKid) {
    strcpy(nodeWord, inWord);
  }

  friend class Trie;
};

class Trie {
 public:
  Trie():root(NULL){};
  Trie(char *inWord); // CONFUSED ON PARAMETERS
  void insert(const char *word);
  void find(const char* inWord, char matchingWords[100][MAX_LENGTH+1], int* count); // CONFUSED ABOUT PARAMETERS
//  bool findRealWords(const char *inWord);

  void setFirstChild(TrieNode * &parent, TrieNode *child);
  void setNextSibling(TrieNode * &parent, TrieNode *nextSibling);
  TrieNode* getNextSibling(TrieNode *node);
  TrieNode* getFirstChild(TrieNode *node);

 private:
  TrieNode *root;
  const char *word;
  void insert(TrieNode *node, int pos); // CONFUSED ON POSITION PARAMETER
  void find(TrieNode* node, int pos, int& matchingPos, int errorCount, bool& isPerfect, char matchingWords[100][MAX_LENGTH+1], int* count); // CONFUSED ABOUT PARAMETERS
//  bool findRealWords(TrieNode *node, int pos);
};

#endif //CHECKER__TRIE_H_
