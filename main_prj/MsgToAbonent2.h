#ifndef __MSG_TO_ABONENT2__
#define __MSG_TO_ABONENT2__

#include "Msg.h"
#include "Abonent2.h"

namespace pulsar
{
	class MsgToAbonent2 : public Msg
	{
	public:
		
		MsgToAbonent2( Address from, Address to ) : Msg( from, to ) {}
		~MsgToAbonent2() {}

		void	exec(const Abonent& abonent) {
			
			if ( abonent.isInstanceOfClass( Abonent2::classInstance ) )
				exec( (Abonent2&)abonent );
		}

	private:
		virtual void exec(Abonent2& abonent2) = 0;
	};

}

#endif