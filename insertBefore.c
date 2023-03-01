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
void insertBefore();
void output();

int main() {
  char answer;
  do {
    fflush(stdin);
    allocation();
    insertEnd();
    fflush(stdin);
    printf("Lagi [y/t]? ");
    answer = getchar();
  } while (answer == 'y' || answer == 'Y');
  fflush(stdin);
  printf("Insert setelah node tertentu\n");
  allocation();
  fflush(stdin);
  insertBefore();
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
  printf("Disisipkan insertBefore node berapa? ");
  scanf("%i", &key);

  before = head;
  while (before->data != key) {
    if(before->next == NULL) {
      printf("%i tidak ada di dalam SLL\n", key);
      exit(0);
    } else {
      prevbefore = before;
      before = before->next;
    }
  }
  p->next = before;
  prevbefore->next = p;
}

void output() {
  Node *baca;
  baca = head;

  while (baca != NULL) {
    printf("%i\n", baca->data);
    baca = baca->next;
  }
}