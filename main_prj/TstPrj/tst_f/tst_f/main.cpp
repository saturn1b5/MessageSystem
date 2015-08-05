#include <functional>
#include <iostream>

class GameCharacter {
	typedef std::function<int(const GameCharacter&)> HealthCalcFunc;
public:
	GameCharacter(HealthCalcFunc healthCalcFunc) : healthCalcFunc(healthCalcFunc) {

	}
	int getHealth() const {
		return healthCalcFunc(*this);
	}
private:
	HealthCalcFunc healthCalcFunc;
};

int calcHealth(const GameCharacter& gc) {
	return 1;
}

struct calcFuncObj {
	int operator()(const GameCharacter& gc) {
		return 5;
	}
};

int main(int argc, char **argv)
{
	GameCharacter gc1(calcHealth);

	std::cout << gc1.getHealth() << std::endl;

	calcFuncObj oBj;

	GameCharacter gc2(oBj);

	std::cout << gc2.getHealth() << std::endl;

	return 0;
}