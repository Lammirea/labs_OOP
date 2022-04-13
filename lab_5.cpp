
//6.	Используйте шаблон map для исключения повторов среди множества целых чисел. 

#include <iostream>
#include <Windows.h>
#include <map>
#include <random>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
    map <int, int> container , container2;
    map <int, int>::iterator m_Iter;
    int n , delNum , counNum;
    cout << "Введите количество элементов контейнера:" << endl;
    cin >> n;
    srand(time(NULL));
    //заполнение map случанйми числами:
    for (int i = 0; i < n; i++)
    {
        container.insert({ i, rand() % 100 });
    }
    //вывод содержимого контейнера на экран:
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " : " << container[i] << endl;
    }
    cout << endl;
    //Изменить контейнер, удалив из него одни элементы и заменив другие
    cout << "Введите порядковый номер элемента, который вы хотите удалить:" << endl;
    cin >> delNum;
    m_Iter = container.find(delNum - 1);
    if (m_Iter != container.end())
        container.erase(m_Iter);
    else { cout << "Такого элемента нет в контейнере." << endl; }
    cout << endl;
    cout << "Вид контейнера после удаления одного элемента и изменения оставшихся:" << endl;
    srand(time(NULL));

    cout << endl;
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        it->second = rand() % 200;
        container.insert({ it->first,it->second });
    }
    //вывод содержимого контейнера на экран c использованием итераторов:
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        cout << it->first + 1 << " : " << it->second << endl;///вывод на экран
    }
    //Создать второй контейнер этого же класса и заполнить его данными того же типа, что и первый контейнер
    container.swap(container2);
    cout << "Заполнение второго контейнера элементами перого : "<<endl;
    for (auto m_Iter = container2.begin(); m_Iter != container2.end(); ++m_Iter)
        cout << m_Iter->first + 1 << " : " << m_Iter->second << endl;

    //Изменить первый контейнер, удалив из него n элементов после заданного и добавив затем в него все элементы из второго контейнера.
    cout << "\nИзменяем первый контейнер:" << endl;
    for (int i = 0; i < n; i++)
    {
        container.insert({ i, rand() % 100 });
    }
    cout << "Введите порядковый номер элемента, после которого удалятся другие в первом контейнере : " << endl;
    cin >> counNum;
    //auto itr = container.find(counNum - 1);
    m_Iter = container.find(counNum - 1);
    container.erase(m_Iter,container.end());
   // container[container2.size()] = container2;
    m_Iter = container.end();
    for (auto it = container2.begin(); it != container2.end(); ++it)
    {
        container[m_Iter->second] = it->second;
    }
    m_Iter++;
    //Просмотреть первый и второй контейнеры.
    cout << "\nПервый контейнер :" << endl;
    for (m_Iter = container.begin();  m_Iter != container.end();  m_Iter++)
    {
        cout << m_Iter->first + 1 << " : " << m_Iter->second << endl;///вывод на экран
    }
   
    cout << "\nВторой контейнер :" << endl;
    for (auto it = container2.begin(); it != container2.end(); ++it)
    {
        cout << it->first + 1 << " : " << it->second << endl;///вывод на экран
    }

	return 0;
}


