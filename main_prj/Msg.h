/************************************************************************************

Filename    :   Msg.h
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

#ifndef __MSG__
#define __MSG__

#include <memory>
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
	class Msg {

	protected:
		Msg(Address from, Address to) : from(from), to(to) {}
	
	public:
		Address	getFrom() const {
			return from;
		}

		Address getTo() const {
			return to;
		}

		virtual void	exec(const Abonent& abonent) = 0;

		virtual ~Msg() = 0;

	private:
		const Address from;
		const Address to;
	};

}  // End Name Space: pulsar

#endif