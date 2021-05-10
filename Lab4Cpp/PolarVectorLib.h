#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <exception>
#include <stdexcept>

class PolarVector {
private:
	double _length;														// длина вектора
	double _angle;														// полярный угол в градусах
	void DelFullSpins();												// приводит полярный угол к виду 0;2pi
public:
    PolarVector();														// конструктор по умолчанию
	PolarVector(double length, double angle);							// конструктор с параметрами
	PolarVector(const PolarVector &copyFrom);							// конструктор копирования
    void TurnVector(double angle);										// повернуть вектор
    double GetLength();
    double GetAngle();
    PolarVector operator *(double factor);								// перегрузка оператора * - умножение вектора на число
	PolarVector & operator *=(double factor);							// перегрузка оператора *=
    PolarVector operator +(const PolarVector & rightVector);					// перегрузка оператора + векторное сложение
	friend PolarVector operator *(double factor, const PolarVector & vector);	// перегрузка оператора * через дружественную функцию - умножение числа на вектор
};