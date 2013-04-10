#include "Dijkstra.h"

Dijkstra::Dijkstra()
{
}

Dijkstra::~Dijkstra()
{
}

std::vector<Grid*> Dijkstra::findPath(int mapId, int startX, int startY)
{
	//int nOpenListItems = 0,
	//onOpenList=1, onClosedList = 2,
	//parentXval=0, parentYval=0,
	//a=0, b=0, m=0, u=0, v=0, temp=0, corner=0, 
	//addedGCost=0, tempGcost = 0, path = 0, x=0, y=0,
	//tempx = 0, pathX = 0, pathY = 0, cellPosition = 0,
	//newOpenListItemID=0;
	Grid* currentGrid;
	Grid* parentGrid;
	std::vector<Grid*> path;
	
//3.Reset some variables that need to be cleared
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {
			//dist[i][j] = infinity;
			//inWhichList[i][j] = 0;
			//map[i][j] = 0;
			
			grids[i][j].setX(i);
			grids[i][j].setY(j);

			//gridDistance[i][j] = INFINITY;
			//gridParentX[i][j] = -1;
			//gridParentY[i][j] = -1;
			//gridType[i][j] = TYPE_NONE;
			//gridList[i][j] = LIST_NONE;
		}
	}
//Set start point and add to open list.
	grids[startX][startY].setDist(0);
	grids[startX][startY].setList(LIST_OPENLIST);
	binaryHeap.insert(&grids[startX][startY]);

	gridDistance[startX][startY] = 0;
	gridList[startX][startY] = LIST_OPENLIST;


//Set Target(temp).
	grids[mapWidth-1][mapHeight-1].setType(TYPE_TOWER);
	grids[1][1].setType(TYPE_WALL);
	grids[1][2].setType(TYPE_WALL);
	grids[2][1].setType(TYPE_WALL);
	grids[2][2].setType(TYPE_WALL);

//Find Path.
	while (!binaryHeap.isEmpty()) {
		currentGrid = binaryHeap.popMin();
		
		if (currentGrid->getType() == TYPE_TOWER) {
			//targetGrid = currentGrid;
			while (currentGrid->getX() > -1 || currentGrid->getY() > -1) {
				path.push_back(currentGrid);
				parentGrid = &grids[currentGrid->getParentX()][currentGrid->getParentY()];
				currentGrid = parentGrid;
			}
			return path;
		}
			
		
		if(currentGrid->getDist() == INFINITY)
			return path;

		currentGrid->setList(LIST_CLOSEDLIST);

		//Add adjacent grids to open list.
		for (int i = currentGrid->getX() - 1; i <= currentGrid->getX() + 1; i++) {
			for (int j = currentGrid->getY() - 1; j <= currentGrid->getY() + 1; j++) {

				//Check if adjacent grid is in boundary.
				if (i > -1 && i < mapWidth && j > -1 && j < mapHeight && grids[i][j].getType() != TYPE_WALL) {
					
					//Check if adjacent grid is not in any list. Add it into open list.
					if (grids[i][j].getList() == LIST_NONE) {
						grids[i][j].setList(LIST_OPENLIST);
						gridNode[i][j] = binaryHeap.insert(&grids[i][j]);
					}

					if (grids[i][j].getList() == LIST_OPENLIST) {
						int distTemp = currentGrid->getDist() + calculateAdjacentDistance(currentGrid, &grids[i][j]);

						if (distTemp < grids[i][j].getDist()) {
							grids[i][j].setDist(distTemp);
							grids[i][j].setParentX(currentGrid->getX());
							grids[i][j].setParentY(currentGrid->getY());
							gridNode[i][j] = binaryHeap.shiftUp(gridNode[i][j]);
						}
					}
				}
			}
		}
	}

//Set target
	//map[16][16] = 1;

//Check if start = target
	//if (map[startGridX][startGridY] == towerLocation)
	//	return 1;

	//dist[startGridX][startGridY] = 0;

//4.Add the starting location to the open list of squares to be checked.
	//nOpenListItems = 1;
	//openList[1] = 1;
	//openX[1] = startGridX;
	//openY[1] = startGridY;
	

	

	//while (true) {

	//}
	return path;
}

int Dijkstra::calculateAdjacentDistance(Grid* u, Grid* v)
{
	
	int distX = abs(u->getX() - v->getX());
	int distY = abs(u->getY() - v->getY());
	if (distX == 0 || distY == 0)
		return (distX + distY) * 10;
	else
		return 14;
}
