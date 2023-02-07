#include <iostream>

#define DEBUGGING 1
#if (DEBUGGING == 1)
#define PRINT_BUFF for (size_t index = 0; index < length; index++)\
	std::cout << buff[index] << " "; \
	std::cout << std::endl;
#else PRINT_BUFF
#endif

#ifndef CIRCULARBUFF
#define CIRCULARBUFF

template <class Type>
class circularBuff {
private:
	Type* buff;
	size_t length;
	size_t count = 0;
	Type* head;
	Type* tail;
	bool flagReplace = false;		 //ôëàã ïåðåçàïèñè
public:
	explicit circularBuff(size_t length = 0);
	~circularBuff() { this->clear(); }
	size_t size() { return count; }
	void push_back(const Type& value);
	void push_front(const Type& value);
	bool pop_back(Type& out_value);
	bool pop_front(Type& out_value);
	void clear();
};

template<class Type>
circularBuff<Type>::circularBuff(size_t length)
	:length(length), buff(new Type[length]) {
	flagReplace = !length;
	head = buff;
	tail = &buff[length - 1];
}

template<class Type>
void circularBuff<Type>::push_back(const Type & value)
{
	// [1][2][3][4] -> [5][2][3][4]  -> [5][6][3][4]
	//  ^head               ^head               ^head
	if (!flagReplace)				//åñëè íå çàïîëíåí
	{
		if (++count == length)
			flagReplace = true;
	}
	else
		tail = head;
	*head = value;
	++head;
	if (head == &buff[length])
		head = buff;
	PRINT_BUFF
}

template<class Type>
void circularBuff<Type>::push_front(const Type & value)
{
	// [1][2][3][4] -> [1][2][3][5] -> [1][2][6][5]
	//             ^tail          ^tail        ^tail
	if (!flagReplace)				//åñëè íå çàïîëíåí
	{
		if (++count == length)
			flagReplace = true;
	}
	else
		head = tail;
	*tail = value;
	if (tail == buff)
		tail = &buff[length - 1];
	else
		--tail;
	PRINT_BUFF
}

template<class Type>
bool circularBuff<Type>::pop_back(Type & out_value)
{
	// [5][2][3][4] -> [x][2][3][4] -> [x][2][3][x]
	//       ^head        ^head                     ^head
	if (count)					//åñëè åñòü ÷òî áðàòü
	{
		--count;
		if (head == buff)
			head = &buff[length - 1];
		else
			--head;
		out_value = *head;
		//remove
		*head = 0;
		PRINT_BUFF
			return true;
	}
	else
		return false;

}

template<class Type>
bool circularBuff<Type>::pop_front(Type & out_value)
{
	// [5][2][3][4] -> [5][x][3][4] -> [5][x][x][4]
	//  ^tail               ^tail              ^tail
	if (count)					//åñëè åñòü ÷òî áðàòü
	{
		--count;
		if (++tail == &buff[length])
			tail = buff;
		out_value = *tail;
		//remove
		*tail = 0;
		PRINT_BUFF
			return true;
	}
	else
		return false;
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

#endif

int main() {
	circularBuff<int> buffer(4);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);
	buffer.push_back(4);
	buffer.push_front(5);
	buffer.push_front(6);
	//buffer.push_front(5);
	//buffer.push_front(6);
	//buffer.push_back(5);
	//buffer.push_back(6);
	//buffer.push_back(7);
	//buffer.push_front(1);
	//buffer.push_front(2);
	//buffer.push_front(3);
	//buffer.push_back(8);
	int t;
	t = 3;
	//buffer.pop_back(t);
	//buffer.pop_back(t);
	//buffer.pop_back(t);
	//buffer.pop_back(t);
	//buffer.push_back(3);
	buffer.pop_front(t);
	buffer.pop_front(t);
	buffer.pop_front(t);

	return 0;
}