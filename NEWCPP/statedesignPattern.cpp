// C++ program to demonstrate working of
// State Design Pattern
#include <iostream>
using namespace std;

// State interface
class MobileAlertState {
public:
	virtual void alert() = 0;
};

// Concrete states
class Vibration : public MobileAlertState {
public:
	void alert() override
	{
		std::cout << "vibration..." << std::endl;
	}
};

class Silent : public MobileAlertState {
public:
	void alert() override
	{
		std::cout << "silent..." << std::endl;
	}
};

// Context class
class AlertStateContext {
private:
	MobileAlertState* currentState;

public:
	AlertStateContext() { currentState = new Vibration(); }

	void setState(MobileAlertState* state)
	{
		currentState = state;
	}

	void alert() { currentState->alert(); }
};

int main()
{
	AlertStateContext stateContext;
	stateContext.alert();
	stateContext.alert();
	stateContext.setState(new Silent());
	stateContext.alert();
	stateContext.alert();
	stateContext.alert();

	return 0;
}
// This code is contributed by Ahmed Izz Murtaja
