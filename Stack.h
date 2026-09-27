#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
public:
	void push(const T& value) //appends value to end of stack
	{
		vec.push_back(value);
	}

	T pop() //removes value from end of stack and returns it
	{
		T val = vec.back();
		vec.pop_back();
		return val;
	}

	T& top() //returns value from end of stack
	{
		return vec.back();
	}

	bool empty() const //checks if stack is empty and returns true/false
	{
		return vec.empty();
	}

	size_t size() const //returns num of blocks in stack
	{
		return vec.size();
	}
	
private:
	vector<T> vec;
};