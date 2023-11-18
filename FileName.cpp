#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "�������� ����� �������:";
    int choose, num = -1;
    cin >> choose;

    switch (choose) {

    case 0: {
        cout << "������ ��������� ���������" << endl;
        choose = -1;
    }
          break;

    case 1: {
        cout << "int �������� " << sizeof(int) << " ����(�)" << endl;
        cout << "short int �������� " << sizeof(short int) << " ����(�)" << endl;
        cout << "long int �������� " << sizeof(long int) << " ����(�)" << endl;
        cout << "float �������� " << sizeof(float) << " ����(�)" << endl;
        cout << "double �������� " << sizeof(double) << " ����(�)" << endl;
        cout << "long double �������� " << sizeof(long double) << " ����(�)" << endl;
        cout << "char �������� " << sizeof(char) << " ����(�)" << endl;
        cout << "bool �������� " << sizeof(bool) << " ����(�)" << endl;

    }
          break;

    case 2: {
        cout << "������� ����� �����: ";
        cin >> num;
        int mask = 1 << ((sizeof(int) * 8) - 1); // ������� ����� ��� �������� ������� ����
        cout << "�������� ������������� �����: " << num << endl;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            if (i % 8 == 0) {
                cout << " "; // ���������� ������ 4 ������� ��� ���������������
            }
            cout << ((num & mask) ? '1' : '0'); // ���������� ������� �������� � ��� ��������� �������� �����
            num <<= 1;// �������� ����� �� 1 ��� �����
        }
        cout << endl;
    }


          break;

    case 3: {
        cout << "������� ������������ �����: ";
        float float_num;
        unsigned int float_mask;

        cin >> float_num;
        cout << "\n";


        float_mask = 1 << ((sizeof(float) * 8) - 1);

        union {
            int intMemory;
            float floatMemory;
        };

        floatMemory = float_num;

        for (int i = 0; i <= sizeof(float) * 8; i++) {
            cout << ((float_mask & intMemory) ? 1 : 0);
            float_mask >>= 1;

            if (i % 8 == 0) {
                cout << " ";
            }
        }
    }
          break;
    case 4: {
        double double_num;
        int double_order;
        unsigned int double_mask;

        cout << "������� ������������ ����� � ���������� ���������: ";
        cin >> double_num;
        cout << "\n";

        double_order = sizeof(double_num) * 8 - 1;
        double_mask = 1 << double_order;

        union {
            int intMemory[2];
            double doubleMemory;
        };

        doubleMemory = double_num;

        for (int i = 0; i <= (double_order / 2); i++) {
            cout << ((double_mask & intMemory[1]) ? 1 : 0);
            double_mask >>= 1;

            if (!i or i == 11)
                cout << " ";
        }


        double_mask = 1 << double_order;

        for (int i = 0; i <= (double_order / 2); i++) {
            cout << ((double_mask & intMemory[0]) ? 1 : 0);
            double_mask >>= 1;
        }
    }
          break;

    case 5: {
        int num;
        cout << "������� ����� �����: ";
        cin >> num;

        int mask = 1 << ((sizeof(int) * 8) - 1);
        cout << "�������� ������������� �����: " << num << endl;

        bool isPositive = num >= 0;

        for (int i = 0; i < sizeof(int) * 8; i++) {
            if (i % 8 == 0) {
                cout << " ";
            }
            if (isPositive && i % 2 == 0) {
                cout << '1';
            }
            else if (!isPositive && i % 2 == 1) {
                cout << '0';
            }
            else {
                cout << ((num & mask) ? '1' : '0');
            }
            num <<= 1;  // �������� ����� �� 1 ��� �����
        }
        cout << endl;

    }
          break;
    case 6: {
        float float_num;
        unsigned int float_mask;

        cout << "������� ������������ �����: ";
        cin >> float_num;
        cout << "\n";

        float_mask = 1u << ((sizeof(float) * 8) - 1);

        union {
            int intMemory;
            float floatMemory;
        };

        floatMemory = float_num;

        bool isPositive = float_num >= 0;

        for (int i = 0; i < sizeof(float) * 8; i++) {
            if (i % 8 == 0) {
                cout << " ";
            }
            if (isPositive && i % 2 == 0) {
                cout << '1';
            }
            else if (!isPositive && i % 2 == 1) {
                cout << '0';
            }
            else {
                std::cout << ((float_mask & intMemory) ? 1 : 0);
                float_mask >>= 1;
            }
        }
        cout << endl;


    }
          break;
         
    }
    return 0;
    }



      











