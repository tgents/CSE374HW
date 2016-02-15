/* 
 * Thomas Tseng
 * 1/27/2016
 *
 * Gasp
 * This program will print any line of a file that matches a given string.
 * Usage: gasp [OPTIONS] [STRING] [FILENAME]
 *
 * Inputs: 
 *     a string and a file.
 *
 * Options: 
 *     -i | ignores all case within the input string and the input file
 *     -n | prints the line number for each of the matched lines
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 500
#define MAX_WORD_LENGTH 100


void check_lines(FILE *file, int checkCaps, int printLines,
                char *word, char *filename);
char *strlow(char *word);


int main(int argc, char  *argv[]) {
	/*checkCaps will keep track of whether -i was chosen*/
  int checkCaps = 0;
  /*printLines will keep track of whether -n was chosen*/
  int printLines = 0;

  if (argc < 2 || argc > 5) {
    fprintf(stderr, "%s\n", "Usage: gasp [OPTIONS] [STRING] [FILENAME]");
    return 1;
  }
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-i") == 0) {
      checkCaps = 1;
    }
    if (strcmp(argv[i], "-n") == 0) {
      printLines = 1;
    }
  }

  char *filename = argv[argc-1];
  char *searchString = argv[argc-2];

  if (sizeof(searchString) >= MAX_WORD_LENGTH) {
    fprintf(stderr, "%s\n", "STRING needs to be less than 100 characters");
    return 2;
  }

  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    check_lines(file, checkCaps, printLines, searchString, filename);
    return 0;
  } else {
    fprintf(stderr, "%s %s\n", argv[argc-1], "not found");
    return 2;
  }
  return 0;
}

/*
 * The check_lines function will take in 5 inputs, check the provided file, and print any lines matched.
 *
 * Parameters:
 *     file | the file to be read
 *     checkCaps | whether or not to factor in upper or lower case while checking
 *     printLines | whether or not to print the line numbers
 *     word | the provided string to match for
 *     filename | the name of the given file
 *
 * Return:
 *     void
 */
void check_lines(FILE *file, int checkCaps, int printLines,
                char *word, char *filename) {
  if (checkCaps == 1) {
    word = strlow(word);
  }
  char line[MAX_LINE_LENGTH];
  char line_copy[MAX_LINE_LENGTH];
  int count = 1;
  while (fgets(line, MAX_LINE_LENGTH, file)) {
    if (checkCaps == 1) {
      strncpy(line_copy, line, MAX_LINE_LENGTH);
      strlow(line);
    }
    if (strstr(line, word)) {
      printf("%s: ", filename);
      if (printLines == 1) {
        printf("line %d: ", count);
      }
      printf("%s", checkCaps == 1 ? line_copy : line);
    }
    count++;
  }
}

/*
 * The strlow function will change given string to all lowercase. 
 * The string provided will be altered directly, not a copy.
 *
 * Parameters:
 *     word | the string to be altered
 *
 * Return:
 *     char * | the altered string
 */
char *strlow(char *word) {
  for (int i = 0; *(word+i); ++i) {
    *(word+i) = tolower(*(word+i));
  }
  return word;
}

