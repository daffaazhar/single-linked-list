#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *next;
};

Node *head = NULL, *p;

void allocation();
void insertEnd();
void insertAfter();
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
  } while (answer == 'y' || answer == 'Y');
  fflush(stdin);
  printf("\nInsert after a certain node...\n");
  allocation();
  fflush(stdin);
  insertAfter();
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
    tail = tail->next;
  }
}

void insertAfter() {
  Node *after;
  int key;

  printf("Inserted after which node? ");
  scanf("%i", &key);

  after = head;
  while (after->data != key) {
    if(after->next == NULL) {
      printf("\n%i is not in SLL\n", key);
      exit(0);
    } else {
      after = after->next;
    }
  }
  p->next = after->next;
  after->next = p;
}

void output() {
  Node *read;
  read = head;

  printf("\nSLL Result: \n");
  while (read != NULL) {
    printf("%i\n", read->data);
    read = read->next;
  }
}