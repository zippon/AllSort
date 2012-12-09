#!/usr/bin/env python
# encoding: utf-8
"""
sort.py

Created by Zhipeng Wu on 2012-12-09.
Copyright (c) 2012 __MyCompanyName__. All rights reserved.
"""

import sys
import os

def BubbleSort(array):
	if not array: return
	counter = 0
	stop = len(array) - 1
	for i in range(0, stop):
		swap_flag = False
		for j in range(0, stop):
			if array[j] > array[j + 1]:
				array[j], array[j + 1] = array[j + 1], array[j]
				stop = j
				swap_flag = True
		counter += 1
		print "Round: %d" % counter
		print array
		if not swap_flag:
			break

	
def CocktailSort(array):
	if not array: return
	counter = 0
	stop_forward = len(array) - 1
	stop_backward = 1
	swap_flag = True
	while swap_flag:
		swap_flag = False
		for j in range(stop_backward - 1, stop_forward):
			if array[j] > array[j + 1]:
				array[j], array[j + 1] = array[j + 1], array[j]
				stop_forward = j
				swap_flag = True
		counter += 1
		print "Round: %d" % counter
		print array
		for k in range(stop_forward, stop_backward - 1, -1):
			if array[k] < array[k - 1]:
				array[k], array[k - 1] = array[k - 1], array[k]
				stop_backward = k
				swap_flag = True
		counter += 1
		print "Round: %d" % counter
		print array

	
def GnomeSort(array):
	if not array: return
	i = 0
	while i < len(array) - 1:
		if array[i] > array[i + 1]:
			array[i], array[i+1] = array[i+1], array[i]
			if i == 0:
				i += 1
			else:
				i -= 1
		else:
			i += 1
		

def SelectionSort(array):
	if not array: return
	for i in xrange(0, len(array)):
		min_ind = i;
		for j in xrange(i + 1, len(array)):
			if array[j] < array[min_ind]:
				min_ind = j
		if min_ind != i:
			array[i], array[min_ind] = array[min_ind], array[i]


def InsertionSort(array):
	if not array: return
	for i in xrange(1, len(array)):
		j = i
		while j > 0 and array[j] < array[j - 1]:
			array[j], array[j - 1] = array[j - 1], array[j]
			j -= 1


# Sift function used by heap sort.
def Sift(array, length, i):
	if not array or i >= length / 2: return
	max_ind = i
	left_ind  = i * 2 + 1
	if left_ind < length and array[max_ind] < array[left_ind]:
		max_ind = left_ind
	right_ind = left_ind + 1
	if right_ind < length and array[max_ind] < array[right_ind]:
		max_ind = right_ind
	if max_ind != i:
		array[i], array[max_ind] = array[max_ind], array[i]
		array = Sift(array, length, max_ind)

def HeapSort(array):
	# Create initial max heap.
	for i in xrange(len(array) / 2 - 1, -1, -1):
		Sift(array, len(array), i)
	# Sort the array.
	for i in xrange(len(array) - 1, 0, -1):
		array[i], array[0] = array[0], array[i]
		Sift(array, i, 0)	
		
def MergeSort(array, start, end):
	if not array or end - start < 1: return
	middle = (start + end ) / 2 + 1
	MergeSort(array, start, middle - 1)
	MergeSort(array, middle, end)
	Merge(array, start, middle, end)

# Merge function used by merge sort.
def Merge(array, start, middle, end):
	if not array or not start <= middle <= end: return
	temp = []
	i = start
	j = middle
	while i <= middle - 1 and j <= end:
		if array[i] < array[j]:
			temp.append(array[i])
			i += 1
		else:
			temp.append(array[j])
			j += 1
	while i <= middle - 1:
		temp.append(array[i])
		i += 1
	while j <= end:
		temp.append(array[j])
		j += 1
	for i in range(start, end + 1):
		array[i] = temp.pop(0)
		
def QuickSort(array, start, end):
	if not array or end - start <= 0: return
	i = start
	j = end + 1
	x = array[start]
	while i < j:
		i += 1
		while i <= end and array[i] < x: i += 1
		j -= 1
		while j >= start and array[j] > x: j -= 1
		if i < j:
			array[i], array[j] = array[j], array[i]
	if start < j:
		array[start], array[j] = array[j], array[start]
	QuickSort(array, start, j - 1)
	QuickSort(array, j + 1, end)

def CountingSort(array):
	min_value = min(array)
	max_value = max(array)
	length = max_value - min_value + 1
	temp = []
	for i in range(0, length):
		temp.append(0)
	for i in range(0, len(array)):
		temp[array[i] - min_value] += 1
	ind = 0
	for i in range(0, length):
		for j in range(0, temp[i]):
			array[ind] = i + min_value
			ind += 1

def main():
	array = [-1, 23, 45, 1, 22, 89, 34, -8, 0, -34, 97, 100]
	# Test bubble sort.
	# bubble = BubbleSort(array)
	# print "Bubble sort..."
	# print array
	
	# Test cocktail sort.
	# CocktailSort(array)
	# print "Cocktail sort..."
	# print array
	
	# Test gnome sort.
	# GnomeSort(array)
	# print "Gnome sort..."
	# print array
	
	# Test selection sort.
	# SelectionSort(array)
	# print "Selection sort..."
	# print array
	
	# Test insertion sort.
	# InsertionSort(array)
	# print "Insertion sort..."
	# print array
	
	# Test heap sort.
	# HeapSort(array)
	# print "Heap sort..."
	# print array
	
	# Test merge sort.
	# MergeSort(array, 0, len(array) - 1)
	# print array
	
	# Test quick sort.
	# QuickSort(array, 0, len(array) - 1)
	# print array
	
	# test counting sort
	# CountingSort(array)
	# print array
	


if __name__ == '__main__':
	main()

