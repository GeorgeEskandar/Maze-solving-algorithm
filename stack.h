#include<iostream>
#include"iomaze.h"
using namespace std;
//Header file containing the implementation of the stack data structure
#ifndef STACK_H
#define STACK_H


struct Node
{
	Spot* StackSpot;
	Node* next;
};

struct Stack
{
	Node* head;
	int count;
};
	//Functions
Stack* InitializeStack()
{
	Stack* Stack1=new Stack;
	Stack1->head=0;
	Stack1->count=0;
	return Stack1;
}
	bool isEmpty(Stack* Stack1)
	{
		return Stack1->head==NULL;
	}

	bool isFull(Node* nptr)
	{
		nptr=new Node;
		return nptr==0;
	}

	bool Push(Stack* Stack1, Spot* ptrSpot)
	{		 
		Node* temp=new Node;
		if(isFull(temp)) return false;
		temp->StackSpot=ptrSpot;
		temp->next=Stack1->head;
		Stack1->head=temp;
		Stack1->count++;
		return true;
	}

	bool Pop(Stack* Stack1, Spot*& Out)
	{
		if(isEmpty(Stack1))
			return false;
		Node* temp=Stack1->head;
		Stack1->head=temp->next;
		Out=temp->StackSpot;
		delete temp;
		Stack1->count--;
		return true;
	}
	void Display(Node* head)
	{		
		Spot* Print;
		if(head!=0)
		{
			Display(head->next);
			Print= head->StackSpot;
			if(Print->data!=-1)
			destination<<"( "<<Print->row<<","<<Print->col<<")  ";
		}
	}
	void DeleteStack(Stack* Stack1)
	{
		Spot* Out;
		while(!isEmpty(Stack1))
		{
			Node* temp=Stack1->head;
		Stack1->head=temp->next;
		Out=temp->StackSpot;
		delete temp;
		Stack1->count--;
		}
	}

#endif