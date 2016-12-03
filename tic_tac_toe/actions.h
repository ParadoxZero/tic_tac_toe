/*
*	Copyright (C) 2016 SIDHIN S THOMAS (sidhin.thomas@gmail.com)
*
*	Collection of Structures that will facilitate interface for actions.
*	related to Gui and Menu structures.
*/


#ifndef SS_EVENTS
#define SS_EVENTS


/* Headers */


namespace events {

	/* Simple abstract class interface to implement Actions */
	class Action {
	public:
		/* The function that will be called by the menu
		   Depending on the return value of start() the menu will close
			- If start() return true : menu will not close
			- If start() return false: menu will close

			usefull when you need to implement a feature after which it should not return to the menu.
			eg. Back/Exit/Game Mode etc.
		*/
		virtual bool start() = 0;
	};

} // namespace events


#endif // !SS_EVENTS