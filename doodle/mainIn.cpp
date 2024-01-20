// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#include "setting.h"

using namespace doodle;

MainIn::mainIns::mainIns(std::string nameShow, int x_Location, int y_Location, int x_Size, int y_Size, int colorNumb) : name{ nameShow }, x{ x_Location }, y{ y_Location }, xSize{ x_Size }, ySize{ y_Size }, color{ colorNumb }
{};

void MainIn::runGame() {
	push_settings();
	set_font_size(36);
	draw_text("Main Ingredients", -200, 250);
	pop_settings();
	
	for (int i = 0; i < mainInStuffs.size(); i++) {
		drawMainIn(mainInStuffs[i]);
	}
	drawPictures();
	drawBag();
}

void MainIn::drawMainIn(mainIns mainInname) {
	push_settings();
	set_font_size(12);
	set_fill_color(HexColor(mainInname.color));
	draw_rectangle(mainInname.x, mainInname.y, mainInname.xSize, mainInname.ySize);
	draw_text(mainInname.name, mainInname.x - mainInname.xSize / 2, mainInname.y - 50);
	pop_settings();
}

void MainIn::drawBag() {
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

	if (!inBagMainIn.empty()) {
		for (int i = 0; i < (int)inBagMainIn.size(); i++) {
			push_settings();
			set_font_size(13);
			set_fill_color(HexColor(inBagMainIn[i].color));
			int inBagMainInText_x = 180;
			int inBagMainInText_y = 155 - i * 35;
			if (inBagMainInText_y < -170) {
				inBagMainInText_x = 310;
				inBagMainInText_y += 350;
			}
			draw_text(inBagMainIn[i].name, inBagMainInText_x, inBagMainInText_y);
			pop_settings();
		}
	}

	for (int j = (int)inBagMainIn.size() - 1; j >= 0; --j) {
		if (MouseIsPressed) 
		{
			if (get_mouse_x() >= min_x && get_mouse_x() <= max_x && get_mouse_y() >= min_y && get_mouse_y() <= max_y) 
			{
				mainInStuffs.push_back(*(inBagMainIn.begin() + j));
				inBagMainIn.erase(inBagMainIn.begin() + j);
			}
		}
	}
}

void MainIn::checkMainIn(std::vector<mainIns> mainInname) {
	for (int i = 0; i < (int)mainInname.size(); i++) {
		for (int j = 0; j < (int)inBagMainIn.size(); j++) {
			if (mainInname[i].name == inBagMainIn[j].name) {
				Games.money += 500;
			}
		}
	}
}

void MainIn::drawPictures() {
	const Image Main0{ "asset/main/ricecake.png" };
	const Image Main1{ "asset/main/wheatcake.png" };
	const Image Main2{ "asset/main/cheesericecake.png" };
	const Image Main3{ "asset/main/sweetpotatoricecke.png" };
	const Image Main4{ "asset/main/ingeolmi.png" };
	const Image Main5{ "asset/main/beakseolgi.png" };
	const Image Main6{ "asset/main/songpyeon.png" };
	const Image Main7{ "asset/main/greenonion.png" };
	const Image Main8{ "asset/main/onion.png" };
	const Image Main9{ "asset/main/cabbage.png" };
	const Image Main10{ "asset/main/lettuce.png" };
	const Image Main11{ "asset/main/carrot.png" };
	const Image Main12{ "asset/main/cucmber.png" };
	const Image Main13{ "asset/main/broccoli.png" };
	const Image Main14{ "asset/main/pickedradish.png" };
	const Image Main15{ "asset/main/mushroom.png" };
	const Image Main16{ "asset/main/bellpepper.png" };
	const Image Main17{ "asset/main/eggplant.png" };
	const Image Main18{ "asset/main/tomato.png" };
	const Image Main19{ "asset/main/fishcake.png" };

	draw_image(Main0, mainInStuffs[0].x, mainInStuffs[0].y, mainInStuffs[0].xSize, mainInStuffs[0].ySize);
	draw_image(Main1, mainInStuffs[1].x, mainInStuffs[1].y, mainInStuffs[1].xSize, mainInStuffs[1].ySize);
	draw_image(Main2, mainInStuffs[2].x, mainInStuffs[2].y, mainInStuffs[2].xSize, mainInStuffs[2].ySize);
	draw_image(Main3, mainInStuffs[3].x, mainInStuffs[3].y, mainInStuffs[3].xSize, mainInStuffs[3].ySize);
	draw_image(Main4, mainInStuffs[4].x, mainInStuffs[4].y, mainInStuffs[4].xSize, mainInStuffs[4].ySize);
	draw_image(Main5, mainInStuffs[5].x, mainInStuffs[5].y, mainInStuffs[5].xSize, mainInStuffs[5].ySize);
	draw_image(Main6, mainInStuffs[6].x, mainInStuffs[6].y, mainInStuffs[6].xSize, mainInStuffs[6].ySize);
	draw_image(Main7, mainInStuffs[7].x, mainInStuffs[7].y, mainInStuffs[7].xSize, mainInStuffs[7].ySize);
	draw_image(Main8, mainInStuffs[8].x, mainInStuffs[8].y, mainInStuffs[8].xSize, mainInStuffs[8].ySize);
	draw_image(Main9, mainInStuffs[9].x, mainInStuffs[9].y, mainInStuffs[9].xSize, mainInStuffs[9].ySize);
	draw_image(Main10, mainInStuffs[10].x, mainInStuffs[10].y, mainInStuffs[10].xSize, mainInStuffs[10].ySize);
	draw_image(Main11, mainInStuffs[11].x, mainInStuffs[11].y, mainInStuffs[11].xSize, mainInStuffs[11].ySize);
	draw_image(Main12, mainInStuffs[12].x, mainInStuffs[12].y, mainInStuffs[12].xSize, mainInStuffs[12].ySize);
	draw_image(Main13, mainInStuffs[13].x, mainInStuffs[13].y, mainInStuffs[13].xSize, mainInStuffs[13].ySize);
	draw_image(Main14, mainInStuffs[14].x, mainInStuffs[14].y, mainInStuffs[14].xSize, mainInStuffs[14].ySize);
	draw_image(Main15, mainInStuffs[15].x, mainInStuffs[15].y, mainInStuffs[15].xSize, mainInStuffs[15].ySize);
	draw_image(Main16, mainInStuffs[16].x, mainInStuffs[16].y, mainInStuffs[16].xSize, mainInStuffs[16].ySize);
	draw_image(Main17, mainInStuffs[17].x, mainInStuffs[17].y, mainInStuffs[17].xSize, mainInStuffs[17].ySize);
	draw_image(Main18, mainInStuffs[18].x, mainInStuffs[18].y, mainInStuffs[18].xSize, mainInStuffs[18].ySize);
	draw_image(Main19, mainInStuffs[19].x, mainInStuffs[19].y, mainInStuffs[19].xSize, mainInStuffs[19].ySize);
}