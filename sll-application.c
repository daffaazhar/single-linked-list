#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *next;
};

void menu();
void allocation();
void insertSort();
void searchData();
void deleteSpecific();
void freeNode(Node *);
void output();

Node *head = NULL, *p;

int main() {
  while (1) {
    menu();
    output();
  }

  return 0;
}

void menu() {
  int choice;
  printf("\n\nMAIN MENU:\n1. Orderly addition of data\n2. Search data\n3. Remove data\n4. Exit\n");
  printf("Enter your choice: ");
  scanf("%i", &choice);

  switch (choice) {
  case 1:
    allocation();
    insertSort();
    break;

  case 2:
    searchData();
    break;
  
  case 3:
    deleteSpecific();
    break;

  case 4:
    exit(0);
  }
}

void allocation() {
  p = (Node *) malloc(sizeof(Node));
  if(p == NULL) {
    printf("\nMemory allocation failed");
    exit(0);
  } else {
    printf("Enter the data you want to save: ");
    scanf("%i", &p->data);
    p->next = NULL;
  }
}

void insertSort() {
  Node *before, *prevbefore;

  if(head == NULL)
    head = p;
  else {
    if(p->data < head->data) {
      p->next = head;
      head = p;
    } else {
      before = head;
      while (p->data >= before->data) {
        if(before->next == NULL) {
          before->next = p;
          break;
        }
        prevbefore = before;
        before = before->next;
      }
      
      if(p->data < before->data) {
        p->next = before;
        prevbefore->next = p;
      }
    }
  }
}

void searchData() {
  int key, i;
  Node *search;
  search = head;

  if(head == NULL)
    printf("\nSLL is still empty. Please enter data first!");
  else {
    printf("Which data do you want to search? ");
    scanf("%i", &key);

    while (search != NULL) {
      if(search->data == key)
        i++;
      search = search->next;
    }
    if(i == 0)
      printf("\nData %i is not in SLL", key);
    else {
      printf("\nData %i found %i time(s)", key, i);
    }
  }
}

void deleteSpecific() {
  Node *delete, *delete_helper;
  int key, stop = 0;

  if(head == NULL) {
    printf("\nSLL is still empty. Please enter data first!");
  } else {
    printf("Which data do you want to delete? ");
    scanf("%i", &key);
    printf("Removing %i from SLL...\n", key);
    delete = head;
    if(head->data == key) {
      if(head->next == NULL)
        head = NULL;
      else
        head = head->next;
      freeNode(delete);
    } else {
      while (delete->data != key) {
        if(delete->next == NULL){
          printf("\nData %i is not in SLL", key);
          stop = 1;
          break;
        } else {
          delete_helper = delete;
          delete = delete->next;
        }
      }
      if(!stop) {
        delete_helper->next = delete->next;
        freeNode(delete);
      }
    }
  }
}

void freeNode(Node *node) {
  free(node);
  node = NULL;
}

void output() {
  Node *read;
  read = head;

  printf("\nSLL Result: ");
  if(head == NULL)
    printf("Empty");
  else {
    while (read != NULL) {
      printf("%i ", read->data);
      read = read->next;
    }
  }
}