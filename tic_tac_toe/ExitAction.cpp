/*
*	Copyright (C) Sidhin S Thomas (sidhin.thomas@gmail.com)
*/


#include "main_menu_events.h"

namespace mm_events {

	bool ExitAction::start() {
		if (getConfirmation())
			return false;
		return true;
	}

	bool ExitAction::getConfirmation() {
		ui::MenuItem items[2];
		items[0].title = "Yes";
		items[0].action = new ConfirmationMenuAction(&confirm);
		items[1].title = "No";
		items[1].action = new DeclineMenuAction(&confirm);
		dialog = new ui::Menu(window, "Are you sure?", items, 2);
		dialog->createMenu();
		return confirm;
	}

} //namespace mm_events
