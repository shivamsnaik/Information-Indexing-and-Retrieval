/* 
 * File:   selection.h
 * Author: prateek
 *
 * Created on 21 April, 2016, 12:39 PM
 */
/*
#ifndef SELECTION_H
#define	SELECTION_H

#include"newfile.h"

const int MAX = 10 ;
class SelectionSort
{
protected:
	int arr[MAX];
	int i;
	int j;
	int count ;
public:
	void array()
	{
		count = 0 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[i] = 0 ;
	}

	void add( int item )
	{
		if ( count < MAX )
	{
		arr[count] = item ;
		count++ ;
	}
	else
		cout << "\nArray is full" << endl ;
	}

	void sort()
	{
		int temp ;
	for ( int i = 0 ; i <= count - 2 ; i++ )
	{
		for ( int j = i + 1 ; j <= count - 1 ; j++ )
		{
			if ( arr[i] > arr[j] )
			{
				temp = arr[i] ;
				arr[i] = arr[j] ;
				arr[j] = temp ;
			}
		}
	}
	}

	void display()
	{
		for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "  " ;
	cout << endl ;
	}

	~SelectionSort(){}

};

#endif	/* SELECTION_H */
