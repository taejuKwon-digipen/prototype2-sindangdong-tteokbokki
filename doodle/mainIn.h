// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#pragma once

class MainIn
{
public:
	struct mainIns {
		int x{ 0 }, y{ 0 }, xSize{ 0 }, ySize{ 0 }, color{ 0 };
		std::string name;

		mainIns(std::string nameShow, int x_Location, int y_Location, int x_Size, int y_Size, int colorNumb);
	};

public:
	void runGame();
	void drawBag();
	void drawPictures();
	void drawMainIn(mainIns mainInname);
	void checkMainIn(std::vector<mainIns> mainInname);

public:
	mainIns ricecake			{ "ricecake",				-400, 150,  50, 50, 0xecebdfff };
	mainIns wheatcake			{ "wheatcake",				-300, 150,  50, 50, 0xfff8e7ff };
	mainIns cheeseRicecake		{ "cheese\nRicecake",		-200, 150,  50, 50, 0xfffcccff };
	mainIns sweetPotatoRicecake	{ "sweet potato\nRicecake",	-100, 150,  50, 50, 0xd8bfccff };
	mainIns ingeolmi			{ "ingeolmi",				0,	  150,  50, 50, 0xd9b469ff };
	mainIns beakseolgi			{ "beakseolgi",				-400, 50,   50, 50, 0xffffffff };
	mainIns songpyeon			{ "songpyeon",				-300, 50,   50, 50, 0xfff0f0ff };
	mainIns greenOnion			{ "green\nOnion",			-200, 50,   50, 50, 0x6cb542ff };
	mainIns onion				{ "onion",					-100, 50,   50, 50, 0x7aff80ff };
	mainIns cabbage				{ "cabbage",				0,	  50,   50, 50, 0xd7e1a0ff };
	mainIns lettuce				{ "lettuce",				-400, -50,  50, 50, 0x87966dff };
	mainIns carrot				{ "carrot",					-300, -50,  50, 50, 0xffc08cff };
	mainIns cucumber			{ "cucumber",				-200, -50,  50, 50, 0x009e73ff };
	mainIns broccoli			{ "broccoli",				-100, -50,  50, 50, 0x0c3300ff };
	mainIns pickledRadish		{ "pickled\nRadish",		0,	  -50,  50, 50, 0xfffbd4ff };
	mainIns mushroom			{ "mushroom",				-400, -150, 50, 50, 0xbe9b7bff };
	mainIns bellPepper			{ "bell\nPepper",			-300, -150, 50, 50, 0xff6b6bff };
	mainIns eggplant			{ "eggplant",				-200, -150, 50, 50, 0x9600ffff };
	mainIns tomato				{ "tomato",					-100, -150, 50, 50, 0xffb1a3ff };
	mainIns fishcake			{ "fishcake",				0,	  -150, 50, 50, 0xffe4b1ff };

	std::vector<mainIns> mainInStuffs = { ricecake, wheatcake, cheeseRicecake, sweetPotatoRicecake, ingeolmi,
	   									  beakseolgi, songpyeon, greenOnion, onion, cabbage, 
	   									  lettuce, carrot, cucumber, broccoli, pickledRadish, 
	   									  mushroom, bellPepper, eggplant, tomato, fishcake };
	std::vector<mainIns> inBagMainIn = {};
	
	std::vector<mainIns> level1mainIn = { wheatcake, greenOnion, cabbage };
	std::vector<mainIns> level2mainIn = { songpyeon, broccoli, mushroom };
	std::vector<mainIns> level3mainIn = { ricecake, onion, tomato, carrot };
	std::vector<mainIns> level4mainIn = { cheeseRicecake, onion, bellPepper, eggplant };
	std::vector<mainIns> level5mainIn = { pickledRadish, cucumber, carrot, onion, sweetPotatoRicecake };
};