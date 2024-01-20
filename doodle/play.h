// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#pragma once
#include <SFML/Audio.hpp>

class Play
{
public:
    void set();
    void run();
    void reset();
    void LoadSound(const std::string& file_path);
    void PlaySound();

public:
    /*std::vector<sf::SoundBuffer> SoundBuffers{};
    std::vector<sf::Sound>       Sounds{};
    sf::Music                    music;*/
    int scene = DIGIPENSCREEN;
    int recipeTimer = 200;
};