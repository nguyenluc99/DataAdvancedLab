#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define initial_size 10
#define incremental_size 5

typedef struct {
    char name[80];
    long number;
} phoneEntry;

typedef struct {
    phoneEntry * entries;
    int total;
    int size;
} phoneBook;

phoneBook createPhoneBook() {
    phoneBook p;
    p.size = initial_size;
    p.entries = (phoneEntry *)malloc(initial_size * sizeof(phoneEntry));
    p.total = 0;
    return p;
}

void dropPhoneBook(phoneBook *p) {
    free(p->entries);
    // free(p->total);
    // free(p->size);
}

void dynamicAllocate(phoneBook * book) {
    int i,j, oldSize = book->size;
    phoneEntry *p = book->entries;
    phoneEntry *newEntry = (phoneEntry *)malloc((oldSize + incremental_size) * sizeof(phoneEntry));
    book->size += incremental_size;
    for (i = 0; i < oldSize; i++) {
        for (j = 0; j < strlen(book->entries[i].name); j++) {
            newEntry[i].name[j] = book->entries[i].name[j];
        }
        newEntry[i].number = book->entries[i].number;
    }
    book->size += incremental_size;
    book->entries = newEntry;
    free(p);
}

int binSearchName(int low, int high, char* target, phoneBook * book) {
    int mid = (int)((low + high) / 2);
    int cmp =  strcmp(book->entries[mid].name, target);
    // if (low > high) return -1;
    if (cmp == 0 || low == mid) return mid;
    else if (cmp > 0) return binSearchName(mid + 1, high, target, book);
    else return binSearchName(low, mid - 1, target, book);
}

void addPhoneNumber(char * name, long number, phoneBook * book) {
    int i, index, exists = 0;
     // Check Same phone number
    for (i = 0; i < book->total; i++) {
        // if (strcmp(book->entries[i].name, name) == 0) {
        if (book->entries[i].number == number) {
            print("Phone exists");
            return ;
        }
    }

     // Check memory and dynamically allocate if needed
    if (book->size == book->total) {
        dynamicAllocate(book);
    }

     // add phone number
    index = binSearchName(0, book->total, name, book);
    // printf("index of %s is %d", name, index);
    if (index == -1) {


    }
}

phoneEntry * getPhoneNumber(char * name, phoneBook * book) {

}
void main() {
    phoneBook firstBook = createPhoneBook();
    printf("size of book is : %d", firstBook.size);
    // addPhoneNumber
}
