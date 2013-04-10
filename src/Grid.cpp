#include "Grid.h"

Grid::Grid()
{
	x_ = 0;
	y_ = 0;
	dist_ = INFINITY;
	type_ = TYPE_NONE;
	parentX_ = -1;
	parentY_ = -1;
	list_ = LIST_NONE;
}

Grid::Grid(int x, int y)
{
	x_ = x;
	y_ = y;
	dist_ = INFINITY;
	type_ = TYPE_NONE;
	parentX_ = -1;
	parentY_ = -1;
	list_ = LIST_NONE;
}

Grid::Grid(int x, int y, int dist)
{
	x_ = x;
	y_ = y;
	dist_ = dist;
}

Grid::~Grid()
{
}

void Grid::setX(int x)
{
	x_ = x;
}

void Grid::setY(int y)
{
	y_ = y;
}

int Grid::getX()
{
	return x_;
}

int Grid::getY()
{
	return y_;
}

void Grid::setDist(int dist)
{
	dist_ = dist;
}

int Grid::getDist()
{
	return dist_;
}

void Grid::setType(Type type)
{
	type_ = type;
}

Type Grid::getType()
{
	return type_;
}

void Grid::setParentX(int parentX)
{
	parentX_ = parentX;
}

void Grid::setParentY(int parentY)
{
	parentY_ = parentY;
}
	
int Grid::getParentX()
{
	return parentX_;
}
	
int Grid::getParentY()
{
	return parentY_;
}

void Grid::setList(List list)
{
	list_ = list;
}
	
List Grid::getList()
{
	return list_;
}


bool Grid::operator== (int dist)
{
	return dist_ == dist;
}

bool Grid::operator< (int dist)
{
	return dist_ < dist;
}

bool Grid::operator<= (int dist)
{
	return dist_ <= dist;
}

bool Grid::operator> (int dist)
{
	return dist_ > dist;
}

bool Grid::operator>= (int dist)
{
	return dist_ >= dist;
}

bool Grid::operator== (Grid& grid)
{
	return dist_ == grid.dist_;
}

bool Grid::operator< (Grid& grid)
{
	return dist_ < grid.dist_;
}

bool Grid::operator<= (Grid& grid)
{
	return dist_ <= grid.dist_;
}

bool Grid::operator> (Grid& grid)
{
	return dist_ > grid.dist_;
}

bool Grid::operator>= (Grid& grid)
{
	return dist_ >= grid.dist_;
}