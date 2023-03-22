#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *next;
};

Node *head, *p;

void allocation();
void insertEnd();
void deleteStart();
void output();

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
  printf("\nRemoving the first node...\n");
  deleteStart();
  output();
  
  return 0;
}

void allocation() {
  p = (Node *) malloc(sizeof(Node));
  if(p == NULL) {
    printf("Memory allocation failed");
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

void deleteStart() {
  Node *delete;
  
  delete = head;
  if(head == NULL)
    printf("SLL is still empty. Please enter data first!");
  else {
    if(delete->next == NULL)
      head = NULL;
    else
      head = delete->next;
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