#ifndef __MSG_ECHO_ABONENT2__
#define __MSG_ECHO_ABONENT2__

#include <string>
#include <iostream>
#include "MsgToAbonent2.h"
#include "Abonent2.h"

namespace pulsar
{
	class MsgEchoAbonent2 : public MsgToAbonent2
	{
	public:
		MsgEchoAbonent2( Address from, Address to, std::string message )
			: MsgToAbonent2( from, to ), message( message ) {}
		~MsgEchoAbonent2() {
			std::cout << "~MsgEchoAbonent2() is called." << "\n";
		}
	
	private:
		virtual void exec( Abonent2& abonent2 ) {
			abonent2.EchoFromAbonent2( message );
		}

	private:
		std::string message;

	};

}


#endif