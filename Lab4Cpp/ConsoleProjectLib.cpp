#include "ConsoleProjectLib.h"

using namespace std;

void ProgramInfo()							            //���������� � ���������
{
    cout << "Lab N4. Nikita Chernikov, IS-02" << endl;
    cout << "Researching of overriding of operations and operators" << endl;
    cout << "Variant 15" << endl;
}

void FormattedPrint(PolarVector vector, const char *name, bool showErrorFlag) 
{
    if (showErrorFlag)
        cout << "Vector " << name << ". Length: " << fixed << vector.GetLength() << 
        ". Polar angle: " << fixed << vector.GetAngle() << " degrees. ErrorFlag is " << ((vector.GetErrorFlag()) ? "true" : "false") << endl;
    else
        cout << "Vector " << name << ". Length: " << fixed << vector.GetLength() << ". Polar angle: " << fixed << vector.GetAngle() << " degrees." << endl;
}