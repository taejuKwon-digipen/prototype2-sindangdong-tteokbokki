// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#pragma once

class SubI
{
public:
    struct Subs {
        int posx{ 0 }, posy{ 0 }, xSize{ 150 }, ySize{ 40 }, color{ 0 };
        std::string name;

        Subs(std::string nameshow, int x_Location, int y_Location, int x_Size, int y_Size, int colorNumb) :
            name(nameshow), posx(x_Location), posy(y_Location), xSize(x_Size), ySize(y_Size), color(colorNumb)
        {}
    };
    
public:
    void runGame();
    void drawBag();
    void drawSubs(Subs subname);
    void checkSubIn(std::vector<Subs> subInname);
    void drawPictures();

    bool mouseCheck = false;

    Subs Ace                { "Ace",                -400, 150,  50, 50, 0xDEB887FF };
    Subs Chocolate_Bar      { "Chocolate\nBar",     -300, 150,  50, 50, 0x483C32FF };
    Subs Cream_Cheese       { "Cream\nCheese",      -200, 150,  50, 50, 0xfaf7d2FF };
    Subs Mozzarella_Cheese  { "Mozzarella\nCheese", -100, 150,  50, 50, 0xfffde6FF };
    Subs Fried_Vegetables   { "Fried\nVegitables",  0,    150,  50, 50, 0x359440FF };
    Subs SPAM               { "SPAM",               -400, 50,   50, 50, 0xfab19bFF };
    Subs Raw_Egg            { "Raw\nEgg",           -300, 50,   50, 50, 0xfbd296FF };
    Subs Fried_Egg          { "Fried\nEgg",         -200, 50,   50, 50, 0xf7e04aFF };
    Subs Broad_Noodle       { "Broad\nNoodle",	    -100, 50,   50, 50, 0xccc286FF };
    Subs Soup_Base          { "Soup\nBase",         0,    50,   50, 50, 0xf07837FF };
    Subs Instant_Noodle     { "Instant\nNoodle",    -400, -50,  50, 50, 0xf07837FF };
    Subs Ramdong            { "Ramdong",            -300, -50,  50, 50, 0x6d4709FF };
    Subs Sundae             { "Sundae",             -200, -50,  50, 50, 0x5e523eFF };
    Subs Vienna             { "Vienna",             -100, -50,  50, 50, 0xfab19bFF };
    Subs Kielbasa           { "Kielbasa",           0,    -50,  50, 50, 0xfab19bFF };
    Subs Strawberry         { "Strawberry",         -400, -150, 50, 50, 0xff7d69FF };
    Subs Rapsberry          { "Rapsberry",          -300, -150, 50, 50, 0xe7381dFF };
    Subs Pear               { "Pear",               -200, -150, 50, 50, 0xe8dcb0FF };
    Subs Apple              { "Apple",              -100, -150, 50, 50, 0xd12a00FF };
    Subs Bacon              { "Bacon",              0   , -150, 50, 50, 0xfab19bFF };

    std::vector<Subs> SubIngredients = { Ace, Chocolate_Bar, Cream_Cheese, Mozzarella_Cheese, Fried_Vegetables,
                                         SPAM, Raw_Egg, Fried_Egg, Broad_Noodle, Soup_Base,
                                         Instant_Noodle, Ramdong, Sundae, Vienna, Kielbasa,
                                         Strawberry, Rapsberry, Pear, Apple, Bacon };

    std::vector<Subs> inBagSubs = {};

    std::vector<Subs> level1Subs = { Sundae };
    std::vector<Subs> level2Subs = { Broad_Noodle, Fried_Egg };
    std::vector<Subs> level3Subs = { Mozzarella_Cheese, Vienna };
    std::vector<Subs> level4Subs = { Pear, Ace, Raw_Egg, Bacon };
    std::vector<Subs> level5Subs = { Cream_Cheese, Mozzarella_Cheese, Ramdong, Fried_Egg, Strawberry };
};

