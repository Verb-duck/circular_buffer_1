#include <iostream>

template <class Type>
class circularBuff {
private:
	Type* buff;
	size_t length = 0;
	size_t indexInsert = 0;
	size_t offsetPoint = 0;
public:
	explicit circularBuff(size_t length) :length(length), buff(new Type[length]) {}
	Type& operator[] (const size_t index);
	size_t size() { return length; }
	void push_back(const Type& value);
};


template<class Type>
Type& circularBuff<Type>::operator[]( size_t index)
{
	index += offsetPoint;
	if (index > length) 
	{
		index -= length;
	}
	return buff[index];
}

template<class Type>
void circularBuff<Type>::push_back(const Type& value)
{
	if (indexInsert < length)
	{
		indexInsert++;
	}
	else
	{
		offsetPoint++;
		indexInsert = 0;
		if (offsetPoint == length)
		{
			offsetPoint = 0;
		}
	}
	buff[indexInsert] = value;
}



int main() {
	circularBuff<int> buffer(4);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);
	buffer.push_back(4);
	buffer.push_back(5);
	buffer.push_back(6);
	//buffer.push_back(7);
	//buffer.push_back(8);
	for (size_t index = 0; index < buffer.size(); index++) {
		std::cout<< buffer[index]<< std::endl;
	}
	return 0;
}