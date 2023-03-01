#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *next;
};

Node *head = NULL, *p;

void allocation();
void insertBegin();
void output();

int main() {
  char answer;
  do {
    fflush(stdin);
    allocation();
    insertBegin();
    fflush(stdin);
    printf("Lagi [y/t]? ");
    answer = getchar();
  } while (answer == 'y' || answer == 'Y');
  output();

  return 0;
}

void allocation() {
  int x;

  printf("Masukkan data yang ingin disimpan: ");
  scanf("%i", &x);
  p = (Node *) malloc(sizeof(Node));
  if(p == NULL) {
    printf("Alokasi memori gagal");
    exit(0);
  } else {
    p->data = x;
    p->next = NULL;
  }
}

void insertBegin() {
  if(head != NULL) {
    p->next = head;
  }
    head = p;
}

void output() {
  Node *read;
  read = head;

  while (read != NULL) {
    printf("%i\n", read->data);
    read = read->next;
  }
}