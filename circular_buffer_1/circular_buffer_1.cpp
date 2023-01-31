#include <iostream>

template <class Type> 
class circularBuff {
private:
	Type buff;
	size_t size = 0;
public:
	explicit circularBuff(size_t size) :
		size(size), buff(new Type[size]) {}

};


int main() {
	return 0;
}