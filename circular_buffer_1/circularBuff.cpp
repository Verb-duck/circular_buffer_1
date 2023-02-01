#include <iostream>

template <class Type>
class circularBuff {
private:
	Type* buff;
	size_t length;
	size_t indexInsert = 0;			
	size_t offsetPoint = 0;			
	bool flagReplace;				//флаг перезаписи
public:
	explicit circularBuff(size_t length = 0) :length(length), 
		 buff(new Type[length]), flagReplace(!length) {}
	~circularBuff() { this->clear();}
	Type& operator[] (const size_t index);
	size_t size() { return length; }
	void push_back(const Type& value);
	void push_front(const Type& value);
	void clear();
};

template<class Type>
Type& circularBuff<Type>::operator[](const size_t index)
{
	size_t replaceIndex = index + offsetPoint;		
	if (replaceIndex == length)
	{
		replaceIndex -= length;
	}
	return buff[replaceIndex];
}

template<class Type>
void circularBuff<Type>::push_back(const Type& value)
{
	// [1] [2] [3] [4] -> [5][2][3][4]
	if (indexInsert == length)  
	{
		indexInsert = 0;
		flagReplace = true;
	}
	if (flagReplace)
	{
		offsetPoint++;
		if (offsetPoint == length)
		{
			offsetPoint = 0;
		}
	}	
	buff[indexInsert] = value;
	indexInsert++;
}

template<class Type>
void circularBuff<Type>::clear()
{
	if (buff != NULL)
	{
		delete[] buff;
		buff = nullptr;
	}
}



int main() {
	circularBuff<int> buffer(4);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);
	buffer.push_back(4);
	buffer.push_back(5);
	buffer.push_back(6);
	buffer.push_back(7);
	buffer.push_back(8);
	//buffer.push_back(9);
	for (size_t index = 0; index < buffer.size(); index++) {
		std::cout<< buffer[index]<< std::endl;
	}
	return 0;
}