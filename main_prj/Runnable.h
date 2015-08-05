#ifndef __RUNNABLE__
#define __RUNNABLE__

/**************************************************************************\

^^^^^^^^  ^	     ^  ^         ^^^^^^^^  ^^^^^^^^  ^^^^^^^^
^      ^  ^      ^  ^         ^         ^      ^  ^      ^
^^^^^^^^  ^      ^  ^         ^^^^^^^^  ^^^^^^^^  ^^^^^^^^
^         ^      ^  ^                ^  ^      ^  ^   ^
^         ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^      ^  ^      ^

\***************************************************************************/


//	Name Space declaration

namespace pulsar
{
	//Intrface class. Implements NVI (non virtual interface idiom).

	class Runnable {
	public:
		void operator()() {
			run();
		}
	private:
		virtual void run() = 0;
	};

}  // End Name Space: pulsar.

#endif