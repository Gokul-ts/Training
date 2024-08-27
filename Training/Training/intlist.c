// ------------------------------------------------------------------------------------------------
// Assignment2 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// inlist.c
// c program for creating a Linked List
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "intlist.h"
#include <stdbool.h>

//bool isDeleted; //flag variable for list deleted status



LinkedList* Create () {
   LinkedList* list = (LinkedList*)malloc (sizeof (LinkedList));
   if (list != NULL) {
      list->head = NULL;
      list->isDeleted = false;
      list->count = 0;
   }
   return list;
}

int Add (LinkedList* list, dataType data) {
   //BaseCase: checks if the list is deleted
   if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
   //case1: checks if the list is empty
   Node* newNode = CreateNode (data);
   if (list->head == NULL) {
      list->head = newNode;
      list->count++;
      return 0;
   }
   //case2: if the list is not empty, it iterates to the desired position
   Node* current = list->head;
   while (current->next != NULL) {
      current = current->next;
   }
   current->next = newNode;
   list->count++;
   return 0;
}

int Count (LinkedList* list) {
   if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
   return list->count;
}

int Delete (LinkedList* list) {
   //BaseCase: checks if the list is deleted
   if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
   //case1: Checks if the list is empty and deletes list
   Node* current = list->head;
   Node* next = NULL;
   if (current == NULL) {
      list->isDeleted = true;
      return 0;
   }
   //case2: if the list is not empty, it iterates to the end and deletes all nodes
   while (current != NULL) {
      next = current->next;
      free (current);
      current = next;
   }
   list->head = NULL;
   list->isDeleted = true;
   return 0;
}

int Remove (LinkedList* list, dataType data) {
   //BaseCase: checks if the list is deleted
   if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
   //case1: Checks if the list is empty
   Node* temp = list->head;
   Node* prev = NULL;
   if (temp == NULL) return E_EMPTY_LIST;
   //case2: Check if the data in head(1st node) is to be removed
   if (temp->data == data) {
      list->head = temp->next;
      free (temp);
      list->count--;
      return 0;
   }
   //case3: if the list is not empty, it iterates to remove the data at spec. index
   while (temp != NULL && temp->data != data) {
      prev = temp;
      temp = temp->next;
   }
   //case4: checks if index exceeds list count
   if (temp != NULL) {
      prev->next = temp->next;
      free (temp);
      list->count--;
      return 0;
   } else return E_VALUE_NOT_FOUND;
}

int RemoveAt (LinkedList* list, int index) {
   //BaseCase: checks if the list is deleted
   if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
   //case1: Checks if the list is empty
   Node* temp = list->head;
   Node* prev = NULL;
   if (temp == NULL) return E_EMPTY_LIST;
   //case2: Check if the data in head(1st node) is to be removed
   if (index == 0) {
      list->head = temp->next;
      free (temp);
      list->count--;
      return 0;
   }
   //case3: if the list is not empty, it iterates to remove the data at spec. index
   for (int i = 0; temp != NULL && i < index; i++) {
      prev = temp;
      temp = temp->next;
   }
   //case4: checks if index exceeds list count
   if (temp != NULL && prev != NULL) {
      prev->next = temp->next;
      free (temp);
      list->count--;
      return 0;
   } else return E_INDEX_OUT_OF_RANGE;
}

int Get (LinkedList* list, int index) {
   //BaseCase: checks if the list is deleted
   if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
   //case1: Checks if the list is empty
   Node* temp = list->head;
   if (temp == NULL) return E_EMPTY_LIST;
   //case2: iterates to get the value at index
   int count = 0;
   while (temp != NULL) {
      if (count == index) return (temp->data);
      count++;
      temp = temp->next;
   }
   return E_INDEX_OUT_OF_RANGE;
};

int Insert (LinkedList* list, dataType data, int index) {
   //BaseCase: checks if the list is deleted
   if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
   //Case1: Checks if the inserted node is going to be the head
   Node* newNode = CreateNode (data);
   if (index == 0) {
      newNode->next = list->head;
      list->head = newNode;
      list->count++;
      return 0;
   }
   //case2: if the list is not empty, it iterates to get the data at spec. index
   Node* temp = list->head;
   for (int i = 0; i < index - 1 && temp != NULL; i++) {
      temp = temp->next;
   }
   //case3: checks if index exceeds list count
   if (temp == NULL || index < 0) {
      free (newNode);
      return E_INDEX_OUT_OF_RANGE;
   }
   newNode->next = temp->next;
   temp->next = newNode;
   list->count++;
   return 0;
}

Node* CreateNode (dataType data) {
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode != NULL) {
      newNode->data = data;
      newNode->next = NULL;
   }
   return newNode;
}

