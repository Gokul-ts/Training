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
   int count;
   bool isDeleted;
   struct Node* head;
}LinkedList;

/// <summary>Returns a pointer to a new LinkedList of integers</summary>
LinkedList* Create ();
/// <summary>Adds element to the end of the list</summary>
int Add (LinkedList* list, dataType data);
/// <summary>Return the number of elements in list</summary>
int Count (LinkedList* list);
/// <summary>Delete the entire list</summary>
int Delete (LinkedList* list);
/// <summary>Removes the first occurrence of specified value in list</summary>
int Remove (LinkedList* list, dataType data);
/// <summary>Removes the value at a specified index</summary>
int RemoveAt (LinkedList* list, int index);
/// <summary>Returns the value at a specified index</summary>
int Get (LinkedList* list, int index);
/// <summary>Inserts a value at a specified index</summary>
int Insert (LinkedList* list, dataType data, int index);
/// <summary>Creates a new node with specified value</summary>
Node* CreateNode (dataType data);


