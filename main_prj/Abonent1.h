#ifndef __ABONENT1__
#define __ABONENT1__

#include <iostream>
#include <memory>
#include "MessageSystem.h"
#include "Runnable.h"
#include "Address.h"
#include "Singleton.h"
#include "MsgEchoAbonent2.h"
#include "TimeHelper.h"

namespace pulsar
{
	class Abonent1 : public Abonent, public Runnable, public Singleton<Abonent1>	{
	public:
		Abonent1( MessageSystem& ms ) 
			: Singleton<Abonent1>( *this ), ms( ms ) {
			
			metaClass = &classInstance;
			ms.addService( *this );
		}

		~Abonent1() {};

		Address getAddress() const {
			return address;
		}

	private:
		
		Address address;
		MessageSystem& ms;

		void run() {
			while ( true ) {

				//std::cout << "Msg from thread: " << std::this_thread::get_id() << "\n";
				sendMessage();
				ms.execForAbonent( *this );
				TimeHelper::sleep( 10 );
			}
		}

		void sendMessage() {

			Address from = getAddress();
			Address to = ms.getAddressService().getAddress( Abonent2::classInstance.getClassName() );
			
			//ms.sendMessage(std::make_shared<MsgEchoAbonent2>(from, to, "Hello, Abonent 2!"));
		}

		Abonent1( const Abonent1& rhr ) = delete;
		Abonent1& operator=( const Abonent1& rhr ) = delete;

	public:
		static	MetaClass	classInstance;

	};

}  // End Name Space: pulsar


#endif