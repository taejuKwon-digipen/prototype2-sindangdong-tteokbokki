// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#include "setting.h"

using namespace doodle;

void SubI::runGame()
{
    push_settings();
    set_font_size(36);
    draw_text("Sub Ingredients", -200, 250);
    pop_settings();

    for (int i = 0; i < SubIngredients.size(); i++) {
        drawSubs(SubIngredients[i]);
    }
    drawPictures();
    drawBag();
}

void SubI::drawSubs(Subs subname)
{
    push_settings();
    set_font_size(12);
    set_fill_color(HexColor(subname.color));
    draw_rectangle(subname.posx, subname.posy, subname.xSize, subname.ySize);
    draw_text(subname.name , subname.posx - subname.xSize /2, subname.posy - 50);
    pop_settings();
}

void SubI::drawBag ()
{
    int undoX{ 160 }, undoY{ -190 }, undoXsize{ 80 }, undoYsize{ 40 };
    set_font_size(20);
    draw_rectangle(300, 0, 400, 450);
    draw_rectangle(undoX, undoY, undoXsize, undoYsize);
    draw_text("What's in your Bag!", 170, 170);
    draw_text("UNDO", undoX - 34, undoY-18);

    double min_x = undoX - undoXsize / 2;
    double min_y = undoY - undoYsize / 2;

    double max_x = undoX + undoXsize / 2;
    double max_y = undoY + undoYsize / 2;

    if (!inBagSubs.empty())
    {
        for (int i = 0; i < (int)inBagSubs.size(); i++)
        {
            push_settings();
            set_font_size(13);
            set_fill_color(HexColor(inBagSubs[i].color));
            int inBagSubText_x = 180;
            int inBagSubText_y = 155 - i * 35;

            if (inBagSubText_y < -170)
            {
                inBagSubText_x = 310;
                inBagSubText_y += 350;
            }

            draw_text(inBagSubs[i].name, inBagSubText_x, inBagSubText_y);
            pop_settings();
        }
    }

    for (int j = (int)inBagSubs.size() - 1; j >= 0; --j)
    {
        if (MouseIsPressed)
        {
            if (get_mouse_x() >= min_x && get_mouse_x() <= max_x && get_mouse_y() >= min_y && get_mouse_y() <= max_y)
            {
                inBagSubs.erase(inBagSubs.begin() + j);
            }
        }
    }
}

void SubI::checkSubIn(std::vector<Subs> subInname) {
    for (int i = 0; i < (int)subInname.size(); i++) {
        for (int j = 0; j < (int)inBagSubs.size(); j++) {
            if (subInname[i].name == inBagSubs[j].name) {
                Games.money += 500;
            }
        }
    }
}

void SubI::drawPictures() {
    const Image sub0{ "asset/sub/Ace.png" };
    const Image sub1{ "asset/sub/Chocolate_bar.png" };
    const Image sub2{ "asset/sub/CreamCheese.png" };
    const Image sub3{ "asset/sub/Mozzarella_Cheese.png" };
    const Image sub4{ "asset/sub/Fried_Vegetable.png" };
    const Image sub5{ "asset/sub/Spam.png" };
    const Image sub6{ "asset/sub/Raw_Egg.png" };
    const Image sub7{ "asset/sub/Fried_Egg.png" };
    const Image sub8{ "asset/sub/Broad_noodle.png" };
    const Image sub9{ "asset/sub/soup_base.png" };
    const Image sub10{ "asset/sub/Instant_noodle.png" };
    const Image sub11{ "asset/sub/Ramdong.png" };
    const Image sub12{ "asset/sub/Sundae.png" };
    const Image sub13{ "asset/sub/vienna.png" };
    const Image sub14{ "asset/sub/Kielbasa.png" };
    const Image sub15{ "asset/sub/strawberry.png" };
    const Image sub16{ "asset/sub/rapsberry.png" };
    const Image sub17{ "asset/sub/Pear.png" };
    const Image sub18{ "asset/sub/Apple.png" };
    const Image sub19{ "asset/sub/Bacon.png" };

    draw_image(sub0, SubIngredients[0].posx, SubIngredients[0].posy, SubIngredients[0].xSize, SubIngredients[0].ySize);
    draw_image(sub1, SubIngredients[1].posx, SubIngredients[1].posy, SubIngredients[1].xSize, SubIngredients[1].ySize);
    draw_image(sub2, SubIngredients[2].posx, SubIngredients[2].posy, SubIngredients[2].xSize, SubIngredients[2].ySize);
    draw_image(sub3, SubIngredients[3].posx, SubIngredients[3].posy, SubIngredients[3].xSize, SubIngredients[3].ySize);
    draw_image(sub4, SubIngredients[4].posx, SubIngredients[4].posy, SubIngredients[4].xSize, SubIngredients[4].ySize);
    draw_image(sub5, SubIngredients[5].posx, SubIngredients[5].posy, SubIngredients[5].xSize, SubIngredients[5].ySize);
    draw_image(sub6, SubIngredients[6].posx, SubIngredients[6].posy, SubIngredients[6].xSize, SubIngredients[6].ySize);
    draw_image(sub7, SubIngredients[7].posx, SubIngredients[7].posy, SubIngredients[7].xSize, SubIngredients[7].ySize);
    draw_image(sub8, SubIngredients[8].posx, SubIngredients[8].posy, SubIngredients[8].xSize, SubIngredients[8].ySize);
    draw_image(sub9, SubIngredients[9].posx, SubIngredients[9].posy, SubIngredients[9].xSize, SubIngredients[9].ySize);
    draw_image(sub10, SubIngredients[10].posx, SubIngredients[10].posy, SubIngredients[10].xSize, SubIngredients[10].ySize);
    draw_image(sub11, SubIngredients[11].posx, SubIngredients[11].posy, SubIngredients[11].xSize, SubIngredients[11].ySize);
    draw_image(sub12, SubIngredients[12].posx, SubIngredients[12].posy, SubIngredients[12].xSize, SubIngredients[12].ySize);
    draw_image(sub13, SubIngredients[13].posx, SubIngredients[13].posy, SubIngredients[13].xSize, SubIngredients[13].ySize);
    draw_image(sub14, SubIngredients[14].posx, SubIngredients[14].posy, SubIngredients[14].xSize, SubIngredients[14].ySize);
    draw_image(sub15, SubIngredients[15].posx, SubIngredients[15].posy, SubIngredients[15].xSize, SubIngredients[15].ySize);
    draw_image(sub16, SubIngredients[16].posx, SubIngredients[16].posy, SubIngredients[16].xSize, SubIngredients[16].ySize);
    draw_image(sub17, SubIngredients[17].posx, SubIngredients[17].posy, SubIngredients[17].xSize, SubIngredients[17].ySize);
    draw_image(sub18, SubIngredients[18].posx, SubIngredients[18].posy, SubIngredients[18].xSize, SubIngredients[18].ySize);
    draw_image(sub19, SubIngredients[19].posx, SubIngredients[19].posy, SubIngredients[19].xSize, SubIngredients[19].ySize);
}