/* Thomas Tseng
 * tgents
 * 1339907
 * 
 * defines functions for the trie
 */

#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// returns an empty trie node
Tnode *init_trie(void) {
  Tnode *n = malloc(sizeof(*n));
  if (n == NULL) {
    fprintf(stderr, "init: malloc failed\n");
    exit(1);
  }
  n->word = NULL;
  for (int i = 0; i < 9; i++) {
    n->nodes[i] = NULL;
  }
  return n;
}

// gets the corresponding value for the given char
// if not alphabet, returns -1
int get_val(char letter) {
  char lower = tolower(letter);
  if (lower == 'a' || lower == 'b' || lower == 'c')
    return 2;
  else if (lower == 'd' || lower == 'e' || lower == 'f')
    return 3;
  else if (lower == 'g' || lower == 'h' || lower == 'i')
    return 4;
  else if (lower == 'j' || lower == 'k' || lower == 'l')
    return 5;
  else if (lower == 'm' || lower == 'n' || lower == 'o')
    return 6;
  else if (lower == 'p' || lower == 'q' || lower == 'r' || lower == 's')
    return 7;
  else if (lower == 't' || lower == 'u' || lower == 'v')
    return 8;
  else if (lower == 'w' || lower == 'x' || lower == 'y' || lower == 'z')
    return 9;
  else
    return -1;
}

// inserts the given str into the given Trie
void insert_word(Tnode *node, char *str) {
  Tnode *currentNode = node;

  char *trim;
  trim = strchr(str, '\n');
  if (trim) {
    *trim = '\0';
  }

  // iterate through trie with the str
  for (int i = 0; i < strlen(str); i++) {
    int currentLetter = get_val(str[i]);

    if (currentLetter < 0) {
      fprintf(stderr, "could not insert: %s %c\n", str, str[i]);
      exit(1);
    }

    if (!currentNode->nodes[currentLetter-2]) {
      currentNode->nodes[currentLetter-2] = init_trie();
    }
    currentNode = currentNode->nodes[currentLetter-2];
  }

  // iterates to end of word list
  while (currentNode->word) {
    if (!currentNode->nodes[8]) {
      currentNode->nodes[8] = init_trie();
    }
    currentNode = currentNode->nodes[8];
  }
  currentNode->word = malloc(strlen(str) + 1);
  strncpy(currentNode->word, str, strlen(str) + 1);
}

// finds and returns the node at the end of str
Tnode *lookup_word(Tnode *node, char *str) {
  Tnode *currentNode = node;
  for (int i = 0; i < strlen(str); i++) {
    int currentNum;
    if (str[i] == '#') {
      currentNum = 10;
    } else {
      currentNum = str[i] - '0';
    }

    // num should be within 2-9 or 10 for #
    if (currentNum < 2 || currentNum > 10
        || !currentNode->nodes[currentNum-2]) {
      return NULL;
    }

    currentNode = currentNode->nodes[currentNum-2];
  }
  return currentNode;
}

// destroys the given trie
void destroy_trie(Tnode *node) {
  if (node) {
    for (int i = 0; i < 9; i++) {
      destroy_trie(node->nodes[i]);
    }
    free(node->word);
    free(node);
  }
}
