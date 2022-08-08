#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include "Label.h"
#include <string>

class ExitButton : public Label 
{
    public:
        static ExitButton* getInstance(int x, int y, int w, int h, std::string txt);
        void mouseDown(int x, int y);
        virtual ~ExitButton(){}
    protected:
        ExitButton(int x, int y, int w, int h, std::string txt);
};

#endif