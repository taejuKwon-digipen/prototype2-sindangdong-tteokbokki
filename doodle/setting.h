// Name       : Sindangdong Tteokbokki (Taeju Kwon, Jihyeon Song, Geonhwi Sim)
// Assignment : Game Prototype2
// Course     : GAM100 + CS120
// Term & Year: Fall 2020

#pragma once

// you can add all header files and global variables here

#include <vector>
#include <doodle/doodle.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>
#include <doodle/drawing.hpp>
#include <doodle/environment.hpp>
#include <doodle/input.hpp>
#include <doodle/random.hpp>
#include <doodle/window.hpp>
#include <doodle/doodle.hpp>
#include <map>
#include <fstream>
#include <istream>
#include <ostream>
#include <filesystem>

#include "sauce.h"
#include "game.h"
#include "enum.h"
#include "screen.h"
#include "play.h"
#include "mainIn.h"
#include "SubI.h"

constexpr int windowX = 1200;
constexpr int windowY = 700;

inline Game Games;
inline Play playgame;
inline Screen screen;
inline Sauce Sauces;
inline MainIn MainIns;
inline SubI Subs;