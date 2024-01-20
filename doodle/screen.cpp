// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#include "setting.h"

using namespace doodle;
using namespace std;

// You can draw screen here
// If you add new function, you should add it in screen.h and play.cpp

constexpr int getnumber(int number) {
	return number;
}

void Screen::DigiPen()
{
	try {
		clear_background(255);
		static const Image DigiPenLogo{ "asset/digipen_black.jpg" };
		static const Image copyRight{ "asset/copyrightMessage.jpg" };
		draw_image(DigiPenLogo, getnumber(0), 0, 650, 200);
		draw_image(copyRight, 0, -250, 650, 30);
		logoTimer--;
		if (logoTimer < 0)
			playgame.scene = TITLESCREEN;
	}
	catch (const exception& e)
	{
		cerr << e.what() << '\n';
	}
}

void Screen::title()
{
	drawBG();
	static const Image title{ "asset/title.png" };
	draw_image(title, 0, 100, 900, 400);

	push_settings();
	set_fill_color(0);
	set_font_size(20);
	draw_text("Created by Team Sindangdong Tteokbokki", -250, -150);
	
	set_fill_color(255);
	draw_rectangle(buttonx, button1y, buttonxSize, buttonySize);
	draw_rectangle(buttonx, button2y, buttonxSize, buttonySize);
	draw_rectangle(buttonx, button3y, buttonxSize, buttonySize);
	draw_rectangle(buttonx, button4y, buttonxSize, buttonySize);
	draw_rectangle(buttonx, button5y, buttonxSize, buttonySize);
	draw_rectangle(startbuttonx, startbuttony, startbuttonxSize, startbuttonySize);

	set_fill_color(0);
	draw_text("START", startbuttonx - 45, startbuttony - 20);
	draw_text("1", buttonx - 5, button1y - 18);
	draw_text("2", buttonx - 5, button2y - 18);
	draw_text("3", buttonx - 5, button3y - 18);
	draw_text("4", buttonx - 5, button4y - 18);
	draw_text("5", buttonx - 5, button5y - 18);

	set_font_size(10);
	draw_text("If you played previous game, press O key to load your money", 200, -320);

	if (MouseIsPressed && get_mouse_x() >= buttonx - buttonxSize / 2 && get_mouse_x() <= buttonx + buttonxSize / 2) {
		if (get_mouse_y() >= button1y - buttonySize / 2 && get_mouse_y() <= button1y + buttonySize / 2) {
			level = level1;
		}
		else if (get_mouse_y() >= button2y - buttonySize / 2 && get_mouse_y() <= button2y + buttonySize / 2) {
			level = level2;
		}
		else if (get_mouse_y() >= button3y - buttonySize / 2 && get_mouse_y() <= button3y + buttonySize / 2) {
			level = level3;
		}
		else if (get_mouse_y() >= button4y - buttonySize / 2 && get_mouse_y() <= button4y + buttonySize / 2) {
			level = level4;
		}
		else if (get_mouse_y() >= button5y - buttonySize / 2 && get_mouse_y() <= button5y + buttonySize / 2) {
			level = level5;
		}
	}

	pop_settings();
}

void Screen::howTo()
{
	drawBG();

	push_settings();
	set_font_size(36);
	draw_text("How To Play?", -130, 200);
	set_font_size(24);
	draw_text("Press Enter to start!", -140, 100);
	set_fill_color(HexColor(0xdddac7ff));
	draw_rectangle(0, -100, 900, 350);
	set_fill_color(0);
	set_font_size(16);
	draw_text(" When you start the game, you can see the recipes for each level of tteokbokki. \n\n There are three steps to select ingredients before cooking. \n\n     1. Sauces   2. Main Ingredients   3. Sub Ingredients \n\n You can memorize recipes for each level and cook with the right ingredients. \n\n Every time you choose the right ingredient, you can get 500 won. \n\n If you reach 22000 won, you can win!", -430, -15);
	pop_settings();
}

void Screen::cooking()
{
	drawBG();

	static const Image cookButton{ "asset/cook.png" };
	static const Image cookingList {"asset/cookingList.png"};
	static const Image cookingTable{ "asset/cookingTable.png" };

	map <int, string> m;

	m[50] = "Sub";
	m[150] = "Main";
	m[250] = "Sauce";

	map <int, string>::iterator iter;

	push_settings();
	int cookingbuttonx{ 300 }, cookingbuttony{ 230 }, cookingbuttonxSize{ 200 }, cookingbuttonySize{ 200 };
	draw_image(cookButton, cookingbuttonx, cookingbuttony, cookingbuttonxSize, cookingbuttonySize);

	set_fill_color(HexColor(0xdddac7ff));
	draw_rectangle(-150, 250, 550, 100);
	draw_rectangle(-150, 150, 550, 100);
	draw_rectangle(-150, 50, 550, 100);

	for (iter = m.begin(); iter != m.end(); iter++) {
		draw_text(iter->second, -400, iter->first);
	}

	draw_image(cookingTable, -157, -150, 565, 300);
	draw_image(cookingList, 300, -100, 200, 400);

	set_font_size(11);

	
	for (int i = 0; i < Sauces.inBagSauce.size(); i++) {
		set_fill_color(HexColor(Sauces.inBagSauce[i].color));
		int sauceXlocation = -300 + i * 80;
		int sauceYlocaiton = 270;
		if (sauceXlocation > 50) {
			sauceXlocation += -400;
			sauceYlocaiton = 230;
		}

		draw_text(Sauces.inBagSauce[i].name, sauceXlocation, sauceYlocaiton);
	}

	for (int i = 0; i < MainIns.inBagMainIn.size(); i++) {
		set_fill_color(HexColor(MainIns.inBagMainIn[i].color));
		int mainInXlocation = -300 + i * 80;
		int mainInYlocaiton = 170;
		if (mainInXlocation > 50) {
			mainInXlocation += -400;
			mainInYlocaiton = 130;
		}
		draw_text(MainIns.inBagMainIn[i].name, mainInXlocation, mainInYlocaiton);
	}

	for (int i = 0; i < Subs.inBagSubs.size(); i++) {
		set_fill_color(HexColor(Subs.inBagSubs[i].color));
		int subInXlocation = -300 + i * 80;
		int subInYlocation = 70;
		if (subInXlocation > 50) {
			subInXlocation += -400;
			subInYlocation = 30;
		}
		draw_text(Subs.inBagSubs[i].name, subInXlocation, subInYlocation);
	}


	if (MouseIsPressed) {
		if (get_mouse_x() >= cookingbuttonx - cookingbuttonxSize / 2 && get_mouse_x() <= cookingbuttonx + cookingbuttonxSize / 2 &&
			get_mouse_y() >= cookingbuttony - cookingbuttonySize / 2 && get_mouse_y() <= cookingbuttony + cookingbuttonySize / 2) {
			Games.checkScore();
			playgame.scene = STAGECLEAR;
		}
	}

	pop_settings();
}

void Screen::sauce()
{
	drawBG();
	Sauces.runGame();
	push_settings();
	set_fill_color(0);
	draw_text("Press Enter to choose Main Ingredient!", 0, -300);
	pop_settings();
}

void Screen::mainIn()
{
	drawBG();
	MainIns.runGame();
	push_settings();
	set_fill_color(0);
	draw_text("Press Enter to choose Sub-Ingredient!", 0, -300);
	pop_settings();
}

void Screen::subIn()
{
	drawBG();
	Subs.runGame();
	push_settings();
	set_fill_color(0);
	draw_text("Press Enter to go to kitchen!", 100, -300);
	pop_settings();
}

void Screen::stageClear()
{
	static const Image sdTB1{ "asset/sindangdong.png" };
	static const Image ryTB1{ "asset/royal.png" };
	static const Image rsTB1{ "asset/rose.png" };
	static const Image cnTB1{ "asset/carbonara.png" };
	static const Image jjTB1{ "asset/jajang.png" };
	static const Image money("asset/money.png");

	drawBG();
	push_settings();
	set_font_size(36);
	set_fill_color(HexColor(0x45a965ff));

	draw_text("STAGE CLEAR!", -150, 200);

	switch (level) {
	default: break;

	case level1:
		draw_image(sdTB1, 0, 30, 300, 300);
		break;

	case level2:
		draw_image(ryTB1, 0, 30, 300, 300);
		break;

	case level3:
		draw_image(rsTB1, 0, 30, 300, 300);
		break;

	case level4:
		draw_image(cnTB1, 0, 30, 300, 300);
		break;

	case level5:
		draw_image(jjTB1, 0, 30, 300, 300);
		break;
	}
	pop_settings();
	timer--;

	string moneyShows;
	moneyShows = to_string(Games.money);

	set_font_size(30);
	if (timer < 0) {
		draw_image(money, 0, -200, 500, 400);
		draw_text("Current Money: " + moneyShows, -170, -200);
	}

	draw_rectangle(clearRectX, clearRectY, clearRectXsize, clearRectYsize);
	set_font_size(15);
	draw_text("Next Stage", min_x + 10, clearRectY - 15);

	if (MouseIsPressed) {
		if (get_mouse_x() >= min_x && get_mouse_x() <= max_x && get_mouse_y() >= min_y && get_mouse_y() <= max_y) {
			level++;
			timer = 100;
			playgame.reset();
			playgame.scene = RECIPESCREEN;
			if (level == 16) {
				if (Games.money >= 22000) {
					playgame.scene = GAMEWIN;
				}
				else {
					playgame.scene = GAMEOVER;
				}
			}
		}
	}
}

void Screen::over()
{
	static const Image failedTteokbokki{"asset/fail.png"};
	drawBG();
	push_settings();
	set_font_size(36);
	set_fill_color(255, 0, 0);
	draw_image(failedTteokbokki, 0, 50, 400, 400);
	draw_text("GAME OVER", -130, 0);
	pop_settings();

	int RectX{ 0 }, RectY{ -200 }, RectXSize{ 150 }, RectYSize{ 80 };

	int minX = RectX - RectXSize / 2;
	int minY = RectY - RectYSize / 2;
	int maxX = RectX + RectXSize / 2;
	int maxY = RectY + RectYSize / 2;

	set_font_size(20);
	draw_rectangle(RectX, RectY, RectXSize, RectYSize);
	draw_text("Replay?", RectX-47, RectY - 20);

	if (MouseIsPressed) {
		if (get_mouse_x() >= minX && get_mouse_x() <= maxX && get_mouse_y() >= minY && get_mouse_y() <= maxY) {
			playgame.reset();
			level = level1;
			playgame.scene = TITLESCREEN;
		}
	}
}

void Screen::win() {
	static const Image sdTB{"asset/sindangdong.png"};
	static const Image ryTB{ "asset/royal.png" };
	static const Image rsTB{ "asset/rose.png" };
	static const Image cnTB{ "asset/carbonara.png" };
	static const Image jjTB{ "asset/jajang.png" };

	drawBG();
	

	int RectX{ 0 }, RectY{ -200 }, RectXSize{ 150 }, RectYSize{ 80 };

	draw_image(sdTB, 0, 150, 200, 200);
	draw_image(ryTB, -150, 30, 200, 200);
	draw_image(rsTB, 150, 30, 200, 200);
	draw_image(cnTB, -110, -150, 200, 200);
	draw_image(jjTB, 110, -150, 200, 200);

	int minX = RectX - RectXSize / 2;
	int minY = RectY - RectYSize / 2;
	int maxX = RectX + RectXSize / 2;
	int maxY = RectY + RectYSize / 2;

	set_font_size(50);
	set_fill_color(HexColor(0x45a965ff));
	draw_text("win", -50, -65);

	set_fill_color(255);
	set_font_size(20);
	draw_rectangle(RectX, RectY, RectXSize, RectYSize);
	draw_text("Replay?", RectX - 47, RectY - 20);

	push_settings();
	set_fill_color(0);
	set_font_size(10);
	draw_text("If you want to save your money, press S key to save your money", 185, -320);
	pop_settings();

	if (MouseIsPressed) {
		if (get_mouse_x() >= minX && get_mouse_x() <= maxX && get_mouse_y() >= minY && get_mouse_y() <= maxY) {
			playgame.reset();
			playgame.scene = TITLESCREEN;
		}
	}
}

void Screen::recipe() {
	using namespace levels;

	static const Image level1Recipe{ "asset/level1Recipe.png" };
	static const Image level2Recipe{ "asset/level2Recipe.jpg" };
	static const Image level3Recipe{ "asset/level3Recipe.jpg" };
	static const Image level4Recipe{ "asset/level4Recipe.jpg" };
	static const Image level5Recipe{ "asset/level5Recipe.jpg" };

	drawBG();

	push_settings();
	set_font_size(36);

	switch (level) {
		case level1:
			draw_text("Level1 recipe", -140, 250);
			draw_image(level1Recipe, 0, -30, 380, 520);
			break;

		case level2:
			draw_text("Level2 recipe", -140, 250);
			draw_image(level2Recipe, 0, -30, 380, 520);
			break;

		case level3:
			draw_text("Level3 recipe", -140, 250);
			draw_image(level3Recipe, 0, -30, 380, 520);
			break;

		case level4:
			draw_text("Level4 recipe", -140, 250);
			draw_image(level4Recipe, 0, -30, 380, 520);
			break;

		case level5:
			draw_text("Level5 recipe", -140, 250);
			draw_image(level5Recipe, 0, -30, 380, 520);
			break;
	}

	pop_settings();
}

void Screen::drawBG() {
	static const Image Background{ "asset/background.png" };
	draw_image(Background, 0, 0, windowX, windowY);
}