/*


*/

#include "my.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i, // переменная меню
        n = 2; // количество чисел(от 2 до 100)
    double a = 0;

    do {
        i = Menu();
        switch (i) {
        case 1: // ввод данных с клавиатуры
            n = InputKeyBoard();
            while (n < 2 || n > 100) {
                cout << "Ввод некорректен. Попробуйте ещё." << endl;
                system("pause");
                n = InputKeyBoard();
            }
            cout << "Вы ввели:\n" << n << endl << endl;
            system("pause");
            break;
        case 2: // ввод данных из файла
            n = InputFile();
            system("pause");
            break;
        case 3: // рекурсия
            a = Recursion(n);
            cout << "Полученный результат:\n" << a << " для k = " << n << "." << endl;
            system("pause");
            break;
        case 4: // цикл
            a = Check(n);
            cout << "Полученный результат:\n" << a << " для k = " << n << "." << endl;
            system("pause");
            break;
        case 5: // вывод результата в файл
            OutputFile(a, n);
            cout << "В файл output.txt было записано следующее: " << a << " для k = " << n << endl;
            system("pause");
            break;
        case 6: // выход
            cout << "Программа завершена успешно." << endl;
            break;
        }
    } while (i != 6);
}

