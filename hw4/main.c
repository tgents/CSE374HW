/* Thomas Tseng
 * tgents
 * 1339907
 * 
 * main for t9
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "%s\n", "Usage: t9 [FILE]");
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (!file) {
    fprintf(stderr, "Error: file not found\n");
    return 1;
  }

  // insert dictionary into trie
  Tnode *trie = init_trie();
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file)) {
    insert_word(trie, line);
  }

  fclose(file);

  // current position in trie
  Tnode *currentNode = trie;
  char input[MAX_LINE_LENGTH];

  printf("Enter \"exit\" to quit.\n");
  printf("Enter Key Sequence (or \"#\" for next word):\n");
  printf("> ");

  while (fgets(input, MAX_LINE_LENGTH, stdin)) {
    // remove newline
    char *trim;
    trim = strchr(input, '\n');
    if (trim) {
      *trim = '\0';
    }

    if (strcmp(input, "exit") == 0 || feof(stdin)) {
      break;
    }

    // check for #, else lookup word
    if (strcmp(input, "#") == 0) {
      if (currentNode && currentNode != trie) {
        printf("  %s\n", currentNode->word);
        currentNode = currentNode->nodes[8];
      } else {
        printf("  %s\n", "There are no more T9onyms");
      }
    } else {
      currentNode = lookup_word(trie, input);
      if (!currentNode || !currentNode->word) {
        printf("  %s\n", "Not found in current dictionary.");
      } else {
        printf("  \'%s\'\n", currentNode->word);
        currentNode = currentNode->nodes[8];
      }
    }

    printf("Enter Key Sequence (or \"#\" for next word):\n");
    printf("> ");
  }

  destroy_trie(trie);
  return 0;
}
