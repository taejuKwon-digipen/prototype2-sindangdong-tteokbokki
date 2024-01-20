// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#pragma once

using namespace levels;

class Screen
{
public:
    void DigiPen();
    void title();
    void recipe();
    void sauce();
    void mainIn();
    void subIn();
    void cooking();
    void stageClear();
    void over();
    void win();
    void drawBG();
    void howTo();

public:
    int clearRectX{ 380 }, clearRectY{ -250 }, clearRectXsize{ 120 }, clearRectYsize{ 50 };
    int min_x = clearRectX - clearRectXsize / 2;
    int max_x = clearRectX + clearRectXsize / 2;
    int min_y = clearRectY - clearRectYsize / 2;
    int max_y = clearRectY + clearRectYsize / 2;

    int buttonx{ -550 }, button1y{ -50 }, buttonxSize{ 30 }, buttonySize{ 30 };
    int button2y{ -110 }, button3y{ -170 }, button4y{ -230 }, button5y{ -290 };
    int startbuttonx{ 0 }, startbuttony{ -240 }, startbuttonxSize{ 250 }, startbuttonySize{ 80 };

public:
    int timer = 100;
    int level = level1;
    int logoTimer = 200;
};
