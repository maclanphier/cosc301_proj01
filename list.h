#ifndef __LIST_H__
#define __LIST_H__

/* your list data structure declarations */

struct node{
	int value;
	struct node* next;
};

char **tokenify(const char *);


/* your function declarations associated with the list */
void list_insert(const int, struct node**);
void list_clear(struct node*);
void list_print(struct node*);
void list_print_matches(const int, const struct node**);
int list_delete(const int, struct node**);
void list_append(const int, struct node**);
void list_reverse(struct node**);
void list_sort(struct node**);
#endif // __LIST_H__
