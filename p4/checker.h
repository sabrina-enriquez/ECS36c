#ifndef CHECKER_H
#define	CHECKER_H

#include "CheckerRunner.h"
#include "Trie.h"

class Checker {
public:
  Checker(const DictionaryWord *words, int numWords);
  void findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1],
    int *count);
  void getMatchingWords(char matchingWordArray[100][MAX_LENGTH +1]);
  void alphabetize(char array[100][MAX_LENGTH+1]);

private:
  Trie arrayOfTries[38];
  char MatchingWords[100][MAX_LENGTH+1];

}; // class Checker 

#endif	// CHECKER_H

