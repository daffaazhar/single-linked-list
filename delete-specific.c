#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *next;
};

void allocation();
void insertEnd();
void deleteSpecific();
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
  printf("\nDeleting a specific node...\n");
  fflush(stdin);
  deleteSpecific();
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

void deleteSpecific() {
  Node *delete, *delete_helper;
  int key;
  printf("\nWhich data do you want to delete? ");
  scanf("%i", &key);

  if(head == NULL) {
    printf("SLL is still empty. Please enter data first.");
  } else {
    delete = head; 
    if(delete->data == key)
      deleteStart();
    else {
      while (delete->data != key) {
        if(delete->next == NULL) {
          printf("\nData %i is not in SLL\n", key);
          exit(0);
        } else {
          delete_helper = delete;
          delete = delete->next;
        }
      }
    delete_helper->next = delete->next;
    free(delete);
    delete = NULL;
    }
  }
}

void output() {
  Node *read;
  read = head;

  printf("\nSLL Result:\n");
  if(head == NULL)
    printf("Empty\n");
  else {
    while (read != NULL) {
      printf("%i\n", read->data);
      read = read->next;
    }
  }
}