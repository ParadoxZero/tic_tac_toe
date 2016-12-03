/*
*	Copyright (C) 2016 SIDHIN S THOMAS (sidhin.thomas@gmail.com)
*/


#ifndef SS_MAIN_MENU_EVENTS
#define SS_MAIN_MENU_EVENTS


/* Headers */
#include "ui.h"

namespace mm_events {

	class StartAction : public events::Action {
		void start() {

		}
	};

	class OptionsAction : public events::Action {
		void start() {

		}
	};

	class ExitAction : public events::Action {
		void start() {
			exit(0);
		}

	};


} // namespace events


#endif // !SS_MAIN_MENU_EVENTS
