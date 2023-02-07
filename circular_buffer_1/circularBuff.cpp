#include <iostream>

#define DEBUGGING 1
#if (DEBUGGING == 1)
#define PRINT_BUFF for (size_t index = 0; index < capacitty; index++)\
	std::cout << buff[index] << " "; \
	std::cout << std::endl;
#else PRINT_BUFF
#endif

#ifndef CIRCULARBUFF
#define CIRCULARBUFF

template <class Type>
class IcircularBuff {
private:
	Type* buff;
	size_t capacitty;
	size_t count = 0;
	Type* head;
	Type* tail;
public:
	explicit IcircularBuff(size_t capacitty);
	~IcircularBuff () { this->clear(); }
	size_t size() { return count; }
	bool empty() { return count; }
	virtual void push_back (const Type& value);
	virtual void push_front (const Type& value);
	virtual bool pop_back (Type& outValue);
	virtual bool pop_front (Type& outValue);
	void clear();
};

template<class Type>
IcircularBuff<Type>::IcircularBuff (size_t capacitty)
	:capacitty(capacitty), buff(new Type[capacitty]) {
	head = buff;
	tail = &buff[capacitty - 1];
}

template<class Type>
void IcircularBuff<Type>::clear()
{
	if (buff != NULL)
	{
		delete[] buff;
		buff = nullptr;
	}
}

//
//template <class Type>
//class circularBuff :public IcircularBuff<Type> {
//public:
//	explicit circularBuff(size_t capacity)  {}
//	//void push_back (const Type& value);
//	//void push_front (const Type& value);
//	///bool pop_back (Type& outValue);
//	//bool pop_front (Type& outValue);
//};

//template<class Type>
//void circularBuff<Type>::push_back(const Type & value)
//{
//	// [1][2][3][4] -> [5][2][3][4]  -> [5][6][3][4]
//	//  ^head               ^head               ^head
//	if (count == capacitty)	//åñëè çàïîëíåí
//		tail = head;
//	else
//		++count;
//	*head = value;
//	if (++head == &buff[capacitty])
//		head = buff;
//	PRINT_BUFF
//}
//
//template<class Type>
//void circularBuff<Type>::push_front(const Type & value)
//{
//	// [1][2][3][4] -> [1][2][3][5] -> [1][2][6][5]
//	//           ^tail        ^tail        ^tail
//	if (count == capacitty)
//		head = tail;
//	else
//		++count;
//	*tail = value;
//	if (tail == buff)
//		tail = &buff[capacitty - 1];
//	else
//		--tail;
//	PRINT_BUFF
//}
//
//template<class Type>
//bool circularBuff<Type>::pop_back(Type& outValue)
//{
//	// [5][2][3][4] -> [x][2][3][4] -> [x][2][3][x]
//	//     ^head        ^head                    ^head
//	if (count)					//åñëè åñòü ÷òî áðàòü
//	{
//		--count;
//		if (head == buff)
//			head = &buff[capacitty - 1];
//		else
//			--head;
//		outValue = *head;
//		PRINT_BUFF
//			return true;
//	}
//	else
//		return false;
//
//}
//
//template<class Type>
//bool circularBuff<Type>::pop_front(Type& outValue)
//{
//	// [5][2][3][4] -> [5][x][3][4] -> [5][x][x][4]
//	//  ^tail              ^tail              ^tail
//	if (count)					//åñëè åñòü ÷òî áðàòü
//	{
//		--count;
//		if (++tail == &buff[capacitty])
//			tail = buff;
//		outValue = *tail;
//		PRINT_BUFF
//			return true;
//	}
//	else
//		return false;
//}


#endif

int main() {
	//int t;
	IcircularBuff<int> buffer(4);
	
	//buffer.push_back(1);
	//buffer.push_back(2);
	//buffer.push_back(3);
	//buffer.push_back(4);
	//buffer.push_front(5);
	//buffer.push_front(6);
	////buffer.push_front(5);
	////buffer.push_front(6);
	////buffer.push_back(5);
	////buffer.push_back(6);
	////buffer.push_back(7);
	////buffer.push_front(1);
	////buffer.push_front(2);
	////buffer.push_front(3);
	////buffer.push_back(8);	
	//buffer.pop_back(t);
	//std::cout << t << std::endl;
	////buffer.pop_back();
	////buffer.pop_back();
	//buffer.push_back(5);
	//buffer.pop_front(t);
	////buffer.pop_front();
	////buffer.pop_front();

	return 0;
}