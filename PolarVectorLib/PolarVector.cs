using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolarVectorLib
{
    public class PolarVector
    {
        private double _length;                         // длина вектора
        private double _angle;                          // полярный угол в градусах
        public PolarVector()                            // конструктор по умолчанию
        {
            _length = 0;
            _angle = 0;
        }
        public PolarVector(double length, double angle) // конструктор с параметрами
        {
            if (length >= 0)
            {
                _length = length;
            }
            else
            {
                _length = 0;
                throw new ArgumentException("Length can`t be negative", nameof(length));                       // ошибка - длина не может быть отрицательной
            }
            _angle = angle;
            DelFullSpins();
        }
        public PolarVector(PolarVector copyFrom)        // конструктор копирования
        {
            _length = copyFrom._length;
            _angle = copyFrom._angle;
        }
        public void TurnVector(double angle)            // повернуть вектор
        {
            _angle += angle;
            DelFullSpins();
        }
        public double GetLength() => _length;
        public double GetAngle() => _angle;
        public static PolarVector operator *(PolarVector vector, double factor)                     //перегрузка оператора * - умножение вектора на число
        {
            PolarVector resultVector = new PolarVector(vector._length * factor, vector._angle);     // при умножении увеличивается только длина вектора
            return resultVector;
        }
        public static PolarVector operator *(double factor, PolarVector vector)
        {
            PolarVector resultVector = new PolarVector(vector._length * factor, vector._angle);
            return resultVector;
        }
        public static PolarVector operator +(PolarVector leftVector, PolarVector rightVector)       // перегрузка оператора + векторное сложение
        {
            const int halfSpin = 180;
            PolarVector resultVector = new PolarVector();
            resultVector._length =                                                                  // подсчитываем длину нового вектора по теореме косинусов
                            Math.Sqrt(leftVector._length * leftVector._length + rightVector._length * rightVector._length
                - 2 * leftVector._length * rightVector._length * Math.Cos((leftVector._angle + halfSpin - rightVector._angle) * Math.PI / halfSpin));
            if (resultVector._length > 0)                                                           // проверяем, не будет ли деления на ноль
            {
                resultVector._angle = leftVector._angle -                                           // по теореме синусов подсчитываем новый угол
                    Math.Asin(Math.Sin((rightVector._angle + halfSpin - leftVector._angle) * Math.PI / halfSpin) * rightVector._length / resultVector._length) * halfSpin / Math.PI;
                resultVector.DelFullSpins();
            }
            else
            {
                resultVector._angle = 0;
                throw new DivideByZeroException("Length of the result vector was 0. Can`t calculate the result because of division by zero");                                                      // ошибка - деление на ноль
            }
            return resultVector;
        }
        private void DelFullSpins()            // приводит полярный угол к виду 0;2pi
        {
            const int spin = 360;
            while (_angle >= spin)
                _angle -= spin;
            while (_angle < 0)
                _angle += spin;
        }
    }
}
