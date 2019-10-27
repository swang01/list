#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void print_list(struct node * head){
  printf("[ ");
  while (head != NULL){
    printf("%d ",head->i);
    head = head->next;
  }
  printf("]\n");
}

struct node * insert_front(struct node * head, int i){
  struct node * new;
  new = (struct node *)malloc(sizeof(struct node));
  new->i = i;
  new->next = head;
  return new;
}

struct node * free_list(struct node * head){
  struct node * previous;
  while (head != NULL){
    previous = head;
    head = head->next;
    free(previous);
  }
  return head;
}

struct node * remove_node(struct node *front, int data){
  struct node * current = front->next;
  struct node * previous = front;
  if (front->i == data){
    free(front);
    return current;
  }
  while (current != NULL){
    if (current->i == data){
      previous->next = current-> next;
      free(current);
      return front;
    }
    previous = current;
    current = current->next;
  }
  return front;
}
