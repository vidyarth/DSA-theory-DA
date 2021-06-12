#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 50000 
 
unsigned long hash_function(char* str) {
    unsigned long i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}
 
typedef struct Ht_item Ht_item;
struct Ht_item {
    char* key;
    char* value;
};
 
typedef struct HashTable HashTable;
struct HashTable {
    Ht_item** items;
    int size;
    int count;
};
 
Ht_item* create_item(char* key, char* value) {
    Ht_item* item = (Ht_item*) malloc (sizeof(Ht_item));
    item->key = (char*) malloc (strlen(key) + 1);
    item->value = (char*) malloc (strlen(value) + 1);
     
    strcpy(item->key, key);
    strcpy(item->value, value);
 
    return item;
}
 
HashTable* create_table(int size) {
    HashTable* table = (HashTable*) malloc (sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**) calloc (table->size, sizeof(Ht_item*));
    for (int i=0; i<table->size; i++)
        table->items[i] = NULL;
 
    return table;
}
 

 
void handle_collision(HashTable* table, unsigned long index, Ht_item* item) {
}
 
void ht_insert(HashTable* table, char* key, char* value) {
    Ht_item* item = create_item(key, value);
    unsigned long index = hash_function(key);
 
    Ht_item* current_item = table->items[index];
     
    if (current_item == NULL) {
        if (table->count == table->size) {
            printf("Insert Error: Hash Table is full\n");
            return;
        }
         
        table->items[index] = item; 
        table->count++;
    }
 
    else {
            if (strcmp(current_item->key, key) == 0) {
                strcpy(table->items[index]->value, value);
                return;
            }
     
        else {
            handle_collision(table, index, item);
            return;
        }
    }
}
 
char* ht_search(HashTable* table, char* key) {
    int index = hash_function(key);
    Ht_item* item = table->items[index];

    if (item != NULL) {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}
 
char* print_search(HashTable* table, char* key) {
    char* val;
    if ((val = ht_search(table, key)) == NULL) {
        printf("status : not available \n");
        return "0";
    }
    else {
        printf("status : available, Price :%s\n",val);
        return val;
    }
}
 
void print_table(HashTable* table) {
    printf("\nHash Table\n-------------------\n");
    for (int i=0; i<table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}
 
int main() {
    HashTable* ht = create_table(CAPACITY);
    ht_insert(ht, "chips", "20");
    ht_insert(ht, "pen", "50");
    ht_insert(ht, "notebook", "60");
    ht_insert(ht, "scale", "10");
    ht_insert(ht, "vegetables", "100");
    ht_insert(ht, "fruits", "150");
    char *s1;
    int c;
    do{
        char *s;
        int no;
        printf("enter your name : ");
        scanf("%s",&s);
        printf("enter the number of items : ");
        scanf("%d",&no);
        int price = 0;
        char *s2[5],*ans[5];
        for(int i=0;i<no;i++){
            scanf("%s",&s2[i]);
            ans[i] = print_search(ht,s2+i);
            price += atoi(ans[i]);
        }
        printf("Your total bill amount is : %d \n",price);
        printf("press 1 to continue and 0 to quit : ");
        scanf("%d",&c);
    }while(c != 0);
}
