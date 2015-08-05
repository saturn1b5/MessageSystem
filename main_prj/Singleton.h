#ifndef __SINGLETON__
#define __SINGLETON__
#include <assert.h>

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
	template<class T>
	class Singleton
	{
	public:

		Singleton( T& Object ) {
			assert( !s_pInstance );
			s_pInstance = &Object;
		}
		
		~Singleton() {
			assert( s_pInstance );
			s_pInstance = nullptr;
		}

		static T& instance() {
			assert( s_pInstance );
			return ( *s_pInstance );
		}

	private:
		static T *s_pInstance;
		Singleton( const Singleton& Src ) = delete;
		Singleton& operator=( const Singleton& Src ) = delete;
	};

	template<class T> T* Singleton<T>::s_pInstance = nullptr;

} // End NameSpace: pulsar

#endif