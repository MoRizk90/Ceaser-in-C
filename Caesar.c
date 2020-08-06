/*
Author : M Rizk



*/

#include <stdio.h>

#include <cs50.h>

#include <string.h>

#include <math.h>

#include <stdlib.h>

#include <ctype.h>


int main(int argc, char *argv[])
{
  string errorMsg = "Usage: ./caesar [POSTIVE KEY]";
  string plainText = "";
  char upperCaseAlpha[] = {
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z'
  };
  char lowerCaseAlpha[] = {
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'
  };
  char asciiChar[12] = {
    ' ',
    ',',
    '!',
    '@',
    '#',
    '$',
    '%',
    '^',
    '&',
    '*',
    '(',
    ')'
  };
  int key = 0;

  //This validate the user did enter the require number of argements
  if (argc != 2) {
    printf("%s\n", errorMsg);
    return 1;
  } else {
    // Validating that we don't accept a negative value
    if (argv[1][1] == 49) {
      printf("%s\n", errorMsg);
      return 1;
    }
    //The Loop checks that is only decimal character
    for (int counter = 0; counter < strlen(argv[1]); counter++) {
      if (isalpha(argv[1][counter]) != 0) {
        printf("%s\n", errorMsg);
        return 1;
      }

    }

    key = atoi(argv[1]);
    //Get the plain text from from the users
    plainText = get_string("Enter your plaint text: ");
    char cipherText[strlen(plainText)];
    int cipherCounter = 0;
    for (int arrayCounter = 0; arrayCounter < strlen(plainText); arrayCounter++) {
      int counterSaver = 0;
      for (int comapringCounter = 0; comapringCounter < strlen(upperCaseAlpha); comapringCounter++) {
        if (plainText[arrayCounter] == upperCaseAlpha[comapringCounter]) {
          int sizeOfCipherTxtArray = sizeof(cipherText);
          int cipherEquation = (comapringCounter + key) % 26;
          cipherText[cipherCounter] = upperCaseAlpha[cipherEquation];
          cipherCounter++;
        } else if (plainText[arrayCounter] == lowerCaseAlpha[comapringCounter]) {
          int sizeOfCipherTxtArray = sizeof(cipherText);
          int cipherEquation = (comapringCounter + key) % 26;
          cipherText[cipherCounter] = lowerCaseAlpha[cipherEquation];
          cipherCounter++;
        } else {

          for (int theAsciiCounter = 0; theAsciiCounter < sizeof(asciiChar); theAsciiCounter++) {
            if (plainText[arrayCounter] == asciiChar[theAsciiCounter]) {
              if (counterSaver == 0) {
                cipherText[cipherCounter] = asciiChar[theAsciiCounter];
                cipherCounter++;
                counterSaver = 1;
              }
            }
          }
        }
      }
    }
    printf("ciphertext:");
    for (int cipherTextCounter = 0; cipherTextCounter < sizeof(cipherText); cipherTextCounter++) {
      printf("%c", cipherText[cipherTextCounter]);
    }
    printf("\n");

  }
  return 0;

}
