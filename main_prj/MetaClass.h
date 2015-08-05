#ifndef __METACLASS__
#define __METACLASS__

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

	class	MetaClass
	{
	public:
		MetaClass( const char * theClassName, MetaClass * super ) {
			className = theClassName;
			superClass = super;
		}

		const char * getClassName() const {
			return className;
		}

		MetaClass * getSuperClass() const {
			return superClass;
		}

		bool	isKindOfClass( const MetaClass& theClass ) const;
		bool	isInstanceOfClass( const MetaClass& theClass ) const;
	
	protected:
		const char * className;						// name of the class
		MetaClass  * superClass;					// link to parent metaclass
	};

} // End Name Space: pulsar

#endif