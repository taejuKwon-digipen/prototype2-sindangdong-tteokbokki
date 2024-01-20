// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#include "setting.h"

using namespace doodle;

// If you add new function, you should add it play.h

//[[noreturn]] void error(const std::string& s) {
//	throw std::runtime_error(s);
//}

void Play::set() {
	/*if (!music.openFromFile("asset/orchestral.ogg"))
	{
		error("Failed to load the music file: asset/orchestral.ogg");
	}

	LoadSound("asset/effect.ogg");

	music.setLoop(true);
	music.play();*/

	create_window("Sindangdong Tteokbokki", windowX, windowY);
	set_rectangle_mode(RectMode::Center);
	set_image_mode(RectMode::Center);
	set_font_size(10);
}

void Play::run()
{
	switch (scene)
	{
	default:
		break;

	case DIGIPENSCREEN:
		screen.DigiPen();
		break;

	case TITLESCREEN:
		screen.title();
		break;

	case HOWTOSCREEN:
		screen.howTo();
		break;

	case RECIPESCREEN:
		screen.recipe();
		recipeTimer--;
		if (recipeTimer < 0) {
			scene = SAUCESCREEN;
			recipeTimer = 200;
		}
		break;

	case COOKINGSCREEN:
		screen.cooking();
		break;

	case SAUCESCREEN:
		screen.sauce();
		break;

	case MAININSCREEN:
		screen.mainIn();
		break;

	case SUBINSCREEN:
		screen.subIn();
		break;

	case STAGECLEAR:
		screen.stageClear();
		break;

	case GAMEOVER:
		screen.over();
		break;

	case GAMEWIN:
		screen.win();
		break;
	}
}

void Play::reset() {
	Sauces.sauceStuffs = { Sauces.gochujang, Sauces.soysauce, Sauces.molasses, Sauces.sugar, Sauces.salt,
						   Sauces.pepper, Sauces.whitePepper, Sauces.curry, Sauces.chiliPowder, Sauces.miwon,
						   Sauces.dasida, Sauces.crushGarlic, Sauces.onionJuice, Sauces.fruiteJuice, Sauces.chunjang,
						   Sauces.oil, Sauces.tomatoSauce, Sauces.creamSauce, Sauces.oysterSauce, Sauces.cookingWine };
	Sauces.inBagSauce = {};

	MainIns.mainInStuffs = { MainIns.ricecake, MainIns.wheatcake, MainIns.cheeseRicecake, MainIns.sweetPotatoRicecake, MainIns.ingeolmi,
							 MainIns.beakseolgi, MainIns.songpyeon, MainIns.greenOnion, MainIns.onion, MainIns.cabbage,
							 MainIns.lettuce, MainIns.carrot, MainIns.cucumber, MainIns.broccoli, MainIns.pickledRadish,
							 MainIns.mushroom, MainIns.bellPepper, MainIns.eggplant, MainIns.tomato, MainIns.fishcake };
	MainIns.inBagMainIn = {};

	Subs.SubIngredients = { Subs.Ace, Subs.Chocolate_Bar, Subs.Cream_Cheese, Subs.Mozzarella_Cheese, Subs.Fried_Vegetables,
							Subs.SPAM, Subs.Raw_Egg, Subs.Fried_Egg, Subs.Broad_Noodle, Subs.Soup_Base,
							Subs.Instant_Noodle, Subs.Ramdong, Subs.Sundae, Subs.Vienna, Subs.Kielbasa,
							Subs.Strawberry, Subs.Rapsberry, Subs.Pear, Subs.Apple, Subs.Bacon };
	Subs.inBagSubs = {};
}

//void Play::LoadSound(const std::string& file_path)
//{
//	SoundBuffers.emplace_back();
//	sf::SoundBuffer& buffer = SoundBuffers.back();
//	if (!buffer.loadFromFile(file_path))
//	{
//		error("Failed to load " + file_path);
//	}
//}
//
//void Play::PlaySound()
//{
//	int       buffer_index = 0;
//	const int random_value = random(0, 100);
//	if (random_value > 90)
//		buffer_index = 2;
//	else if (random_value >= 45)
//		buffer_index = 1;
//	for (auto& sound : Sounds)
//	{
//		if (sound.getStatus() != sf::SoundSource::Playing)
//		{
//			sound.setBuffer(SoundBuffers[buffer_index]);
//			sound.play();
//			return;
//		}
//	}
//	Sounds.emplace_back(SoundBuffers[buffer_index]);
//	Sounds.back().play();
//}
