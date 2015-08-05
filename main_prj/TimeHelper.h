#ifndef __TIMEHELPER__
#define __TIMEHELPER__

#include <thread>
#include <chrono>

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
	struct TimeHelper{
		static void sleep(int timeMs) {
			std::this_thread::sleep_for(std::chrono::milliseconds(timeMs));
		}
	};

} // End Name Space: pulsar

#endif