#pragma once

//=================================
// include guard
#ifndef __DIJKSTRA_H_INCLUDED__
#define __DIJKSTRA_H_INCLUDED__
//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "Grid.h"
#include "BinaryHeap.h"
#include "Constant.h"
using namespace gameconst;
//=================================
// the actual class
class Dijkstra
{
	public:
		Dijkstra();
		~Dijkstra();

		std::vector<Grid*> findPath (int mapId, int startX, int startY);

	private:
		static const int INFINITY = 65536;
		static const int mapWidth = 4, mapHeight = 4, tileSize = 50, nPeople = 1;
		//int onClosedList = 10;
		static const int notfinished = 0, notStarted = 0;// path-related constants
		static const int found = 1, nonexistent = 2; 
		static const int walkable = 0, unwalkable = 1;// walkability array constants

		static const int towerLocation = 1;
		
		//Create needed arrays
		int map[mapWidth][mapHeight];
		int inWhichList[mapWidth+1][mapHeight+1];  //2 dimensional array used to record 
		// 		whether a cell is on the open list or on the closed list.
		int openList[mapWidth*mapHeight+2]; //1 dimensional array holding ID# of open list items
		int openX[mapWidth*mapHeight+2]; //1d array stores the x location of an item on the open list
		int openY[mapWidth*mapHeight+2]; //1d array stores the y location of an item on the open list
		int parentX[mapWidth+1][mapHeight+1]; //2d array to store parent of each cell (x)
		int parentY[mapWidth+1][mapHeight+1]; //2d array to store parent of each cell (y)
		int dist[mapWidth+1][mapHeight+1]; 	//2d array to store G cost for each cell.
		int pathLength[nPeople+1];     //stores length of the found path for critter
		int pathLocation[nPeople+1];   //stores current position along the chosen path for critter		
		int* pathBank[nPeople+1];

		//Path reading variables
		int pathStatus[nPeople+1];
		int xPath[nPeople+1];
		int yPath[nPeople+1];
//////////////////////////////////////////////////////////////////////////////
		
		BinaryHeap<Grid> binaryHeap;
		Grid grids[mapWidth][mapHeight];
		int gridNode[mapWidth][mapHeight];

		int calculateAdjacentDistance(Grid* u, Grid* v);

//////////////////////////////////////////////////////////////////////////////
		
		BinaryHeap<int> binaryHeap2;
		
		int gridDistance[mapWidth][mapHeight];
		int gridParentX[mapWidth][mapHeight];
		int gridParentY[mapWidth][mapHeight];
		int gridType[mapWidth][mapHeight];
		int gridList[mapWidth][mapHeight];

};

#endif // __DIJKSTRA_H_INCLUDED__ 

