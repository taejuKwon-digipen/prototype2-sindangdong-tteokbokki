// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#include "setting.h"

using namespace doodle;

Sauce::sauces::sauces(std::string nameShow, int x_Location, int y_Location, int x_Size, int y_Size, int colorNumb) : name{ nameShow }, x { x_Location }, y{ y_Location }, xSize{ x_Size }, ySize{ y_Size }, color{ colorNumb }
{};

void Sauce::runGame() {
	push_settings();
	set_font_size(36);
	draw_text("Sauces", -80, 250);
	pop_settings();
	
	for (int i = 0; i < sauceStuffs.size(); i++) {
		drawSauce(sauceStuffs[i]);
	}
	drawPictures();
	drawBag();
}

void Sauce::drawSauce(sauces saucename) {
	push_settings();
	set_font_size(12);
	set_fill_color(HexColor(saucename.color));
	draw_rectangle(saucename.x, saucename.y, saucename.xSize, saucename.ySize);
	draw_text(saucename.name, saucename.x - saucename.xSize / 2, saucename.y - 50);
	pop_settings();
}

void Sauce::drawBag() {
	int undoX{ 160 }, undoY{ -190 }, undoXsize{ 80 }, undoYsize{ 40 };
	set_font_size(20);
	draw_rectangle(300, 0, 400, 450);
	draw_rectangle(undoX, undoY, undoXsize, undoYsize);
	draw_text("What's in your Bag!", 170, 170);
	draw_text("UNDO", undoX - 34, undoY - 18);

	double min_x = undoX - undoXsize / 2;
	double min_y = undoY - undoYsize / 2;
	
	double max_x = undoX + undoXsize / 2;
	double max_y = undoY + undoYsize / 2;

	if (!inBagSauce.empty()) {
		for (int i = 0; i < (int)inBagSauce.size(); i++) {
			push_settings();
			set_font_size(13);
			set_fill_color(HexColor(inBagSauce[i].color));
			int inBagSauceText_x = 180;
			int inBagSauceText_y = 155 - i * 35;
			if (inBagSauceText_y < -170) {
				inBagSauceText_x = 310;
				inBagSauceText_y += 350;
			}
			draw_text(inBagSauce[i].name, inBagSauceText_x, inBagSauceText_y);
			pop_settings();
		}
	}

	for (int j = (int)inBagSauce.size() - 1; j >= 0; --j) {
		if (MouseIsPressed) {
			if (get_mouse_x() >= min_x && get_mouse_x() <= max_x && get_mouse_y() >= min_y && get_mouse_y() <= max_y) {
				sauceStuffs.push_back(*(inBagSauce.begin() + j));
				inBagSauce.erase(inBagSauce.begin() + j);
			}
		}
	}
}

void Sauce::checkSauce(std::vector<sauces> saucename) {
	for (int i = 0; i < (int)saucename.size(); i++) {
		for (int j = 0; j < (int)inBagSauce.size(); j++) {
			if (saucename[i].name == inBagSauce[j].name) {
				Games.money += 500;
			}
		}
	}
}

void Sauce::drawPictures() {
	const Image Sauce0{ "asset/sauce/Gochujang.png" };
	const Image Sauce1{ "asset/sauce/SoySauce.png" };
	const Image Sauce2{ "asset/sauce/molasses.png" };
	const Image Sauce3{ "asset/sauce/Sugar.png" };
	const Image Sauce4{ "asset/sauce/Salt.png" };
	const Image Sauce5{ "asset/sauce/Pepper.png" };
	const Image Sauce6{ "asset/sauce/Whitepepper.png" };
	const Image Sauce7{ "asset/sauce/Curry.png" };
	const Image Sauce8{ "asset/sauce/Chillipowder.png" };
	const Image Sauce9{ "asset/sauce/Miwon.png" };
	const Image Sauce10{ "asset/sauce/dasida.png" };
	const Image Sauce11{ "asset/sauce/crushgarlic.png" };
	const Image Sauce12{ "asset/sauce/onionjuice.png" };
	const Image Sauce13{ "asset/sauce/fruitjuice.png" };
	const Image Sauce14{ "asset/sauce/chunjang.png" };
	const Image Sauce15{ "asset/sauce/oil.png" };
	const Image Sauce16{ "asset/sauce/tomatoSauce.png" };
	const Image Sauce17{ "asset/sauce/creamSauce.png" };
	const Image Sauce18{ "asset/sauce/oysterSauce.png" };
	const Image Sauce19{ "asset/sauce/cookingwine.png" };

	draw_image(Sauce0,	sauceStuffs[0].x,  sauceStuffs[0].y,  sauceStuffs[0].xSize,  sauceStuffs[0].ySize);
	draw_image(Sauce1,	sauceStuffs[1].x,  sauceStuffs[1].y,  sauceStuffs[1].xSize,  sauceStuffs[1].ySize);
	draw_image(Sauce2,	sauceStuffs[2].x,  sauceStuffs[2].y,  sauceStuffs[2].xSize,  sauceStuffs[2].ySize);
	draw_image(Sauce3,	sauceStuffs[3].x,  sauceStuffs[3].y,  sauceStuffs[3].xSize,  sauceStuffs[3].ySize);
	draw_image(Sauce4,	sauceStuffs[4].x,  sauceStuffs[4].y,  sauceStuffs[4].xSize,  sauceStuffs[4].ySize);
	draw_image(Sauce5,	sauceStuffs[5].x,  sauceStuffs[5].y,  sauceStuffs[5].xSize,  sauceStuffs[5].ySize);
	draw_image(Sauce6,	sauceStuffs[6].x,  sauceStuffs[6].y,  sauceStuffs[6].xSize,  sauceStuffs[6].ySize);
	draw_image(Sauce7,	sauceStuffs[7].x,  sauceStuffs[7].y,  sauceStuffs[7].xSize,  sauceStuffs[7].ySize);
	draw_image(Sauce8,	sauceStuffs[8].x,  sauceStuffs[8].y,  sauceStuffs[8].xSize,  sauceStuffs[8].ySize);
	draw_image(Sauce9,	sauceStuffs[9].x,  sauceStuffs[9].y,  sauceStuffs[9].xSize,  sauceStuffs[9].ySize);
	draw_image(Sauce10, sauceStuffs[10].x, sauceStuffs[10].y, sauceStuffs[10].xSize, sauceStuffs[10].ySize);
	draw_image(Sauce11, sauceStuffs[11].x, sauceStuffs[11].y, sauceStuffs[11].xSize, sauceStuffs[11].ySize);
	draw_image(Sauce12, sauceStuffs[12].x, sauceStuffs[12].y, sauceStuffs[12].xSize, sauceStuffs[12].ySize);
	draw_image(Sauce13, sauceStuffs[13].x, sauceStuffs[13].y, sauceStuffs[13].xSize, sauceStuffs[13].ySize);
	draw_image(Sauce14, sauceStuffs[14].x, sauceStuffs[14].y, sauceStuffs[14].xSize, sauceStuffs[14].ySize);
	draw_image(Sauce15, sauceStuffs[15].x, sauceStuffs[15].y, sauceStuffs[15].xSize, sauceStuffs[15].ySize);
	draw_image(Sauce16, sauceStuffs[16].x, sauceStuffs[16].y, sauceStuffs[16].xSize, sauceStuffs[16].ySize);
	draw_image(Sauce17, sauceStuffs[17].x, sauceStuffs[17].y, sauceStuffs[17].xSize, sauceStuffs[17].ySize);
	draw_image(Sauce18, sauceStuffs[18].x, sauceStuffs[18].y, sauceStuffs[18].xSize, sauceStuffs[18].ySize);
	draw_image(Sauce19, sauceStuffs[19].x, sauceStuffs[19].y, sauceStuffs[19].xSize, sauceStuffs[19].ySize);
}