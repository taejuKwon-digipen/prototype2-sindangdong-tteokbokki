// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#pragma once

class Sauce
{
public:
	struct sauces {
		int x{ 0 }, y{ 0 }, xSize{ 0 }, ySize{ 0 }, color{ 0 };
		std::string name;

		sauces(std::string nameShow, int x_Location, int y_Location, int x_Size, int y_Size, int colorNumb);
	};

public:
	void runGame();
	void drawPictures();
	void drawBag();
	void drawSauce(sauces saucename);
	void checkSauce(std::vector<sauces> saucename);

public:
	sauces gochujang	{ "gochujang",		-400, 150,  50, 50, 0xFF0000FF };
	sauces soysauce		{ "soy\nsauce",		-300, 150,  50, 50, 0x6b3f3fff };
	sauces molasses		{ "molasses",		-200, 150,  50, 50, 0xffffffff };
	sauces sugar		{ "sugar",			-100, 150,  50, 50, 0xffffffff };
	sauces salt			{ "salt",			0,	  150,  50, 50, 0xffffffff };
	sauces pepper		{ "pepper",			-400, 50,   50, 50, 0x402020ff };
	sauces whitePepper	{ "white\nPepper",	-300, 50,   50, 50, 0xffffffff };
	sauces curry		{ "curry",			-200, 50,   50, 50, 0xdbc43bff };
	sauces chiliPowder	{ "chili\nPowder",	-100, 50,   50, 50, 0xff0000ff };
	sauces miwon		{ "miwon",			0,	  50,   50, 50, 0xffffffff };
	sauces dasida		{ "dasida",			-400, -50,  50, 50, 0xba7024ff };
	sauces crushGarlic	{ "crush\nGarlic",	-300, -50,  50, 50, 0xf4edc3ff };
	sauces onionJuice	{ "onion\nJuice",	-200, -50,  50, 50, 0xe7ffdfff };
	sauces fruiteJuice	{ "fruite\nJuice",	-100, -50,  50, 50, 0xffe7dfff };
	sauces chunjang		{ "chunjang",		0,	  -50,  50, 50, 0x000000ff };
	sauces oil			{ "oil",			-400, -150, 50, 50, 0xfffcdfff };
	sauces tomatoSauce	{ "tomato\nSauce",	-300, -150, 50, 50, 0xec583eff };
	sauces creamSauce	{ "cream\nSauce",	-200, -150, 50, 50, 0xf4e0a2ff };
	sauces oysterSauce	{ "oyster\nSauce",	-100, -150, 50, 50, 0x40390cff };
	sauces cookingWine	{ "cooking\nWine",	0,	  -150, 50, 50, 0xf0e081ff };
	
	std::vector<sauces> sauceStuffs = { gochujang, soysauce, molasses, sugar, salt,
										pepper, whitePepper, curry, chiliPowder, miwon,
										dasida, crushGarlic, onionJuice, fruiteJuice, chunjang,
										oil, tomatoSauce, creamSauce, oysterSauce, cookingWine };
	std::vector<sauces> inBagSauce = {};

	std::vector<sauces> level1Sauce = { gochujang, sugar, salt };
	std::vector<sauces> level2Sauce = { soysauce, molasses, oysterSauce, miwon };
	std::vector<sauces> level3Sauce = { tomatoSauce, creamSauce, sugar, pepper };
	std::vector<sauces> level4Sauce = { creamSauce, cookingWine, whitePepper, crushGarlic };
	std::vector<sauces> level5Sauce = { chunjang, molasses, dasida, oysterSauce, oil };
};