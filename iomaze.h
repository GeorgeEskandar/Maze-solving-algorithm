#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//file containing the functions and the global variables related to input and output
#ifndef IOMAZE_H
#define IOMAZE_H

//Input file
const char* Inputpath="C:/Documents and Settings/Windows XP/My Documents/Visual Studio 2008/Projects/Maze Nouran-George/mazes.txt";
	ifstream source(Inputpath);
char comma;  //to skip commas
//Output file
const char* Outputpath="C:/Documents and Settings/Windows XP/My Documents/Visual Studio 2008/Projects/Maze Nouran-George/Output.txt";
ofstream destination(Outputpath);

struct Spot
{
	signed int data;  // 0 or 1
	signed int row;  
	signed int col;
	bool traversed;  
};

int nRows,nCols;



// Function that allocates memory for a maze 
//Given number of rows and columns
//Returns an empty 2-D array
	Spot** AllMaze(int row, int col)
	{
		nRows=row; nCols=col;
		Spot** arr;
		arr= new Spot* [row];
	for(int i=0;i<row;i++)
		arr[i]=new Spot [col];
	return arr;
	}
//Function that reads the maze from a file
//Given the number of rows and cols passed by reference
//Returns a 2D array containing the Maze
Spot** InputMaze(int &row, int& col, string& name, int& numberOfLocations)
{	
	
	source>>name;
	source>>row;
	source>>comma;
	source>>col;
	Spot** Maze;
	Maze=AllMaze(row,col);
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
		{
			source>>Maze[i][j].data;
			if(j!=col-1)
				source>>comma;
			Maze[i][j].col=j;
			Maze[i][j].row=i;
			Maze[i][j].traversed=false;
		}
		source>>numberOfLocations;
		return Maze;
}
//Function that reads the entrances
//Pre: 
//Post  number of locations and one of the locations
void ReadEntrance( int &inputRow, int &inputCol)
{
	source>>inputRow;
	source>>comma;
	source>>inputCol;
}
#endif