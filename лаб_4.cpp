
/*     6. Класс − множество set. Дополнительно перегрузить следующие операции:
     - − удалить элемент из множества (типа set-item);
     * − пересечение множеств;
     < − сравнение множеств.
*/

/*#include <iostream>
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
        std::cout << n << ' ';
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
}*/

#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>


//void HeapSort(std::vector<int>& values) {
//    std::make_heap(values.begin(), values.end());
//    for (auto i = values.end(); i != values.begin(); --i) {
//        std::pop_heap(values.begin(), i);
//    }
//}

template<class T>
class Set
{
public:
    Set(){};
    Set(int amount) {
        std::cout << "Введите количество элементов в множестве set: " << std::endl;
        std::cin >> amount;
        std::cout << "Введите элементы множества:" << std::endl;
        for (int i = 0; i < amount; i++)
        {
            std::cin >> num;
            value.push_back(num);
        }
        
        //пирамидальная сортировка:
        HeapSort(value);
    }
    void DeleteNum() {
        std::cout << "Введите элемент,который хотите удалить:" << std::endl;
        std::cin >> delNum;
        value.erase(std::remove(value.begin(), value.end(), delNum), value.end());
    }
    void HeapSort(std::vector<T>& values) {
        std::make_heap(values.begin(), values.end());
        for (auto i = values.end(); i != values.begin(); --i) {
            std::pop_heap(values.begin(), i);
        }
    }
    Set operator * (Set<T> mul1) {
        std::cout << std::endl;
        for (T i : value)
        {
            for (T j : mul1.value)
            {
                if (i == j) std::cout << i << "\t";
            }
        }
        return *this;
    }

    bool operator < (Set<T> compareItem1) {
        for (T i : value ) {
            for (T j : compareItem1.value) {
                if (i < j) { return true; }
                else
                {
                    return false;
                }
            }
        }
    }

    void PrintSet() {
        std::cout << std::endl;
        for (int i : value)
        {
            std::cout << i << std::endl;
        }
    }
    ~Set() {
        value.clear();
    };

private:
    int n = 0;
    T num, delNum;
    std::vector<T> value;
};

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.

    //удаление элемента из множества:
    Set<int> TSet(1);
    TSet.DeleteNum();
    TSet.PrintSet();

    std::cout << "Пересечение множеств:" << std::endl;
    Set<int> TSetMul1(1);
    Set<int> TSetMul2(1);
    TSetMul1 = TSetMul1 * TSetMul2;
   
    std::cout << std::endl;
    std::cout << "Сравнение множеств:" << std::endl;
    Set<int> TSetComp1(1);
    Set<int> TSetComp2(1);
    std::cout << (TSetComp1 < TSetComp2 ?  "Первое множество меньше второго" : "Второе множество меньше первого") << std::endl;
    return 0;
}
//template<class T>
//bool operator < (Set<T> compareItem1, Set<T> compareItem2)
//{
//   
//    //return false;
//}
