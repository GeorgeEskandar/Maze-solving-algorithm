#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"iomaze.h"
#include"stack.h"
//file containing the algorithm
using namespace std;

Stack* Visited=InitializeStack();
Stack* Backtrack=InitializeStack();


//Function that determines if a spot is the exit spot
bool Exit(Spot* Current)
{
	if(Current->row==nRows-1||Current->col==nCols-1||Current->row==0||Current->col==0) //check if the current col is the last one or the current row is the last one
		return true;
	else return false;
}

//global variable- array 
//array containing available spots
Spot* Available[4];   
int count=0;
//Token that is pushed in the backtrack stack to marl the different routes specific to a certain intersection point
Spot* IntersectionToken=new Spot;
//Token that is pushed in the visited stack when encountering an intersection point
Spot* DecisionToken=new Spot;

//Function that checks 
int NumberOfPaths(Spot**Maze, Spot* Mouse)
{
	int i= Mouse->row;  //(i,j) are the coordinates of the mouse in the maze
	int j= Mouse->col;
	count=0;
	int k=0;   //index of the array containing available spots	
	if(Maze[i+1][j].data==0 && Maze[i+1][j].traversed==0)
	{count++; Available[k]=&Maze[i+1][j];  k++;}	
	if(Maze[i-1][j].data==0 && Maze[i-1][j].traversed==0) 
	{count++; Available[k]=&Maze[i-1][j];  k++;}
	if(Maze[i][j+1].data==0 && Maze[i][j+1].traversed==0) 
	{count++; Available[k]=&Maze[i][j+1]; k++;}	
	if(Maze[i][j-1].data==0 && Maze[i][j-1].traversed==0) 
	{count++; Available[k]=&Maze[i][j-1];  k++;}
	return count;
}


void Traverse(Spot* Current, Spot*& Mouse)
{
	Current->traversed=true;
	Mouse=Current;
	Push(Visited, Mouse);
	
}

bool FindPath(Spot** Maze, Spot*& Mouse)
{
	DecisionToken->data=-1;
	DecisionToken->row=-1;
	DecisionToken->col=-1;
	IntersectionToken->data=-1;
	IntersectionToken->row=-1;
	IntersectionToken->col=-1;
	///////////////////////////////////
	
	while(! Exit(Mouse))
	{
		int AvailablePaths= NumberOfPaths(Maze,Mouse);
		if(AvailablePaths==1)   //Continue
		{
			Traverse(Available[0],Mouse);
		}		
		else if(AvailablePaths>1)  //Intersection Point
		{
			for(int i=1;i<=AvailablePaths-1;i++)
			{
				Push(Visited, DecisionToken);
			}
			Traverse(Available[0],Mouse);
			for(int i=1; i<count; i++)
			{
				Push(Backtrack, Available[i]);
			}
			Push(Backtrack, IntersectionToken);
		}
		else if(AvailablePaths==0)  // Dead End
		{
			if(isEmpty(Backtrack))   //Trapped
			{
				destination<<"Trapped";
				return false;
			}
			else                                       //Return to the first intersection point
			{
				Spot* Popped=new Spot;
				do
				{
					Pop(Visited, Popped);
				}
				while(Popped->data!=-1);
				//Choose an alternative path
				Spot* OtherOption=new Spot;
				Pop(Backtrack, OtherOption); 
				if(OtherOption==IntersectionToken)
				{
					Pop(Backtrack, OtherOption);
				}
				//Set the position of the mouse to the new spot
				Traverse(OtherOption,Mouse);
			}
		}
	}
	return true;
}
