#pragma once
template <typename T>
class NodeDraw
{
public:
	NodeDraw(int level, T value);
	int Level();
	T Value();
private:
	int _level;    // Значение уровня
	T _value;		// Значение узла
};
template <typename T>
NodeDraw<T>::NodeDraw(int level, T value)
{
	_level = level;
	_value = value;
}

template<typename T>
int NodeDraw<T>::Level()
{
	return _level;
}

template<typename T>
T NodeDraw<T>::Value()
{
	return _value;
}
