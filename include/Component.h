#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL2/SDL.h>
#include <string>

class Component
{
public: 
	virtual ~Component(){}
	virtual void mouseDown(int x, int y) {} // tar kordinater för där musklick har skett 
	virtual void mouseUp(int x, int y) {}
	virtual void draw() = 0;
	SDL_Rect getRect() { return rect; }
	virtual void tick() {}
	virtual void collision() = 0;
	virtual std::string getTag(){ return tag; }
protected:
	Component(int x, int y, int w, int h) : rect{ x,y,w,h } {}
	SDL_Rect rect;
	std::string tag;
};

#endif
