#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "SDL/include/SDL_rect.h"
#include "PugiXml/src/pugixml.hpp"
#include "SString.h"

enum class EntityType
{
	PLAYER,
	ENEMY,
	NPC,
	ITEM,
	MAP,
	UNKNOWN
};

class Entity
{
public:
	Entity(EntityType type) : type(type) {}

	virtual bool Load() { return true; }
	
	virtual bool Update(float dt) { return true; }

	virtual bool CheckCollisions() { return true; }
	
	virtual void Draw() {}

	virtual bool UnLoad() { return true; }

	virtual bool LoadState(pugi::xml_node& node) { return true; }

	virtual bool SaveState(pugi::xml_node& node) 
	{ 
		return true; 
	}

public:
	SDL_Rect bounds;
	SString name;
	EntityType type;
};

#endif //__ENTITY_H__