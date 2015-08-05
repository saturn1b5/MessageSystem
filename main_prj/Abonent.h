/************************************************************************************

Filename    :   Abonent.h
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

#ifndef __ABONENT__
#define __ABONENT__

#include <string>
#include "Address.h"
#include "MetaClass.h"

/**************************************************************************\

^^^^^^^^  ^	     ^  ^         ^^^^^^^^  ^^^^^^^^  ^^^^^^^^
^      ^  ^      ^  ^         ^         ^      ^  ^      ^
^^^^^^^^  ^      ^  ^         ^^^^^^^^  ^^^^^^^^  ^^^^^^^^
^         ^      ^  ^                ^  ^      ^  ^   ^
^         ^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^      ^  ^      ^

\***************************************************************************/

using std::string;

//	Name Space declaration

namespace pulsar
{
	class	Abonent {
	public:
		Abonent() {
			metaClass = &classInstance;
		}
		
		virtual		~Abonent() {}
		virtual Address		getAddress() const = 0;
		
		//virtual string		ClassName() const = 0;

		string		getClassName() const {
			return metaClass != nullptr ? metaClass->getClassName() : "";
		}

		bool	isKindOfClass( const MetaClass& theClass ) const {
			return metaClass != nullptr ? metaClass->isKindOfClass( theClass ) : false;
		}

		bool	isInstanceOfClass( const MetaClass& theClass ) const {
			return metaClass != nullptr ? metaClass->isInstanceOfClass( theClass ) : false;
		}
	
		// Static variables and functions

		static MetaClass classInstance;

	protected:
		
		MetaClass *metaClass;
	};

} // End Name Space: pulsar

#endif