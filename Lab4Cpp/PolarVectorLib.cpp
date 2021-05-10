#include "PolarVectorLib.h"

using namespace std;

PolarVector::PolarVector()                            // ����������� �� ���������
{
    _length = 0;
    _angle = 0;
}

PolarVector::PolarVector(double length, double angle) // ����������� � �����������
{
    if (length >= 0)
    {
        _length = length;
    }
    else
    {
        _length = 0;
        throw invalid_argument("Length can`t be negative");                       // ������ - ����� �� ����� ���� �������������
    }
    _angle = angle;
    DelFullSpins();
}

PolarVector::PolarVector(const PolarVector& copyFrom)        // ����������� �����������
{
    _length = copyFrom._length;
    _angle = copyFrom._angle;
}

void PolarVector::TurnVector(double angle)            // ��������� ������
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

PolarVector PolarVector::operator *(double factor) {	    // ���������� ��������� * - ��������� ������� �� �����
    PolarVector resultVector(_length * factor, _angle);     // ��� ��������� ������������� ������ ����� �������
    return resultVector;
}

PolarVector & PolarVector::operator *=(double factor) {					//���������� ��������� *=
    _length *= factor;
    return *this;
}

PolarVector operator *(double factor, const PolarVector & vector) {	// ���������� ��������� * ����� ������������� ������� - ��������� ����� �� ������
    PolarVector resultVector(vector._length * factor, vector._angle);     // ��� �������� ������������� ������ ����� �������
    return resultVector;
}

PolarVector PolarVector::operator +(const PolarVector & rightVector) { // ���������� ��������� + ��������� ��������
    const int halfSpin = 180;
    PolarVector resultVector;
    resultVector._length =                                                                  // ������������ ����� ������ ������� �� ������� ���������
        sqrt(_length * _length + rightVector._length * rightVector._length
            - 2 * _length * rightVector._length * cos((_angle + halfSpin - rightVector._angle) * M_PI / halfSpin));
    if (resultVector._length > 0)                                                           // ���������, �� ����� �� ������� �� ����
    {
        resultVector._angle = _angle -                                           // �� ������� ������� ������������ ����� ����
            asin(sin((rightVector._angle + halfSpin - _angle) * M_PI / halfSpin) * rightVector._length / resultVector._length) * halfSpin / M_PI;
        resultVector.DelFullSpins();
    }
    else
    {
        resultVector._angle = 0;
        throw runtime_error("Length of the result vector was 0. Can`t calculate the result because of division by zero");               // ������ - ������� �� ����
    }
    return resultVector;
}

void PolarVector::DelFullSpins()            // �������� �������� ���� � ���� 0;2pi
{
    const int spin = 360;
    while (_angle >= spin)
        _angle -= spin;
    while (_angle < 0)
        _angle += spin;
}