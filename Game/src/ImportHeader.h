#pragma once
#ifdef GAME
#define GAME_API __declspec(dllexport)
#else
#define GAME_API __declspec(dllimport)
#endif
