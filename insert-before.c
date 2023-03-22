#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *next;
};

void allocation();
void insertStart();
void insertEnd();
void insertBefore();
void output();

Node *head = NULL, *p;

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
  insertBefore();
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

void insertStart() {
  if(head != NULL) {
    p->next = head;
  }
    head = p;
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

void insertBefore() {
  Node *before, *prevbefore;
  int key;
  printf("Inserted before which node? ");
  scanf("%i", &key);

  before = head;
  if(before->next == NULL)
    insertStart();
  else {
    while (before->data != key) {
      if(before->next == NULL) {
        printf("%i is not in SLL\n", key);
        exit(0);
      } else {
        prevbefore = before;
        before = before->next;
      }
    }
    p->next = before;
    prevbefore->next = p;
  }
}

void output() {
  Node *baca;
  baca = head;

  printf("\nSLL Result: \n");
  while (baca != NULL) {
    printf("%i\n", baca->data);
    baca = baca->next;
  }
}