using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PolarVectorLib;

namespace Lab4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "PolarVector Demonstation";
            ProgramInfo();
            PolarVector Z1 = new PolarVector();                         // создаем экземпляр класса PolarVector - Z1, используя конструктор по умолчанию
            Console.WriteLine();
            FormattedPrint(Z1, "Z1");
            double z2Length, z2Angle;                                   // длина и угол вектора Z2 (вводит пользователь)
            bool parsed;                                                // прошел ли успешно парсинг введенной строки
            do
            {
                Console.WriteLine("Enter the length of new vector: ");
                parsed = double.TryParse(Console.ReadLine().Replace('.', ','), out z2Length);
            }
            while (!parsed);
            do
            {
                Console.WriteLine("Enter the polar angle of new vector: ");
                parsed = double.TryParse(Console.ReadLine().Replace('.', ','), out z2Angle);
            }
            while (!parsed);
            PolarVector Z2 = new PolarVector(z2Length, z2Angle);        // создаем экземпляр класса PolarVector - Z2, используя коструктор с параметрами
            FormattedPrint(Z2, "Z2", true);
            PolarVector Z3 = new PolarVector(Z2);                       // создаем экземпляр класса PolarVector - Z3, используя конструктор копирования
            FormattedPrint(Z3, "Z3");
            Z3 *= 2;                                                    // увеличиваем длину вектора Z3 при помощи перегруженной операции * (Альтернатива: Z3 = Z3 * 2)
            Console.WriteLine("\nNow let's multiply vector Z3 by 2. Z3 *= 2");
            FormattedPrint(Z3, "Z3");
            Z3.TurnVector(90);                                          // при помощи метода, "поворачиваем" вектор Z3 на 90 градусов ()
            Console.WriteLine("\nNow let's turn vector Z3 on 90 degrees.");
            FormattedPrint(Z3, "Z3");
            Z1 = Z2 + Z3;                                               // присваиваем Z1 значение "суммы" Z2 и Z3, вычисленной при помощи перегруженного оператора
            Console.WriteLine("\nNow let's add vectors Z2 and Z3. The result will be written in vector Z1. Z1 = Z2 + Z3");
            FormattedPrint(Z1, "Z1", true);
            Console.WriteLine("\nPress ENTER to quit");
            Console.ReadKey();
        }
        static void ProgramInfo()							            //информация о программе
        {
            Console.WriteLine("Lab N4. Nikita Chernikov, IS-02");
            Console.WriteLine("Researching of overriding of operations and operators");
            Console.WriteLine("Variant 15");
        }
        static void FormattedPrint(PolarVector vector, string name, bool showErrorFlag = false)      // форматированный вывод данных вектора
        {
            if (showErrorFlag)
                Console.WriteLine("Vector {0}. Length: {1:F6}. Polar angle: {2:F6} degrees. ErrorFlag is {3}", name, vector.GetLength(), vector.GetAngle(), vector.ErrorFlag);
            else
                Console.WriteLine("Vector {0}. Length: {1:F6}. Polar angle: {2:F6} degrees.", name, vector.GetLength(), vector.GetAngle());
        }
    }
}
