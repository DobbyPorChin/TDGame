#pragma once

//=================================
// include guard
#ifndef __GRID_H_INCLUDED__
#define __GRID_H_INCLUDED__
//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "Constant.h"
using namespace gameconst;
//=================================
// the actual class
class Grid
{
public:
	Grid();
	Grid(int x, int y);
	Grid(int x, int y, int dist);
	~Grid();

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

	void setDist(int dist);
	int getDist();

	void setType(Type type);
	Type getType();

	void setParentX(int parentX);
	void setParentY(int parentY);
	int getParentX();
	int getParentY();

	void setList(List list);
	List getList();

	bool operator== (int dist);
	bool operator< (int dist);
	bool operator<= (int dist);
	bool operator> (int dist);
	bool operator>= (int dist);

	bool operator== (Grid& grid);
	bool operator< (Grid& grid);
	bool operator<= (Grid& grid);
	bool operator> (Grid& grid);
	bool operator>= (Grid& grid);

private:
	static const int INFINITY = 66536;
	int x_, y_;
	int dist_;
	Type type_;
	int parentX_, parentY_;
	List list_;
};

#endif // __GRID_H_INCLUDED__ 

