#pragma once
#include <iostream>

template <class T>
class TQueue
{
private:
	int MaxSize;
	T* arr;
	int head;
	int tail;
	int count;
public:
	TQueue(int _MaxSize = 10);
	~TQueue()
	{
		delete[] arr;
	};
	TQueue(const TQueue<T>& q);
	TQueue& operator = (const TQueue<T>& q);

	bool IsEmpty()
	{

		if (count == 0)
		{
			return true;
		}
		else
			return false;
	};
	bool IsFull()
	{

		if (count == MaxSize)
		{
			return true;
		}
		else
			return false;
	};

	bool operator == (const TQueue<T>& q) const;
	bool operator != (const TQueue<T>& q) const;

	void Push(T elem);
	T Pop();
	void Clear();
	int GetHead();
	int GetSize();
	int GetMaxSize();


	friend std::istream& operator >> (std::istream& in, const TQueue& q)
	{
		for (int i = 0; i < q.MaxSize; i++)
		{
			in >> q.arr[i];
		};
		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, const TQueue& q)
	{
		out << "[";
		for (int i = 0; i < q.MaxSize; i++)
		{
			out << q.arr[i] << " ";
		};
		out << "]";
		return out;
	}
};

template<class T>
inline TQueue<T>::TQueue(int _MaxSize)
{
	if (_MaxSize < 1) throw "Small length";
		MaxSize = _MaxSize;
	arr = new T[MaxSize];
	head = 0;
	tail = -1;
	count = 0;
};
template<class T>
inline TQueue<T>::TQueue(const TQueue<T>& q)
{
	MaxSize = q.MaxSize;
	head = q.head;
	tail = q.tail;
	count = q.count;
	arr = new T[MaxSize];
	for (int i = 0; i < MaxSize; i++)
	{
		arr[i] = q.arr[i];
	}
};
template<class T>
inline TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
{
	if (this == &q)
		return *this;
	if (MaxSize != q.MaxSize)
	{
		delete[] arr;
		MaxSize = q.MaxSize;
		arr = new T[MaxSize];
	};
	head = q.head;
	tail = q.tail;
	count = q.count;
	for (int tcount = count, i = head; tcount > 0; tcount--)
	{
		arr[i] = q.arr[i];
		i = (++i) % MaxSize;
	}
	return *this;
};
template<class T>
inline bool TQueue<T>::operator==(const TQueue<T>& q) const
{
	if (MaxSize != q.MaxSize) return false;
	if (head != q.head) return false;
	if (tail != q.tail) return false;
	if (count != q.count) return false;
	
	for (int i = count, j = head; i > 0; i--)
	{
		if (arr[j] != q.arr[j]) return false;
		j = (++j) % MaxSize;
	}

	return true;
}
template<class T>
inline bool TQueue<T>::operator!=(const TQueue<T>& q) const
{
	return !operator==(other);
}
template<class T>
inline void TQueue<T>::Push(T elem)
{
	if (IsFull()) throw "Can't push, full queue";
	tail = (++tail) % MaxSize;

	arr[tail] = elem;

	count++;
};
template<class T>
inline T TQueue<T>::Pop()
{
	if (IsEmpty()) throw "Can't pop, empty queue";
	T temp = arr[head];
	head++;
	if (tail > MaxSize)
	{
		tail = 0;
	};
	return temp;
};
template<class T>
inline void TQueue<T>::Clear()
{
	count = 0;
	tail = -1;
	head = 0;
}
template<class T>
inline int TQueue<T>::GetHead()
{
	return head;
}
template<class T>
inline int TQueue<T>::GetSize()
{
	return count;
}
template<class T>
inline int TQueue<T>::GetMaxSize()
{
	return MaxSize;
}
;
