#include "DLList.h"
#include <stdio.h>
DLList::DLList()
{
	DLNode *e = new DLNode();
	head=e;
	head->next =e;
	head->prev = e;
}

DLList::~DLList()
{
	delete head->next;
}

void DLList::print()
{
	DLNode *n;
	for(n=head->next; n!= head; n=n->next){
		printf("%d\n",n->data);
	}
}

void DLList::printSorted()
{
	DLNode *n;
	int counter =0;
	for( n=head->next; n != head; n=n->next,counter++);
	int arr[counter];

	int i = 0;
	for(n=head->next; n != head; n=n->next,i++ ){
		arr[i] = n->data;
	}

	for(int a = 0; a < counter;a++){
		for(int b = a+1; b < counter; b++){
			if(arr[a] > arr[b] ){
				int temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;

			}
		}
	}
	for(int a = 0; a < counter; a++){
		printf("%d\n", arr[a]);
	}
}

void DLList::insertFront(int data)
{
	DLNode *e = new DLNode();
	DLNode *e1;
	e1=head->next;
	head->next = e;
	e->next = e1;
	e1->prev = e;
	e->prev = head;
	e->data = data;



}

bool DLList::removeLast(int & data)
{
	DLNode *e= head->prev;
	e->prev->next = head;
	e->next->prev= e->prev;
	data = e->data;
	free(e);

	return true;

}

DLList * DLList::difference(DLList & list)
{
	DLList * diff = new DLList();
	DLNode *n;
	DLNode *e;
	for(n =head->prev; n != head; n=n->prev ){
		int check =1;
		for(e=list.head->prev; e != list.head; e=e->prev){
			if(n->data == e->data){
				check =0;
				//	diff->insertFront(n->data);
				//	break;
			}
		}
		if(check == 1){
			diff->insertFront(n->data);
		}

		e=list.head->prev;

	}
	return diff;
}

DLList * DLList::getRange(int start, int end)
{
	return this;
}

DLList * DLList::intersection(DLList & list)
{
	DLList * inter = new DLList();
	//        DLList *differ = new DLList();
	//        differ = difference(list);
	//	inter->head= head;
	//	while (head->next != head ) { 

	//	head = head->next;

	//	}

	return  inter;
}

void DLList::removeRange(int start, int end)
{

}
