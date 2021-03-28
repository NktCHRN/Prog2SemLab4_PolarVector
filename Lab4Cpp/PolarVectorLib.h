#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

class PolarVector {
private:
	double _length;														// ����� �������
	double _angle;														// �������� ���� � ��������
	bool _errorFlag;													// ����������, �� �������� �� ������ � ��������� ��������
	void DelFullSpins();												// �������� �������� ���� � ���� 0;2pi
public:
    PolarVector();														// ����������� �� ���������
	PolarVector(double length, double angle);							// ����������� � �����������
	PolarVector(const PolarVector &copyFrom);							// ����������� �����������
    void TurnVector(double angle);										// ��������� ������
    double GetLength();
    double GetAngle();
	bool GetErrorFlag();
    PolarVector operator *(double factor);								// ���������� ��������� * - ��������� ������� �� �����
	PolarVector & operator *=(double factor);							// ���������� ��������� *=
    PolarVector operator +(const PolarVector & rightVector);					// ���������� ��������� + ��������� ��������
	friend PolarVector operator *(double factor, const PolarVector & vector);	// ���������� ��������� * ����� ������������� ������� - ��������� ����� �� ������
};