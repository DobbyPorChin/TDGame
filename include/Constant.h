#pragma once

//=================================
// include guard
#ifndef __CONSTANT_H_INCLUDED__
#define __CONSTANT_H_INCLUDED__
//=================================
// forward declared dependencies

//=================================
// included dependencies

//=================================
// the actual class
namespace gameconst {
	typedef enum Id {
		ID_TOWER_A_1 = 0x111,
		ID_TOWER_A_2 = 0x112,
		ID_TOWER_B_1 = 0x121,
		ID_TOWER_C_1 = 0x131,

		ID_HUMAN_A_1 = 0x311,

		ID_NONE = 0x000
	};
	typedef enum Type {
		TYPE_TOWER = 1,
		TYPE_WALL = 2,
		TYPE_HUMAN = 3,

		TYPE_NONE = 0
	};

	typedef enum List {
		LIST_OPENLIST = 1,
		LIST_CLOSEDLIST = 2,

		LIST_NONE = 0
	};
}

class Constant
{
	public:
		Constant();
		~Constant();

};


#endif // __CONSTANT_H_INCLUDED__ 

