#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Выберите номер задание:";
    int choose, num = -1;
    cin >> choose;

    switch (choose) {

    case 0: {
        cout << "Работа программы завершена" << endl;
        choose = -1;
    }
          break;

    case 1: {
        cout << "int занимает " << sizeof(int) << " байт(а)" << endl;
        cout << "short int занимает " << sizeof(short int) << " байт(а)" << endl;
        cout << "long int занимает " << sizeof(long int) << " байт(а)" << endl;
        cout << "float занимает " << sizeof(float) << " байт(а)" << endl;
        cout << "double занимает " << sizeof(double) << " байт(а)" << endl;
        cout << "long double занимает " << sizeof(long double) << " байт(а)" << endl;
        cout << "char занимает " << sizeof(char) << " байт(а)" << endl;
        cout << "bool занимает " << sizeof(bool) << " байт(а)" << endl;

    }
          break;

    case 2: {
        cout << "Введите целое число: ";
        cin >> num;
        int mask = 1 << ((sizeof(int) * 8) - 1); // Создаем маску для проверки каждого бита
        cout << "Двоичное представление числа: " << num << endl;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            if (i % 8 == 0) {
                cout << " "; // Разделение каждых 4 разряда для удобочитаемости
            }
            cout << ((num & mask) ? '1' : '0'); // Используем битовую операцию И для получения значений битов
            num <<= 1;// Сдвигаем число на 1 бит влево
        }
        cout << endl;
    }


          break;

    case 3: {
        cout << "Введите вещественное число: ";
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

        cout << "Введите вещественное число с повышенной точностью: ";
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
        cout << "Введите целое число: ";
        cin >> num;

        int mask = 1 << ((sizeof(int) * 8) - 1);
        cout << "Двоичное представление числа: " << num << endl;

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
            num <<= 1;  // Сдвигаем число на 1 бит влево
        }
        cout << endl;

    }
          break;
    case 6: {
        float float_num;
        unsigned int float_mask;

        cout << "Введите вещественное число: ";
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



      











