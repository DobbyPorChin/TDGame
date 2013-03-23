#pragma once

//=================================
// include guard
#ifndef __BASIC_ENEMY_H_INCLUDED__
#define __BASIC_ENEMY_H_INCLUDED__
//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "Enemy.h"

//=================================
// the actual class
class BasicEnemy :
	public Enemy
{
public:
	BasicEnemy(void);
	~BasicEnemy(void);
};

#endif // __BASIC_ENEMY_H_INCLUDED__ 

