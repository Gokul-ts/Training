// ------------------------------------------------------------------------------------------------
// Assignment2 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testintlist.c
// Testcases for the implementation of functions in Linked list
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "intlist.h"

int main () {

	//Testcases for LinkedList
	//case1: Create the Linked List, add 3 values and print count
	printf ("\nCase 1:\n");
	Node* headPtr = Create ();
	Add (&headPtr, 100);
	Add (&headPtr, 200);
	Add (&headPtr, 300);
	printf ("Expected: 3\n");
	printf ("Output: %d\n", Count (headPtr));
	Delete (&headPtr);

	//case2: Create the Linked List, add values,get count and remove values based on index
	printf ("\nCase 2:\n");
	Node* headPtr1 = Create ();
	Add (&headPtr1, 10);
	Add (&headPtr1, 20);
	Add (&headPtr1, 30);
	printf ("Expected: 0\n");
	int length = Count (headPtr1);
	for (int i = 0; i < length; i++) {
		RemoveAt (&headPtr1, 0);
	}
	printf ("Output: %d\n", Count (headPtr1));
	Delete (&headPtr1);

	//case3: Create the Linked List, delete list 2 times
	printf ("\nCase 3:\n");
	Node* headPtr2 = Create ();
	int n = Delete (&headPtr2);
	printf ("Expected: 0\n");
	printf ("Output1: ");
	printf ("%d\n", n);
	printf ("Expected: -3\n");
	int m = Delete (&headPtr2);
	printf ("Output2: ");
	printf ("%d\n", m);

	//case4: Create the Linked List, delete list and try to insert, add values to list
	printf ("\nCase 4:\n");
	Node* headPtr3 = Create ();
	Delete (&headPtr3);
	printf ("Expected: -3\n");
	int j = Add (&headPtr3, 20);
	printf ("Output1: ");
	printf ("%d\n", j);
	printf ("Expected: -3\n");
	int k = Insert (&headPtr3, 20, 0);
	printf ("Output2: ");
	printf ("%d\n", k);


	//case5: Create the Linked List, add values and remove values based on value itself
	printf ("\nCase 5:\n");
	Node* headPtr4 = Create ();
	Add (&headPtr4, 100);
	Add (&headPtr4, 200);
	Add (&headPtr4, 300);
	Remove (&headPtr4, 200);
	printf ("Expected: 2\n");
	printf ("Output: %d\n", Count (headPtr4));
	Delete (&headPtr4);

	//case6: Create the Linked List and insert values based on index
	printf ("\nCase 6:\n");
	Node* headPtr5 = Create ();
	for (int i = 0; i < 5; i++) {
		Insert (&headPtr5, i, 0);
	}
	printf ("Expected: 5\n");
	printf ("Output: %d\n", Count (headPtr5));
	Delete (&headPtr5);

	//case7: Create the Linked List and get values based on index
	printf ("\nCase 7:\n");
	Node* headPtr6 = Create ();
	Add (&headPtr6, 10);
	Add (&headPtr6, 20);
	Add (&headPtr6, 30);
	printf ("Expected: 20\n");
	int a = Get (headPtr6, 1);
	printf ("Output: %d\n", a);
	Delete (&headPtr6);


	//case8: Create an empty Linked List and try to get values based on index
	printf ("\nCase 8:\n");
	Node* headPtr7 = Create ();
	printf ("Expected: -2\n");
	int b = Get (headPtr7, 1);
	printf ("Output: %d\n", b);
	Delete (&headPtr7);


	//case9: Create a Linked List and try to get values exceeding index range
	printf ("\nCase 9:\n");
	Node* headPtr8 = Create ();
	Add (&headPtr8, 100);
	Add (&headPtr8, 200);
	Add (&headPtr8, 300);
	printf ("Expected: -1\n");
	int c = Get (headPtr8, 3);
	printf ("Output: %d\n", c);
	Delete (&headPtr8);

	//case10: Create a Linked List, add same values and remove the first occurence
	printf ("\nCase 10:\n");
	Node* headPtr9 = Create ();
	Add (&headPtr9, 100);
	Add (&headPtr9, 100);
	Add (&headPtr9, 100);
	printf ("Expected: 2\n");
	Remove (&headPtr9, 100);
	printf ("Output: %d\n", Count (headPtr9));
	Delete (&headPtr9);

	//case11: Create a Linked List and try giving negative values as index
	printf ("\nCase 11:\n");
	Node* headPtr10 = Create ();
	Add (&headPtr10, 100);
	Add (&headPtr10, 100);
	Add (&headPtr10, 100);
	printf ("Expected: -1\n");
	int d = Insert (&headPtr10, 10, -2);
	printf ("Output: %d\n", d);
	Delete (&headPtr10);

}
