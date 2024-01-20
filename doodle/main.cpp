// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#include "setting.h"

using namespace doodle;

int main(void)
try{
    playgame.set();

    while (!is_window_closed())
    {
        update_window();
        playgame.run();
    }
    return 0;
}
catch (const std::exception& e)
{
    std::cerr << "Error : " << e.what() << '\n';
    return -1;
}


void on_key_released(KeyboardButtons button)
{
    if (button == KeyboardButtons::Escape) 
        close_window();

    if (button == KeyboardButtons::O) {
        if (playgame.scene == TITLESCREEN) {
            std::ifstream readFile;
            readFile.open("money.txt");

            if (readFile.is_open()) {
                while (!readFile.eof()) {
                    std::string strMoney;
                    getline(readFile, strMoney);
                    Games.money = stoi(strMoney);
                    std::cout << Games.money << std::endl;
                }
                readFile.close();
            }
        }
    }

    if (button == KeyboardButtons::S) {
        if (playgame.scene == GAMEWIN) {
            std::ofstream writeFile;
            writeFile.open("money.txt");

            std::string moneyPut;
            moneyPut = std::to_string(Games.money);
            writeFile.write(moneyPut.c_str(), moneyPut.size());
            std::cout << moneyPut << std::endl;

            writeFile.close();
        }
    }
    
    if (button == KeyboardButtons::E)
        playgame.scene++;

    if (button == KeyboardButtons::R)
        playgame.scene--;

    if (button == KeyboardButtons::Enter) {
        if (playgame.scene == HOWTOSCREEN) {
            playgame.scene = RECIPESCREEN;
        }
        else if (playgame.scene == SAUCESCREEN) {
            playgame.scene = MAININSCREEN;
        }
        else if (playgame.scene == MAININSCREEN) {
            playgame.scene = SUBINSCREEN;
        }
        else if (playgame.scene == SUBINSCREEN) {
            playgame.scene = COOKINGSCREEN;
        }
    }
}

void on_mouse_pressed(MouseButtons button)
{
    if (button == MouseButtons::Left) {
        switch (playgame.scene) {
        default: break;

        case TITLESCREEN:
            if (get_mouse_x() >= screen.startbuttonx - screen.startbuttonxSize / 2 && get_mouse_x() <= screen.startbuttonx + screen.startbuttonxSize / 2 &&
                get_mouse_y() >= screen.startbuttony - screen.startbuttonySize / 2 && get_mouse_y() <= screen.startbuttony + screen.startbuttonySize / 2) {
                playgame.scene = HOWTOSCREEN;
            }

            break;

        case SAUCESCREEN:
            for (int i = static_cast<int>(Sauces.sauceStuffs.size()) - 1; i >= 0; --i)
            {
                double Saucemin_x = Sauces.sauceStuffs[i].x - Sauces.sauceStuffs[i].xSize / 2;
                double Saucemin_y = Sauces.sauceStuffs[i].y - Sauces.sauceStuffs[i].ySize / 2;
                double Saucemax_x = Sauces.sauceStuffs[i].x + Sauces.sauceStuffs[i].xSize / 2;
                double Saucemax_y = Sauces.sauceStuffs[i].y + Sauces.sauceStuffs[i].ySize / 2;

                if (get_mouse_x() >= Saucemin_x && get_mouse_x() <= Saucemax_x && get_mouse_y() >= Saucemin_y && get_mouse_y() <= Saucemax_y) {
                    Sauces.inBagSauce.push_back(*(Sauces.sauceStuffs.begin() + i));
                    break;
                }
            }
            break;

        case MAININSCREEN:
            for (int i = static_cast<int>(MainIns.mainInStuffs.size()) - 1; i >= 0; --i)
            {
                double Mainmin_x = MainIns.mainInStuffs[i].x - MainIns.mainInStuffs[i].xSize / 2;
                double Mainmin_y = MainIns.mainInStuffs[i].y - MainIns.mainInStuffs[i].ySize / 2;
                double Mainmax_x = MainIns.mainInStuffs[i].x + MainIns.mainInStuffs[i].xSize / 2;
                double Mainmax_y = MainIns.mainInStuffs[i].y + MainIns.mainInStuffs[i].ySize / 2;

                if (get_mouse_x() >= Mainmin_x && get_mouse_x() <= Mainmax_x && get_mouse_y() >= Mainmin_y && get_mouse_y() <= Mainmax_y)
                {
                    MainIns.inBagMainIn.push_back(*(MainIns.mainInStuffs.begin() + i));
                    break;
                }
            }
            break;

        case SUBINSCREEN:
            int SubIn_size = static_cast<int>(Subs.SubIngredients.size());
            for (int i = SubIn_size - 1; i >= 0; --i)
            {
                double Submin_x = Subs.SubIngredients[i].posx - Subs.SubIngredients[i].xSize / 2;
                double Submin_y = Subs.SubIngredients[i].posy - Subs.SubIngredients[i].ySize / 2;
                double Submax_x = Subs.SubIngredients[i].posx + Subs.SubIngredients[i].xSize / 2;
                double Submax_y = Subs.SubIngredients[i].posy + Subs.SubIngredients[i].ySize / 2;

                if (get_mouse_x() >= Submin_x && get_mouse_x() <= Submax_x && get_mouse_y() >= Submin_y && get_mouse_y() <= Submax_y)
                {
                    Subs.inBagSubs.push_back(*(Subs.SubIngredients.begin() + i));
                    break;
                }
            }
            break;
        }
    }
}