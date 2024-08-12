// ------------------------------------------------------------------------------------------------
// Assignment2 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// inlist.c
// c program for creating a Linked List
// ------------------------------------------------------------------------------------------------

#include<stdio.h>
#include <stdlib.h>
#include "intlist.h"
#include <stdbool.h>

bool isDeleted;

/// <summary>Creates a new LinkedList to hold integers</summary>
/// <returns>pointer to linked list</returns>
Node* Create () {
	Node* head = NULL;
	isDeleted = false;
	return head;
}


/// <summary>Adds element to the end of the list</summary>
/// <param name="pointer address"></param>
/// <param name="value"></param>
/// <returns>Error code (if any)</returns>
int Add (Node** head, int data) {
	//BaseCase: checks if the list is deleted
	if (isDeleted == true) return List_does_not_exist;
	//case1: checks if the list is empty
	Node* newNode = CreateNode (data);
	if (*head == NULL) {
		*head = newNode;
		return 0;
	}
	//case2: if the list is not empty, it iterates to the desired position
	Node* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
	return 0;

}


/// <summary>Return the number of elements in list</summary>
/// <param name="pointer address"></param>
/// <returns>Error code (if any)</returns>
int Count (Node* head) {
	//BaseCase: checks if the list is deleted
	if (isDeleted == true) return List_does_not_exist;
	//case1: if the list is not deleted, it iterates to get count
	int count = 0;
	Node* current = head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}


/// <summary>Delete the entire list</summary>
/// <param name="pointer address"></param>
/// <returns>Error code (if any)</returns>
int Delete (Node** head) {
	//BaseCase: checks if the list is deleted
	if (isDeleted == true) return List_does_not_exist;
	//case1: Checks if the list is empty and deletes list
	Node* current = *head;
	Node* next = NULL;
	if (current == NULL) {
		isDeleted = true;
		return 0;
	}
	//case2: if the list is not empty, it iterates to the end and deletes all nodes
	while (current != NULL) {
		next = current->next;
		free (current);
		current = next;
	}
	*head = NULL;
	isDeleted = true;
	return 0;
}


/// <summary>Removes the first occurrence of specified value in list</summary>
/// <param name="pointer address"></param>
/// <param name="value"></param>
/// <returns>Error code (if any)</returns>
int Remove (Node** head, int data) {
	//BaseCase: checks if the list is deleted
	if (isDeleted == true) return List_does_not_exist;
	//case1: Checks if the list is empty
	Node* temp = *head;
	Node* prev = NULL;
	if (temp == NULL) return Empty_list;
	//case2: Check if the data in head(1st node) is to be removed
	if (temp != NULL && temp->data == data) {
		*head = temp->next;
		free (temp);
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
		return 0;
	} else {
		return Value_not_found;
	}
}


/// <summary>Removes the value at a specified index</summary>
/// <param name="pointer address"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
int RemoveAt (Node** head, int index) {
	//BaseCase: checks if the list is deleted
	if (isDeleted == true) return List_does_not_exist;
	//case1: Checks if the list is empty
	Node* temp = *head;
	Node* prev = NULL;
	if (temp == NULL) return Empty_list;
	//case2: Check if the data in head(1st node) is to be removed
	if (index == 0) {
		*head = temp->next;
		free (temp);
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
		return 0;
	} else {
		return Index_out_of_range;
	}
}


/// <summary>Returns the value at a specified index</summary>
/// <param name="pointer address"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
int Get (Node* head, int index) {
	//BaseCase: checks if the list is deleted
	if (isDeleted == true) return List_does_not_exist;
	//case1: Checks if the list is empty
	Node* temp = head;
	if (temp == NULL) return Empty_list;
	//case2: iterates to get the value at index
	int count = 0;
	while (temp != NULL) {
		if (count == index) return (temp->data);
		count++;
		temp = temp->next;
	}
	return Index_out_of_range;
};


/// <summary>Inserts a value at a specified index</summary>
/// <param name="pointer address"></param>
/// <param name="value"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
int Insert (Node** head, int data, int index) {
	//BaseCase: checks if the list is deleted
	if (isDeleted == true) return List_does_not_exist;
	//Case1: Checks if the inserted node is going to be the head
	Node* newNode = CreateNode (data);
	if (index == 0) {
		newNode->next = *head;
		*head = newNode;
		return 0;
	}
	//case2: if the list is not empty, it iterates to get the data at spec. index
	Node* temp = *head;
	for (int i = 0; i < index - 1 && temp != NULL; i++) {
		temp = temp->next;
	}
	//case3: checks if index exceeds list count
	if (temp == NULL || index < 0) {
		free (newNode);
		return Index_out_of_range;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return 0;
}


Node* CreateNode (int data) { //creates a new node with specified value
	Node* newNode = NULL;
	newNode = (Node*)malloc (sizeof (Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}

