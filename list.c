#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList(){
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL) exit(EXIT_FAILURE);
    list->head = NULL;
    list->current = NULL;
    list->tail = NULL;
    return list;
}

void * firstList(List * list){
    if (list->head != NULL){
        list->current = list->head;
        return list->head->data;
    }
    return NULL;
}

void * nextList(List * list){
    if(list->head == NULL) return NULL;
    if(list->current == NULL) return NULL;
    if((list->current->next != NULL) && (list->current->next->data != NULL)){
        list->current = list->current->next;
        return list->current->data;
    }
    return NULL;
}

void * lastList(List * list){
    if(list->tail != NULL && list->tail->data != NULL){
        list->current = list->tail;
        return list->current->data;
    }
    return NULL;
}

void * prevList(List * list){
    if(list->current == list->head || list->current == NULL) return NULL;
    if(list->current->prev != NULL){
        list->current = list->current->prev;
        return list->current->data;
    }
    return NULL;
}

void pushFront(List * list, void * data){
    Node *newNode = createNode(data);
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }

}

void pushBack(List * list, void * data){
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data){
    Node *newNode = createNode(data);
    newNode->prev = list->current;
    list->current->next = newNode;
    list->tail = list->current;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}