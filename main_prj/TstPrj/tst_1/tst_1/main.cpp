#include <iostream>

using std::cout;

class	MetaClass
{
protected:
	const char * className;						// name of the class
	MetaClass  * superClass;					// link to parent metaclass

public:
	MetaClass(const char * theClassName, MetaClass * super)
	{
		className = theClassName;
		superClass = super;
	}

	const char * getClassName() const
	{
		return className;
	}

	MetaClass * getSuperClass() const
	{
		return superClass;
	}

	bool	isKindOfClass(const MetaClass& theClass) const;
	bool	isInstanceOfClass(const MetaClass& theClass) const;
};

//////////////////////////// MetaClass methods /////////////////////////

bool	MetaClass::isInstanceOfClass(const MetaClass& theClass) const
{
	return this == &theClass;
}

bool	MetaClass::isKindOfClass(const MetaClass& theClass) const
{
	const MetaClass * clsPtr = this;

	while (clsPtr != nullptr)
	{
		if (clsPtr->isInstanceOfClass(theClass))
			return true;

		clsPtr = clsPtr->getSuperClass();
	};

	return false;
}

class   Object
{
protected:
	MetaClass * metaClass;

public:
	Object() {
		metaClass = &classInstance;
	};
	virtual ~Object() {}

	const char  * getClassName() const
	{
		return metaClass != nullptr ? metaClass->getClassName() : "";
	}

	bool	isKindOfClass(const MetaClass& theClass) const
	{
		return metaClass != NULL ? metaClass->isKindOfClass(theClass) : false;
	}

	bool	isInstanceOfClass(const MetaClass& theClass) const
	{
		return metaClass != NULL ? metaClass->isInstanceOfClass(theClass) : false;
	}

	static	MetaClass	classInstance;

};

MetaClass	Object::classInstance("Object", nullptr);

class	Queue : public Object
{
public:
	Queue()
	{
		metaClass = &classInstance;
	}

	static	MetaClass	classInstance;

};

MetaClass	Queue::classInstance("Queue", &Object::classInstance);

int main(int argc, char* argv[]) {

	Queue q;

	cout << q.getClassName() << "\n";
	
	Object *pObj = &q;

	cout << pObj->isInstanceOfClass(Queue::classInstance) << "\n";

	return 0;
}