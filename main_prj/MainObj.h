#ifndef __MAIN_OBJ__
#define __MAIN_OBJ__

#include <iostream>
#include "Runnable.h"
#include "MessageSystem.h"
#include "Address.h"
#include "Singleton.h"
#include "MsgEchoAbonent2.h"
#include "TimeHelper.h"

namespace pulsar
{
	class Main : public Abonent, public Singleton<Main>	{
	public:
		Main(MessageSystem& ms)
			: Singleton<Main>(*this), ms(ms) {

				metaClass = &classInstance;
				ms.addService(*this);

				countMessages = 0;

			}

		~Main() {};

		Address getAddress() const {
			return address;
		}

		void run() {
			while (true) {

				//std::cout << "Msg from thread: " << std::this_thread::get_id() << "\n";
				sendMessage();
				ms.execForAbonent(*this);
				TimeHelper::sleep(10);
			}
		}

	private:

		int countMessages;

		Address address;
		MessageSystem& ms;

		void sendMessage() {

			if (countMessages < 10) {

				Address from = getAddress();
				Address to = ms.getAddressService().getAddress(Abonent2::classInstance.getClassName());
				//ms.sendMessage(new MsgEchoAbonent2(from, to, "Hello, Abonent 2! from Main!"));
				ms.sendMessage(std::make_shared<MsgEchoAbonent2>(from, to, "Hello, Abonent 25! from Main!"));

				++countMessages;

			}
		}

		Main(const Main& rhr) = delete;
		Main& operator=(const Main& rhr) = delete;

	public:
		static	MetaClass	classInstance;

	};

}

#endif