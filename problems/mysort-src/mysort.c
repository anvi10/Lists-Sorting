#include "mysort.h"
#include <alloca.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//

//
// See test_sort to see how to use mysort.
/**
 * @brief Arbitrary sort func
 *
 * Sort an array of element of any type
 * using "compFunc" to sort the elements.
 * 
 * The elements are sorted such as:
 * 
 * if ascending != 0
 *   compFunc( array[ i ], array[ i+1 ] ) <= 0
 * else
 *   compFunc( array[ i ], array[ i+1 ] ) >= 0
 * 
 * @param n Number of elements.
 * @param elementSize Size of each element.
 * @param array Pointer to an array of arbitrary type.
 * @param ascending Boolean controlling the direction of the sort.
 * @param compFunc Comparison funciton.
 **/
void mysort(int n, int elementSize, void * array, int ascending, CompareFunction compFunc)
{
	/** @todo **/
	void * tmp = malloc(elementSize);
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<i;j++)
		{

			void *e1 = (void*)((char*)array+j*elementSize);
			void *e2 = (void*)((char*)array+i*elementSize);
			if(ascending ==1){
				if(compFunc(e1,e2)>0)
				{
					memcpy(tmp, e1,elementSize);
					memcpy(e1,e2,elementSize);
					memcpy(e2, tmp, elementSize);
				}
			}
			else{	
				if(compFunc(e1,e2)<0){
					memcpy(tmp, e1,elementSize);
					memcpy(e1,e2,elementSize);
					memcpy(e2, tmp, elementSize);

				}
			}
		}
	}
	free(tmp);

}

