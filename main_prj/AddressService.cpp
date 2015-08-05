/************************************************************************************

Filename    :   AddressService.cpp
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
#include "AddressService.h"
#include <stdexcept>

using namespace pulsar;

Address AddressService::getAddress( const Abonent& abonent )
{
	std::string abonentClass = abonent.getClassName();

	auto it = addresses.find( abonentClass );

	if ( it == addresses.end() )
		throw std::domain_error( "No address" );
	
	return it->second;
}

Address AddressService::getAddress( const std::string& abonentClass )
{
	auto it = addresses.find( abonentClass );
	
	if ( it == addresses.end() )
		throw std::domain_error( "No address" );

	return it->second;
}

void AddressService::setAddress( const Abonent& abonent )
{
	auto it = addresses.find( abonent.getClassName() );
	
	if ( it == addresses.end() )
		addresses[ abonent.getClassName() ] = abonent.getAddress();
}