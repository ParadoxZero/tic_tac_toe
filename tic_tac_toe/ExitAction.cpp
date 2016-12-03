/*
*	Copyright (C) Sidhin S Thomas (sidhin.thomas@gmail.com)
*/


#include "main_menu_events.h"

namespace mm_events {

	bool ExitAction::start() {
		if (getConfirmation())
			return false; // means exit
		return true;
	}

	bool ExitAction::getConfirmation() {
		bool confirm = false;
		ui::MenuItem items[2]; //Creating a list of Menu Items for the Dialog
		items[0].title = "Yes";
		items[0].action = new ConfirmationMenuAction(&confirm);
		items[1].title = "No";
		items[1].action = new DeclineMenuAction(&confirm);
		ui::Menu dialog(window, "Are you sure?", items, 2); //Creating the confirmation dialog
		dialog.createMenu();
		return confirm;
	}

} //namespace mm_events
