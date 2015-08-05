#ifndef __ABONENT2__
#define __ABONENT2__

#include <iostream>
#include "Runnable.h"
#include "MessageSystem.h"
#include "Address.h"
#include "Singleton.h"
#include "TimeHelper.h"

namespace pulsar
{
	class Abonent2 : public Abonent, public Runnable, public Singleton<Abonent2>	{
	public:
		Abonent2( MessageSystem& ms ) : Singleton<Abonent2>( *this ), ms( ms ) {
			metaClass = &classInstance;
			ms.addService( *this );
		}

		~Abonent2() {};

		Address getAddress() const {
			return address;
		}

		void EchoFromAbonent2( const std::string& message ) const {
			
			//auto time = std::chrono::high_resolution_clock::now();
			//std::chrono::duration<double, std::milli> elapsed;
			std::cout << "<Abonent   2> Msg : " << message << std::endl;
		}

	private:
		Address address;
		MessageSystem& ms;

		void run() {
			while ( true ) {
				//std::cout << "Msg from thread: " << std::this_thread::get_id() << "\n";
				ms.execForAbonent( *this );
				TimeHelper::sleep( 10 );
			}
		}

		Abonent2( const Abonent2& rhr ) = delete;
		Abonent2& operator=( const Abonent2& rhr ) = delete;

	public:
		static	MetaClass	classInstance;
	
	};

}  // End Name Space: pulsar

#endif