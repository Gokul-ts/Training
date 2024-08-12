// ------------------------------------------------------------------------------------------------
// Assignment2 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// inlist.c
// Header file for creating a Linked List
// ------------------------------------------------------------------------------------------------
#pragma once

#define Index_out_of_range  -1
#define Empty_list -2
#define List_does_not_exist -3
#define Value_not_found -4

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* Create ();
int Add (Node** head, int data);
int Count (Node* head);
int Delete (Node** head);
int Remove (Node** head, int data);
int RemoveAt (Node** head, int index);
int Get (Node* head, int index);
int Insert (Node** head, int data, int index);
Node* CreateNode (int data);


