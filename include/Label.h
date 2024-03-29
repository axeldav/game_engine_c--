#ifndef LABEL_H
#define LABEL_H

#include "Component.h"
#include <string>
#include <SDL2/SDL.h>

class Label: public Component 
{
public:
	static Label* getInstance(int x, int y, int w, int h, std::string txt); 
	void draw();
	void collision(){}
	std::string getText() const;
	void setText(std::string newText);
	void mouseDown(int x, int y) {}
	~Label();
protected:
	Label(int x, int y, int w, int h, std::string txt);
private:
	std::string text; 
	SDL_Texture* texture;
};

#endif