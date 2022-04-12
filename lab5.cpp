
//6)	Перевод числа из тринадцатеричной системы счисления в восьмеричную.

#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

char digit(int num)
{
    switch (num) {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    }
}
// Получение целой части числа
//int dectox_int(int a, int p, char* s)
//{
//    int num = a;
//    int rest = num % p;
//    num /= p;
//    if (num == 0)
//    {
//        s[0] = digit(rest); return 1;
//    }
//    int k = dectox_int(num, p, s);
//    s[k++] = digit(rest);
//    return k;
//}
// Получение дробной части числа
//void dectox_double(double a, int p, char* s)
//{
//    int iter = 0;
//    int k = 0;
//    double a1 = a;
//    do {
//        a1 = a1 * p;
//        int num = (int)(a1);
//        s[k++] = digit(num);
//        a1 -= (int)a1;
//        iter++;
//    } while (a1 > 0.00000001 && iter < 10);
//    s[k] = '\0';
//}

class Translate
{
public:
    class TranslateEx { };//класс исключений
    Translate();
    Translate(string rNum) {
        /*  if (stof(rNum) > std::numeric_limits<float>::max() || stof(rNum) < std::numeric_limits<float>::lowest()) {
              throw TranslateEx();
          }*/
        real_num = rNum;
    }
    void GetNum();
    int conversion_to_int(string s);
    float conversion_to_int_float_part(string s);
    int conversion_to_other_int(int a, int p, char* s/*int num*/);
    void conversion_to_other_float(float a, char* s);
    void TranslateToEight();
    ~Translate();

private:
    string real_num;
};

Translate::Translate()
{
    real_num = 0.0;
}
int Translate::conversion_to_int(string s)
{
    double result = 0;
    int digits = s.length();
    double razr;
    double osn = 13;
    for (int i = digits; i > 0; i--)
    {
        for (int b = 0; b <= 13; b++)
        {
            if (s[digits - i] == digit(b))
            {
                razr = b;
                break;
            }
            if (b == 13)
            {
                throw TranslateEx();
            }
        }
        result = result + razr * pow(osn, i - 1);

    }
    return (int)result;
}
float Translate::conversion_to_int_float_part(string s)
{
    float result = 0;
    int digits = s.length();
    float razr = 0;
    float osn = 13;
    int j = 0;
    for (int i = digits; i > 0; i--)
    {
        for (int b = 0; b <= 13; b++)
        {
            if (s[digits - i] == digit(b))
            {
                razr = b;
                break;
            }
            if (b == 13)
            {
                throw TranslateEx();
            }
        }
        j++;
        //razr = razr * pow(osn, -1 * j);
        result = result + razr * pow(osn, -1 * j);
    }
    return result;
}
//перевод из десятичной в восьмиричную целую часть
int Translate::conversion_to_other_int(int a, int p, char* s/*int num*/) // num - число
{
    int num = (int)a;
    int rest = num % p;
    num /= p;
    if (num == 0)
    {
        s[0] = digit(rest); return 1;
    }
    int k = conversion_to_other_int(num, p, s);
    s[k++] = digit(rest);
    return k;

    /*int osn = 8;
    string number;
    int ostatok;
    while (num > osn)
    {
        ostatok = num % osn;
        number = number + digit(ostatok);
        num = num / osn;
    }
    number = number + digit(num);
    reverse(number.begin(), number.end());
    return number;*/

}
//перевод из десятичной в восьмиричную дробную часть
void Translate::conversion_to_other_float(float a, char* s) // num - число
{
    int p = 8;
    int iter = 0;
    int k = 0;
    float a1 = a;
    do {
        a1 = a1 * p;
        int num = (int)(a1);
        s[k++] = digit(num);
        a1 -= (int)a1;
        iter++;
    } while (a1 > 0.00000001 && iter < 10);
    s[k] = '\0';

}
void Translate::GetNum()
{
    cout << "Введите число в тринадцатеричной системе счисления: "; cin >> real_num;
    /*if (stof(real_num) > std::numeric_limits<float>::max() || stof(real_num) < std::numeric_limits<float>::lowest())
    {
        throw TranslateEx();
    }*/
}

void Translate::TranslateToEight()
{
    char s[80] = { 0 };
    int intPartToComma, p = 8;
    float intPartAfterComma, result;
    int pos = real_num.find(".");
    string subToComma = real_num.substr(0, pos); //отделили целую часть от дробной
    intPartToComma = conversion_to_int(subToComma);
    string subAfterComma = real_num.substr(pos + 1); //отделили числа после запятой
    int k = conversion_to_other_int(intPartToComma, p, s);
    result = conversion_to_int_float_part(subAfterComma);
    s[k++] = ',';
    conversion_to_other_float(result, &s[k]);

    cout << "Ваше число в восьмеричной системе счисления : " << s << endl;
    cin.get(); cin.get();
}

Translate::~Translate()
{
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
    try {
        Translate trans;
        trans.GetNum(); //считываем число для перевода
        trans.TranslateToEight();
    }
    catch (Translate::TranslateEx) //ловим исключение
    {
        cout << "\nВведено некорректное значение!";
    }
    return 0;
}

