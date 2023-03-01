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
    printf("Lagi [y/t]? ");
    answer = getchar();
  } while (answer == 'y' || answer == 'Y');
  fflush(stdin);
  printf("\nInsert setelah node tertentu\n");
  allocation();
  fflush(stdin);
  insertAfter();
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

void insertAfter() {
  Node *after;
  int key;

  printf("Disisipkan setelah node berapa? ");
  scanf("%i", &key);

  after = head;
  while (after->data != key) {
    if(after->next == NULL) {
      printf("%i tidak ada di dalam SLL\n", key);
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

  while (read != NULL) {
    printf("%i\n", read->data);
    read = read->next;
  }
}