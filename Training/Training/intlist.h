// ------------------------------------------------------------------------------------------------
// Assignment2 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// inlist.c
// Header file for creating a Linked List
// ------------------------------------------------------------------------------------------------
#pragma once
#include <stdbool.h>

#define E_INDEX_OUT_OF_RANGE  -1
#define E_EMPTY_LIST -2
#define E_LIST_DOES_NOT_EXIST -3
#define E_VALUE_NOT_FOUND -4

typedef int dataType; //the datatype can be changed based on requirement

typedef struct Node {
	dataType data;
	struct Node* next;
}Node;

typedef struct LinkedList {
	bool isDeleted;
	struct Node* head;
}LinkedList;

LinkedList* Create ();
int Add (LinkedList* list, dataType data);
int Count (LinkedList* list);
int Delete (LinkedList* list);
int Remove (LinkedList* list, dataType data);
int RemoveAt (LinkedList* list, int index);
int Get (LinkedList* list, int index);
int Insert (LinkedList* list, dataType data, int index);
Node* CreateNode (dataType data);


