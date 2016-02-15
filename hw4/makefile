# Thomas Tseng
# tgents 1339907

# constructs the t9 program
t9: trie.o main.o
	gcc -Wall -std=c11 -o t9 trie.o main.o

#compiles trie
trie.o: trie.h trie.c
	gcc -Wall -std=c11 -g -c trie.c trie.h

#main for t9
main.o: main.c trie.h
	gcc -Wall -std=c11 -g -c main.c trie.h

#make sure no 'clean' file
.PHONY: clean 

#removes the .o files
clean:
	rm -f main.o trie.o t9