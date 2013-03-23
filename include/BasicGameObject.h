#pragma once

//=================================
// include guard
#ifndef __BASIC_GAME_OBJECT_H_INCLUDED__
#define __BASIC_GAME_OBJECT_H_INCLUDED__
//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameObject.h"
//=================================
// the actual class
class BasicGameObject :
	public GameObject
{
public:
	BasicGameObject(void);
	~BasicGameObject(void);
};

#endif // __BASIC_GAME_OBJECT_H_INCLUDED__ 

