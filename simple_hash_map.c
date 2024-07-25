#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct node {
	char * key;
	int val;
	struct node * next;
} node;

void insert(node ** hash_map, char * s, int val) {
	int index = s[0] - 97;
	if (hash_map[index] != NULL) {
		if (strcmp(hash_map[index] ->key, s) == 0) {
			hash_map[index]->val += val;
			return;
		}

		node * n = hash_map[index];
		
		while (n->next) {
			if (strcmp(n -> next ->key, s) == 0) {
				n -> next -> val += val;
				return;
			}
			n = n -> next;
		}
	
		n->next = malloc(sizeof(node));
		n->next ->next = NULL;
		n->next ->key = malloc(sizeof(char) * (1+strlen(s)));
		strcpy(n -> next ->key, s);
		n->next ->key[strlen(s)] = '\0';
		n->next ->val = val;
		


	} else {
		hash_map[index] = malloc(sizeof(node));
		hash_map[index] ->next = NULL;
		hash_map[index] ->key = malloc(sizeof(char) * (1+strlen(s)));
		strcpy(hash_map[index] ->key, s);
		hash_map[index] ->key[strlen(s)] = '\0';
		hash_map[index] ->val = val;
	}
}

void print(node ** hash_map) {
	for (int i = 0; i < 26; i++) {
		node * n = hash_map[i];
		while (n) {
			printf("%s: %d\n", n ->key, n -> val);
			n = n -> next;
		}
	}	
}

int main() {
	node * hash_map[26] = {NULL}; 
	insert(hash_map, "bingus", 10);
	insert(hash_map, "bingus", 10);
	insert(hash_map, "bingsu", 10);
	insert(hash_map, "cingus", 10);
	print(hash_map);

}
