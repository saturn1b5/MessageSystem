/************************************************************************************

Filename    :   MessageSystem.h
Content     :   
Created     :   July 26, 2015
Authors     :   

Copyright   :   Copyright 2015, All Rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

************************************************************************************/

#ifndef __MESSAGE_SYSTEM__
#define __MESSAGE_SYSTEM__

#include <map>
#include <memory>
#include <iostream>
#include <tbb/tbb.h>
#include "Msg.h"
#include "Address.h"
#include "AddressService.h"

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

class MessageSystem
{
	typedef std::shared_ptr<Msg> MessageType;
	typedef std::map<Address, tbb::concurrent_queue<MessageType>> Messages;
	typedef std::map<Address, tbb::concurrent_queue<MessageType>>::const_iterator Iterator;

public:
	MessageSystem() {}

	void addService( const Abonent& abonent ) {
		addressService.setAddress( abonent );
	}

	void sendMessage(const MessageType& message) {
		
		auto it = messages.find( message->getTo() );
		
		if ( it != messages.end() )
			messages[ it->first ].push( message  );
	}

	void execForAbonent( const Abonent& abonent ) {
		
		MessageType message;

		while ( messages[ abonent.getAddress() ].try_pop( message ) ) {
			if ( message ) {
				message->exec( abonent );

				 std::cout << "Ref count is : " << message.use_count() << "\n";
				std::cout << "Queue size is : " << messages[abonent.getAddress()].unsafe_size() << "\n";

				//messages[abonent.getAddress()].

			}
		}
	}

	AddressService getAddressService() const {
		return addressService;
	}

private:
	Messages messages;
	AddressService addressService;
};

} // End Name Space: pulsar

#endif