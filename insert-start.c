#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *next;
};

Node *head = NULL, *p;

void allocation();
void insertStart();
void output();

int main() {
  char answer;
  do {
    fflush(stdin);
    allocation();
    insertStart();
    fflush(stdin);
    printf("Want to enter data again [y/t]? ");
    answer = getchar();
  } while (answer == 'y' || answer == 'Y');
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

void insertStart() {
  if(head != NULL) {
    p->next = head;
  }
  head = p;
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