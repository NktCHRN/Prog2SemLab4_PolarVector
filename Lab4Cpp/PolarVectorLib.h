#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <exception>
#include <stdexcept>

class PolarVector {
private:
	double _length;														// ����� �������
	double _angle;														// �������� ���� � ��������
	void DelFullSpins();												// �������� �������� ���� � ���� 0;2pi
public:
    PolarVector();														// ����������� �� ���������
	PolarVector(double length, double angle);							// ����������� � �����������
	PolarVector(const PolarVector &copyFrom);							// ����������� �����������
    void TurnVector(double angle);										// ��������� ������
    double GetLength();
    double GetAngle();
    PolarVector operator *(double factor);								// ���������� ��������� * - ��������� ������� �� �����
	PolarVector & operator *=(double factor);							// ���������� ��������� *=
    PolarVector operator +(const PolarVector & rightVector);					// ���������� ��������� + ��������� ��������
	friend PolarVector operator *(double factor, const PolarVector & vector);	// ���������� ��������� * ����� ������������� ������� - ��������� ����� �� ������
};