// Author: Sean Davis

#include "CheckerRunner.h"
#include "checker.h"
#include <cstring>

Checker::Checker(const DictionaryWord *words, int numWords) 
{
  for (int i = 0; i < numWords ; i++) {
//    std::cout << words[i].word << std::endl;
    arrayOfTries[strlen(words[i].word)].insert(words[i].word);
  }
//  for (int i = 1; i < numWords + 1; i++) {
//    arrayOfTries[i] = new Trie(NULL);
//  }
//  for (int i = 0; i < numWords ; i++) {
//    arrayOfTries[strlen(words[i].word)]->insert(words[i].word);
//  }
} // Checker()


void Checker::findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1],
  int *count)
{
  //first we need to check to see if its a real word
  int length = strlen(word);
//  int pos=0;

  //if it is not a real word
//  if(arrayOfTries[length].findRealWords(word)== false) {
//    int errorCnt=0; //initialize errorcount
  arrayOfTries[length].find(word, matchingWords, count);
    //if it is not then we check for partial matches and put them in our matchingwords2

    //getmatchingword(matchingWords);//puts our matchingwords2 into matchingWords
//  }

  //matchingWords= arrayOfTries[length]->getMatchingWords();//copy our array of partial matches to his array
//  //first we need to check to see if its a real word
//  int length = strlen(word);
//  int pos=0;
//
//  if(arrayOfTries[length]-> findRealWords(word, pos)== false)
//  { int errorCnt=0;
//    arrayOfTries[length] -> find(word,pos,errorCnt);
//    //if it is not then we check for partial matches and put them in our matchingwords2
//    matchingWords= arrayOfTries[length]->getMatchingWords();//copy our array of partial matches to his array
}

//void alphabetize(char unsortedMatched[100][MAX_LENGTH+1])
//{
//    char alphabet[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//    int pos=0;
//    MatchingWords[0][0] = unsortedMatched[0][0];// put first word in first slot
//
//    for( int i=1; i<27; i++)
//    {if
//
//    }
//
//}


