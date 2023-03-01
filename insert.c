#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
  int data;
  Node *next;
};

Node *head = NULL, *p;

void alokasi();
void awal();
void akhir();
void setelah();
void sebelum();
void tampil();

int main() {
  int pilihan;
  while (1) {
    printf("Menu Insert\n");
    printf("1. Awal\n");
    printf("2. Akhir\n");
    printf("3. After\n");
    printf("4. Before\n");
    printf("5. Keluar\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%i", &pilihan);

    if(pilihan == 1) {
      fflush(stdin);
      alokasi();
      awal();
      fflush(stdin);
    } else if(pilihan == 2) {
      fflush(stdin);
      alokasi();
      akhir();
      fflush(stdin);
    } else if(pilihan == 3) {
      if(head == NULL) {
        printf("SLL masih kosong, tidak bisa Insert After");
      } else {
        alokasi();
        fflush(stdin);
        setelah();
        fflush(stdin);
      }
    } else if(pilihan == 4) {
      if(head == NULL) {
        printf("SLL masih kosong, tidak bisa Insert After");
      } else {
        alokasi();
        fflush(stdin);
        sebelum();
        fflush(stdin);
      }
    } else if(pilihan == 5) {
      exit(0);
    }

    tampil();
  }
}

void alokasi() {
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

void setelah() {
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

void sebelum() {
  Node *before, *prevbefore;
  int key;
  printf("Disisipkan sebelum node berapa? ");
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

void awal() {
  if(head != NULL) {
    p->next = head;
  }
    head = p;
}

void akhir() {
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

void tampil() {
  Node *baca;
  baca = head;

  printf("\nData yang ada di dalam SLL:\n");
  while (baca != NULL) {
    printf("%i\n", baca->data);
    baca = baca->next;
  }
  printf("\n");
}