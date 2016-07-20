/* 
 * File:   quicksort.h
 * Author: prateek
 *
 * Created on 2 May, 2016, 7:55 AM
 */

#ifndef QUICKSORT_H
#define	QUICKSORT_H

#include "newfile.h"
#include "node.h"

class file
{
public:
	string name;
	int count;
};

class quick:public Node
{
    int pivotIndex,  index1, index2;
    file temp;
    
    public:

    void quicksort(file array[], int firstIndex, int lastIndex)
    {
        //declaaring index variable
        if(firstIndex < lastIndex)
        {
            //assigning first element index as pivot element
            pivotIndex = firstIndex;
            index1 = firstIndex;
            index2 = lastIndex;

            //Sorting in Ascending order with quick sort
          
            while(index1 < index2)
            {
                while(array[index1].count <= array[pivotIndex].count && index1 < lastIndex)
                {
                    index1++;
                }
                while(array[index2].count>array[pivotIndex].count)
                {
                    index2--;
                }

                if(index1<index2)
                {
                    //Swapping opertation
                    temp = array[index1];
                    array[index1] = array[index2];
                    array[index2] = temp;
                }
            }

            //At the end of first iteration, swap pivot element with index2 element
            temp = array[pivotIndex];
            array[pivotIndex] = array[index2];
            array[index2] = temp;

            //Recursive call for quick sort, with partiontioning
            quicksort(array, firstIndex, index2-1);
            quicksort(array, index2+1, lastIndex);
        }
    }
};

#endif	/* QUICKSORT_H */

