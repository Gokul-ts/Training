#pragma once
// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Gokul TS @Metamation India.
// ------------------------------------------------------------------
// SortAndSearch.h
// Header file for SortAndSearch.c program
// ------------------------------------------------------------------------------------------------
#define MAX_DIGIT 13
#define TEST_SIZE 6
#define ANSI_RESET_ALL "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

/// <summary>Converts the input array into a sorted array</summary>
void InsertionSort (int arr[], int size);
/// <summary>Returns the index of key element in an array</summary>
int BinarySearch (int sortArr[], int key, int size);