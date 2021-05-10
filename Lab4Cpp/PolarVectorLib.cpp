#include "PolarVectorLib.h"

using namespace std;

PolarVector::PolarVector()                            // конструктор по умолчанию
{
    _length = 0;
    _angle = 0;
}

PolarVector::PolarVector(double length, double angle) // конструктор с параметрами
{
    if (length >= 0)
    {
        _length = length;
    }
    else
    {
        _length = 0;
        throw invalid_argument("Length can`t be negative");                       // ошибка - длина не может быть отрицательной
    }
    _angle = angle;
    DelFullSpins();
}

PolarVector::PolarVector(const PolarVector& copyFrom)        // конструктор копирования
{
    _length = copyFrom._length;
    _angle = copyFrom._angle;
}

void PolarVector::TurnVector(double angle)            // повернуть вектор
{
    _angle += angle;
    DelFullSpins();
}

double PolarVector::GetLength() {
    return _length;
}

double PolarVector::GetAngle() {
    return _angle;
}

PolarVector PolarVector::operator *(double factor) {	    // перегрузка оператора * - умножение вектора на число
    PolarVector resultVector(_length * factor, _angle);     // при умножении увеличивается только длина вектора
    return resultVector;
}

PolarVector & PolarVector::operator *=(double factor) {					//перегрузка оператора *=
    _length *= factor;
    return *this;
}

PolarVector operator *(double factor, const PolarVector & vector) {	// перегрузка оператора * через дружественную функцию - умножение числа на вектор
    PolarVector resultVector(vector._length * factor, vector._angle);     // при умнжении увеличивается только длина вектора
    return resultVector;
}

PolarVector PolarVector::operator +(const PolarVector & rightVector) { // перегрузка оператора + векторное сложение
    const int halfSpin = 180;
    PolarVector resultVector;
    resultVector._length =                                                                  // подсчитываем длину нового вектора по теореме косинусов
        sqrt(_length * _length + rightVector._length * rightVector._length
            - 2 * _length * rightVector._length * cos((_angle + halfSpin - rightVector._angle) * M_PI / halfSpin));
    if (resultVector._length > 0)                                                           // проверяем, не будет ли деления на ноль
    {
        resultVector._angle = _angle -                                           // по теореме синусов подсчитываем новый угол
            asin(sin((rightVector._angle + halfSpin - _angle) * M_PI / halfSpin) * rightVector._length / resultVector._length) * halfSpin / M_PI;
        resultVector.DelFullSpins();
    }
    else
    {
        resultVector._angle = 0;
        throw runtime_error("Length of the result vector was 0. Can`t calculate the result because of division by zero");               // ошибка - деление на ноль
    }
    return resultVector;
}

void PolarVector::DelFullSpins()            // приводит полярный угол к виду 0;2pi
{
    const int spin = 360;
    while (_angle >= spin)
        _angle -= spin;
    while (_angle < 0)
        _angle += spin;
}