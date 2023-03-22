#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *next;
};

void allocation();
void insertEnd();
void deleteEnd();
void output();

Node *head, *p;

int main() {
  char answer;
  do {
    fflush(stdin);
    allocation();
    insertEnd();
    fflush(stdin);
    printf("Want to enter data again [y/t]? ");
    answer = getchar();
  } while (answer == 'Y' || answer == 'y');
  output();
  printf("\nRemoving the last node...\n");
  deleteEnd();
  output();
  
  return 0;
}

void allocation() {
  p = (Node *) malloc(sizeof(Node));
  if(p == NULL) {
    printf("\nMemory allocation failed");
    exit(0);
  } else {
    printf("\nEnter the data you want to save: ");
    scanf("%i", &p->data);
    p->next = NULL;
  }
}

void insertEnd() {
  Node *tail;

  if(head == NULL) {
    head = p;
  } else {
    tail = head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = p;
  } 
}

void deleteEnd() {
  Node *delete, *delete_helper;

  if(head == NULL) {
    printf("SLL is still empty. Please enter data first!");
  } else {
    delete = head;
    if(delete->next == NULL)
      head = NULL;
    else {
      while (delete->next != NULL) {
        delete_helper = delete;
        delete = delete->next;
      }
      delete_helper->next = NULL;
    }
    free(delete);
    delete = NULL;
  }
}

void output() {
  Node *read;
  read = head;

  printf("\nSLL Result: \n");
  if(head == NULL)
    printf("Empty\n");
  else {
    while (read != NULL) {
      printf("%i\n", read->data);
      read = read->next;
    }
  }
}
