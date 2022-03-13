
/*     6. Класс − множество set. Дополнительно перегрузить следующие операции:
     - − удалить элемент из множества (типа set-item);
     * − пересечение множеств;
     < − сравнение множеств.
*/

#include <iostream>
#include <Windows.h>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.

    set<int> mySet, mySet2;
    int n, delNum;
    cout << "Введите количество элементов в множестве set: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mySet.insert(rand() % 80);
    }
    for (auto& item : mySet)
    {
        cout << item << endl;
    }
  
    cout << "Введите число, которое хотите удалить: " << endl;
    cin >> delNum;
    if (mySet.find(delNum) != mySet.end()) {
        mySet.erase(delNum);
        cout << endl;
        for (auto& item : mySet)
        {
            cout << item << endl;
        }
    }
    else
    {
        cout << "Такого числа нет в множестве!" << endl;
    }
    cout << endl;
    cout << "Пересечение множеств: " << endl;
    cout << "Введите количество элементов " << endl;

    vector <int> v1;
    vector <int> v2;
    vector <int> v_intersection;

   // set <int> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        v1.push_back(rand() % 90);
        v2.push_back(rand() % 90);
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
   /* std::set_intersection(v1.begin(), v1.end(),
        v2.begin(), v2.end(),
        std::back_inserter(v_intersection));
    for (int n : v_intersection)
        std::cout << n << ' ';*/
    if (!v_intersection.empty()) {
        std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v_intersection));
        for (int n : v_intersection)
            std::cout << n << ' ';
    }
    else
    {
        cout << "Множества не пересекаются!" << endl;
    }
    cout << endl;
    cout << "Сравнение множеств: " << endl;
    cout << "Введите количество элементов в множестве set: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mySet.insert(rand() % 80);
        mySet2.insert(rand() % 80);
    }
    for (auto& item : mySet)
    {
        cout << item << endl;
    }
    cout << endl;
    for (auto& item : mySet2)
    {
        cout << item << endl;
    }
    if (mySet < mySet2) {
        cout << "Set1 меньше чем Set2" << endl;
    }
    else {
        cout << "Set1 больше чем Set2" << endl;
    }

    return 0;
}


