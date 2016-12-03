/*
*	Copyright (C) 2016 SIDHIN S THOMAS (sidhin.thomas@gmail.com)
*/


#ifndef SS_EVENTS
#define SS_EVENTS


/* Headers */


namespace events {

	/* Simple abstract class interface to implement Actions */
	class Action {
	public:
		/* The function that will be called by the menu */
		virtual void start() = 0;
	};

} // namespace events


#endif // !SS_EVENTS