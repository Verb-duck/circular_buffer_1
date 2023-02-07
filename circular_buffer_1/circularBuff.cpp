#include <iostream>

template <class Type>
class circularBuff {
private:
	Type* buff;
	size_t capacity;			
	size_t length = 0;
	Type* head;					//для добавления в начало очереди
	Type* tail;					//для добавления в конец очереди
	Type* end;
	bool flagReplace = false;	//флаг перезаписи
public:
	explicit circularBuff(size_t capacity = 0)
	{
		this->capacity = capacity;
		buff = new Type[capacity];
		tail = buff;
		head = &buff[capacity - 1];
		end = &buff[capacity];
		for (size_t index = 0; index < capacity; index++) 
			buff[index] = 0;
		std::cout << std::endl;
	}
	~circularBuff()							{this->clear();}
	Type& operator[](const size_t index)	{return buff[index]; }
	size_t size()							{return length;}
	void push_back(const Type& value);
	void push_front(const Type& value);
	void clear();
};

template<class Type>
void circularBuff<Type>::push_back(const Type& value)
{
	*tail = value;
	tail++;
	if (tail == end)
	{
		tail = buff;
	}
	if (length != capacity) 
	{
		length++;
	}
	else
	{
		head = tail;
	}
	for (size_t index = 0; index < capacity; index++)
		std::cout << buff[index]  << " ";
	std::cout << std::endl;
}

template<class Type>
void circularBuff<Type>::push_front(const Type& value)
{
	head--;
	*head = value;
	if (head == buff) {
		head = end;
	}
	if (length != capacity)
	{
		length++;
	}
	else
	{
		tail = head;
	}
	for (size_t index = 0; index < capacity; index++)
		std::cout << buff[index]  << " ";
	std::cout << std::endl;
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
	///*buffer.push_front(3);
	//buffer.push_front(4);
	//*/
	buffer.push_back(3);
	buffer.push_back(4);
	buffer.push_back(5);
	buffer.push_front(6);
	buffer.push_front(7);
	////buffer.push_back(6);
	////buffer.push_back(7);
	buffer.push_back(8);
	////buffer.push_front(2);
	////buffer.push_back(6);
	
	return 0;
}