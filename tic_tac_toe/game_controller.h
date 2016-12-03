/*
*	Copyright (C) Sidhin S Thomas (sidhin.thomas@gmail.com)
*
*	These are the main classes that will be used to control the game,
*	GUI, gameboard, music etc.
*/


#ifndef SS_GAME_CONTROLLER
#define SS_GAME_CONTROLLER


#include "SFML\Graphics.hpp"


namespace game {

	/*
	==============================================================
						Controller Classses
	==============================================================
	*/

	/*	The base class where the game will begin and end */
	class GameMaster {
	public:
		/* Will point to the only instance of gameMaster */
		static GameMaster *game_master;

		/* Use this method to get or create the gameMaster */
		static GameMaster* getGameMaster(sf::RenderWindow*);
		
		int run(); //ahem... does as the name says

	private:
		sf::RenderWindow *window;
		GameMaster(sf::RenderWindow *);

	}; //GameMaster

	/*	Who will be responsible for the music and sound*/
	class SoundMaster {

	};

	//===========================================================

	class GameBoard{

	};




} // namespace game


#endif // !SS_GAME_CONTROLLER

