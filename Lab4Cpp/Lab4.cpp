#include "PolarVectorLib.h"
#include "ConsoleProjectLib.h"

using namespace std;

int main()
{
    ProgramInfo();
    PolarVector Z1;                                             // создаем объект Z1, используя конструктор по умолчанию
    cout << endl;
    FormattedPrint(Z1, "Z1");
    double z2Length, z2Angle;                                   // длина и угол вектора Z2 (вводит пользователь)
    do
    {
        cout << "Enter the length of new vector: " << endl;
        cin >> z2Length;
    } while (cin.fail());
    do
    {
        cout << "Enter the polar angle of new vector: " << endl;
        cin >> z2Angle;
    } while (cin.fail());
    PolarVector Z2(z2Length, z2Angle);                          // создаем объект Z2, используя коструктор с параметрами
    FormattedPrint(Z2, "Z2", true);
    PolarVector Z3(Z2);                                         // создаем объект Z3, используя конструктор копирования
    FormattedPrint(Z3, "Z3");
    Z3 = Z3 * 2;                                                // увеличиваем длину вектора Z3 при помощи перегруженной операции * (Альтернатива: Z3 *= 2)
    cout << "\nNow let's multiply vector Z3 by 2. Z3 *= 2" << endl;
    FormattedPrint(Z3, "Z3");
    Z3.TurnVector(90);                                          // при помощи метода, "поворачиваем" вектор Z3 на 90 градусов ()
    cout << "\nNow let's turn vector Z3 on 90 degrees." << endl;
    FormattedPrint(Z3, "Z3");
    Z1 = Z2 + Z3;                                               // присваиваем Z1 значение "суммы" Z2 и Z3, вычисленной при помощи перегруженного оператора
    cout << "\nNow let's add vectors Z2 and Z3. The result will be written in vector Z1. Z1 = Z2 + Z3" << endl;
    FormattedPrint(Z1, "Z1", true);
    cout << endl;
    system("pause");
}