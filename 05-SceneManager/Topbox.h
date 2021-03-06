#pragma once

#include "GameObject.h"

// 
// The most popular type of object in Mario! 
// 
class CTopbox : public CGameObject
{
protected:
	int length;				// Unit: cell 
	float cellWidth;
	float cellHeight;
	int spriteIdBegin, spriteIdMiddle, spriteIdEnd;

public:
	CTopbox(float x, float y,
		float cell_width, float cell_height, int length,
		int sprite_id_begin, int sprite_id_middle, int sprite_id_end) :CGameObject(x, y)
	{
		this->length = length;
		this->cellWidth = cell_width;
		this->cellHeight = cell_height;
		this->spriteIdBegin = sprite_id_begin;
		this->spriteIdMiddle = sprite_id_middle;
		this->spriteIdEnd = sprite_id_end;
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void RenderBoundingBox();
	void BlockFromUnder(float& b) { b = 0.0f; }
	void BlockFromRight(float& r) { r = 0.0f; }
	void BlockFromLeft(float& l) { l = 0.0f; }



};

typedef CTopbox* LPTOPBOX;