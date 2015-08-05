/************************************************************************************

Filename    :   AddressService.h
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
#ifndef __ADDRESS_SERVICE__
#define __ADDRESS_SERVICE__

#include <map>
#include <algorithm>

#include "Address.h"
#include "Abonent.h"

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
	class AddressService
	{
		 typedef std::map<std::string, Address> Addresses;
		typedef std::map<std::string, Address>::const_iterator Iterator;

	public:
		AddressService() {}

		Address getAddress( const std::string& );
		Address getAddress( const Abonent& );
		void setAddress( const Abonent& );

	private:
		Addresses addresses;
	};

} // End Name Space: pulsar

#endif