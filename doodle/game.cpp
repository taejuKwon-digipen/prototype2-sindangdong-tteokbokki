// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#include "setting.h"

void Game::checkScore() {
	using namespace levels;

	switch (screen.level) {
	default:
		break;

	case level1:
		Sauces.checkSauce(Sauces.level1Sauce);
		MainIns.checkMainIn(MainIns.level1mainIn);
		Subs.checkSubIn(Subs.level1Subs);
		break;

	case level2:
		Sauces.checkSauce(Sauces.level2Sauce);
		MainIns.checkMainIn(MainIns.level2mainIn);
		Subs.checkSubIn(Subs.level2Subs);
		break;

	case level3:
		Sauces.checkSauce(Sauces.level3Sauce);
		MainIns.checkMainIn(MainIns.level3mainIn);
		Subs.checkSubIn(Subs.level3Subs);
		break;

	case level4:
		Sauces.checkSauce(Sauces.level4Sauce);
		MainIns.checkMainIn(MainIns.level4mainIn);
		Subs.checkSubIn(Subs.level4Subs);
		break;

	case level5:
		Sauces.checkSauce(Sauces.level5Sauce);
		MainIns.checkMainIn(MainIns.level5mainIn);
		Subs.checkSubIn(Subs.level5Subs);
		break;	
	}
}