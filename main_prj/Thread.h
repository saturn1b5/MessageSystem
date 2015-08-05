#ifndef __THREAD__
#define __THREAD__

#include <thread>
#include <stdexcept>

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
	class Thread
	{
	public:
		explicit Thread( std::thread rthr ) : thr( std::move(rthr) ) {
			if ( !thr.joinable() )
				throw std::logic_error("No thread");
		
		}

		~Thread() {
			thr.join();
		}

	private:
		std::thread thr;
	
	};

}  // End Name Space: pulsar

#endif