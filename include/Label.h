#ifndef LABEL_H
#define LABEL_H

#include "Component.h"
#include <string>
#include <SDL2/SDL.h>



class Label: public Component // label ärver publikt från Component
{
    public:
		static Label* getInstance(int x, int y, int w, int h, std::string txt); //x,y,w,h som behövs i component, och string som den behöver själv
		void draw() ;														// istället för konstruktor används getInstance, returnerar en pekare, alltså hamnar objektet på heapen
		void collision(){}
		std::string getText() const;
		void setText(std::string newText);
		~Label();
	protected:
		Label(int x, int y, int w, int h, std::string txt); // protected för att man ej ska komma åt constructorn och kunnna skapa ett objekt på stacken
	private:
		std::string text; 
		SDL_Texture* texture;

		Label(const Label&) = delete;
        const Label& operator = (const Label&) = delete;
};
#endif