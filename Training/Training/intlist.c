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

bool isDeleted; //flag variable for list deleted status

/// <summary>Creates a new LinkedList to hold integers</summary>
/// <returns>pointer to linked list</returns>
LinkedList* Create () {
	LinkedList* list = (LinkedList*)malloc (sizeof (LinkedList));
	if (list != NULL) {
		list->head = NULL;
		list->isDeleted = false;
	}
	return list;
}


/// <summary>Adds element to the end of the list</summary>
/// <param name="linkedlist pointer"></param>
/// <param name="value"></param>
/// <returns>Error code (if any)</returns>
int Add (LinkedList* list, dataType data) {
	//BaseCase: checks if the list is deleted
	if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
	//case1: checks if the list is empty
	Node* newNode = CreateNode (data);
	if (list->head == NULL) {
		list->head = newNode;
		return 0;
	}
	//case2: if the list is not empty, it iterates to the desired position
	Node* current = list->head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
	return 0;

}


/// <summary>Return the number of elements in list</summary>
/// <param name="linkedlist pointer"></param>
/// <returns>Error code (if any)</returns>
int Count (LinkedList* list) {
	//BaseCase: checks if the list is deleted
	if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
	//case1: if the list is not deleted, it iterates to get count
	int count = 0;
	Node* current = list->head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}


/// <summary>Delete the entire list</summary>
/// <param name="linkedlist pointer"></param>
/// <returns>Error code (if any)</returns>
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


/// <summary>Removes the first occurrence of specified value in list</summary>
/// <param name="linkedlist pointer"></param>
/// <param name="value"></param>
/// <returns>Error code (if any)</returns>
int Remove (LinkedList* list, dataType data) {
	//BaseCase: checks if the list is deleted
	if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
	//case1: Checks if the list is empty
	Node* temp = list->head;
	Node* prev = NULL;
	if (temp == NULL) return E_EMPTY_LIST;
	//case2: Check if the data in head(1st node) is to be removed
	if (temp != NULL && temp->data == data) {
		list->head = temp->next;
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
		return E_VALUE_NOT_FOUND;
	}
}


/// <summary>Removes the value at a specified index</summary>
/// <param name="linkedlist pointer"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
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
		return E_INDEX_OUT_OF_RANGE;
	}
}


/// <summary>Returns the value at a specified index</summary>
/// <param name="linkedlist pointer"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
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


/// <summary>Inserts a value at a specified index</summary>
/// <param name="linkedlist pointer"></param>
/// <param name="value"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
int Insert (LinkedList* list, dataType data, int index) {
	//BaseCase: checks if the list is deleted
	if (list->isDeleted == true) return E_LIST_DOES_NOT_EXIST;
	//Case1: Checks if the inserted node is going to be the head
	Node* newNode = CreateNode (data);
	if (index == 0) {
		newNode->next = list->head;
		list->head = newNode;
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
	return 0;
}


Node* CreateNode (dataType data) { //creates a new node with specified value
	Node* newNode = (Node*)malloc (sizeof (Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}

