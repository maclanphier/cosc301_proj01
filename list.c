#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next; 
};

void list_insert(const int val, struct node **head) {
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->value = val;
 	struct node* cur = *head;
	if(cur==NULL || cur->value > val){
		*head = newnode;
		newnode->next = cur;
	}else{
		while(cur->next!=NULL){
			if(val < cur->next->value){
				newnode->next = cur->next;
				cur->next = newnode;
				return;
			}
			cur= cur->next;
		}
		cur->next = newnode;
		newnode->next == NULL;
	}
	
	
	printf("Start of the list is now: %d \n", (*head)->value);
}


void list_clear(struct node *list) {
    while (list != NULL) {
        struct node *tmp = list;
        list = list->next;
        free(tmp);
    }
}


void list_print(struct node *head) {
	printf("printing list: \n");
    	while(head!=NULL){
		printf("%d\n",head->value);
		head = head->next;	
	}  
	printf("END\n"); 
}

void list_print_matches(const int val, const struct node* head){
	while(head!=NULL){
		if(val!=head->value){
			printf("%d\n", head->value);
		}
		head = head->next;	
	}
	
}


int list_delete(const int val, struct node **head) {
	if(val==(*head)->value){
		struct node* tmp = *head;
		*head = tmp->next;
		free(tmp);
		return 1;
	}else{	
		struct node* cur_node = *head;
		while(cur_node!=NULL && cur_node->next!=NULL){
			if(cur_node->next->value==val){
				struct node* temp = cur_node->next;
				cur_node->next = temp->next;
				free(temp);
				return 1;		
			}
			cur_node = cur_node->next;
		}
	}
	return 0;
}

void list_append(const int val, struct node **head) {
	struct node* to_add = (struct node*)malloc(sizeof(struct node));
	to_add->value = val;
	to_add->next = NULL;
	if(*head == NULL){
		*head = to_add;
		return;
	}
	struct node* i = *head;
	while(i->next!=NULL){
		i=i->next;
	}
	i->next = to_add;
}

void list_reverse(struct node **head) {
	if(head==NULL || *head==NULL){return;}
	struct node* i = *head;
	while(i!=NULL){
		printf("%p\n",i);
		i = i->next;
	}
	struct node* a = *head;
	struct node* b = (*head)->next;
	struct node* temp = NULL;
	while(b!=NULL){
		a->next = temp;
		temp = a;
		a = b;
		b = b -> next;
	}
	a->next = temp;
	(*head) = a;
}


void list_sort(struct node **head) {
	if(*head == NULL || (*head)->next == NULL)
		return;

	struct node* i = *head;
	int length = 0;
	while(i!=NULL){
		length++;
		i = i->next;
	}

	struct node** list1 = head;
	struct node** list2 = head;
	int m = 0;
	for(i=*head;m<length/2-1;m++){
		i = i->next;
	}
	struct node* new_head = i->next;
	list2 = &new_head;
	i->next = NULL;

	list_sort(list1);
	list_sort(list2);

	struct node* h = *list1;
	i = *list2;
	struct node* end_of_merged;
	struct node* new_list_head;
	if(h->value < i->value){
		end_of_merged = h;
		new_list_head = h;
		h = h-> next;
	}else{
		end_of_merged = i;
		new_list_head = i;
		i = i->next;
	}
	while(h!=NULL && i!=NULL){
		if(h->value < i->value){
			end_of_merged->next = h;
			h = h->next;
		}else{
			end_of_merged->next = i;
			i = i->next;
		}
		end_of_merged = end_of_merged->next;
	}
	if(h==NULL && i!=NULL){
		end_of_merged->next = i;
	}else{
		end_of_merged->next = h;
	}
	(*head) = new_list_head;

}




