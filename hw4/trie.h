/* Thomas Tseng
 * tgents
 * 1339907
 * 
 * header for trie
 * declares functions for trie structure
 */

#ifndef TRIE_H
#define TRIE_H

// struct for a node in the Trie
typedef struct Tnode {
  char *word;
  struct Tnode *nodes[9];
} Tnode;

// creates an empty node
Tnode *init_trie(void);

// inserts the given str into the given Trie
void insert_word(Tnode *node, char *str);

// finds and returns the node at the end of str
Tnode *lookup_word(Tnode *node, char *str);

// destroys the given Trie
void destroy_trie(Tnode *node);

#endif
