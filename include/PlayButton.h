#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include "Label.h"
#include <string>

class PlayButton : public Label 
{
public:
    static PlayButton* getInstance(int x, int y, int w, int h, std::string txt);
    void mouseDown(int x, int y);
    virtual ~PlayButton(){}
protected:
    PlayButton(int x, int y, int w, int h, std::string txt);
};

#endif