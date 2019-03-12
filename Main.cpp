#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"iomaze.h"
#include"stack.h"
#include"algorithm.h"

using namespace std;


void main()
{
	//Variables
	Spot** Maze; 
	Spot* Mouse=new Spot;
	string title;   
	int numberOfEntrances=0;
	//Reading and Solving Mazes
	while(!source.eof())
	{		
		Maze= InputMaze(nRows, nCols , title,numberOfEntrances); 
		destination<<title<<endl;
		int EntranceRow, EntranceCol;
		
       	for(int i=0; i<numberOfEntrances; i++)
		{
			ReadEntrance(EntranceRow, EntranceCol);
			DeleteStack(Visited);
			DeleteStack(Backtrack);
			//Reset the maze 
			for(int i=0; i<nRows; i++)
			{
				for(int j=0; j<nCols; j++)
					Maze[i][j].traversed=false;
			}
			/////////////////
			destination<<"Entrance ("<<EntranceRow<<", "<<EntranceCol<<"): ";
			Mouse=&Maze[EntranceRow][EntranceCol];
			if(Mouse->data==1)
			{
				destination<<"Invalid\n";
				continue;
			}
			Mouse->traversed=true;
			Push(Visited,Mouse);
			bool succeeded=FindPath(Maze,Mouse); 
			if(succeeded)
			{
				Display(Visited->head);
			}
			destination<<endl;		
		}
	}
			source.close();
			destination.close();
}

	