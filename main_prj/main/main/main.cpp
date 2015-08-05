
#include "MessageSystem.h"
#include "MainObj.h"
#include "Abonent1.h"
#include "Abonent2.h"
#include "Thread.h"

using namespace pulsar;

int main( int argc, char* argv[] )
{
	MessageSystem ms;

	Abonent1 abonent1( ms );
	Abonent2 abonent2( ms );

	Thread thrAbonent1( std::thread ( std::ref( abonent1 ) ) );
	Thread thrAbonent2( std::thread ( std::ref( abonent2 ) ) );

	Main mainObj( ms );
	mainObj.run();

	return 0;
}