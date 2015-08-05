#include "MetaClass.h"

using namespace pulsar;

bool	MetaClass::isInstanceOfClass( const MetaClass& theClass ) const
{
	return this == &theClass;
}

bool	MetaClass::isKindOfClass( const MetaClass& theClass ) const
{
	const MetaClass * clsPtr = this;

	while ( clsPtr != nullptr )
	{
		if ( clsPtr->isInstanceOfClass( theClass ) )
			return true;

		clsPtr = clsPtr->getSuperClass();
	};

	return false;
}