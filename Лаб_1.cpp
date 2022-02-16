

#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>

using namespace std;

class Train
{
private:
	string Destination, time, type_of_train;
	int num_of_train, num_of_seats;
	int* p;
public:
	//Train(string destination, string time, string type_of_train, int num_of_train, int num_of_seats);
	
	Train();

	string Set_Destination(string Dest) { Destination = Dest; }
	string Set_Time(string Time) { time = Time; }
	string Set_Type(string Type_of_train) { type_of_train = Type_of_train; }
	int Set_Num(int Num_of_Train) { num_of_train = Num_of_Train; }
	int Set_Seats(int Num_of_Seats) { num_of_seats = Num_of_Seats; }
	string Get_Destination() { return Destination; }
	string Get_Time() { return time; }
	string Get_Type() { return type_of_train; }
	int Get_Num() { return num_of_train; }
	int Get_Seats() { return num_of_seats; }
	~Train();
};


Train::Train()
{
	p = new int[100];
}

Train::~Train() { delete p; };

int main()
{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
	string Destination_, time_, type_of_train_;
	int num_of_train_ = 0, num_of_seats_ = 0;
	int n;
	cout << "Введите количество поездов:" << endl;
	cin >> n;
	Train* info = new Train[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите пункт достижения:" << endl;
		cin >> Destination_;
		cout << "Введите время отправления:" << endl;
		cin >> time_;
		cout << "Введите номер поезда:" << endl;
		cin >> num_of_train_;
		cout << "Введите тип вагона (плацкарт/купе):" << endl;
		cin >> type_of_train_;
		cout << "Введите количество общих мест:" << endl;
		cin >> num_of_seats_;

		info[i].Set_Destination(Destination_);
		info[i].Set_Time(time_);
		info[i].Set_Type(type_of_train_);
		info[i].Set_Num(num_of_train_);
		info[i].Set_Seats(num_of_seats_);
	}
	cout << "Выберите действия: " << endl << "1 Получить список поездов, следующих до заданного пункта назначения" << endl <<
		"2 Получить список поездов, следующих до заданного пункта назначения и отправляющихся после заданного часа" << endl <<
		"3 Получить список поездов, отправляющихся до заданного пункта назначения и имеющих общие места" << endl <<
		"-----------------------------------------------------------------------------" << endl;;
	int choice = 0;
	cin >> choice;
	string ToReplace = ":", ReplaceWith = ",";
	switch (choice)
	{
	case 1:
		cout << "Введите пункт достижения:" << endl;
		cin >> Destination_;
		for (int i = 0; i < n; i++) {
			if (info[i].Get_Destination() == Destination_)
			{
				cout << info[i].Get_Num() << "\t" << info[i].Get_Time() << "\t" << info[i].Get_Seats() << "\t" << info[i].Get_Type() << endl;
			}
			//else cout << "Нет поездов, следующих до " << Destination_ << endl;
		}
		break;
	case 2:
		cout << "Введите пункт назначения и время:" << endl;
		cin >> Destination_ >> time_;
		time_.replace(time_.find(ToReplace), ToReplace.length(), ReplaceWith);
		for (int i = 0; i < n; i++) {
			info[i].Get_Time().replace(info[i].Get_Time().find(ToReplace), ToReplace.length(), ReplaceWith);
			if ((info[i].Get_Destination() == Destination_) && (atof(info[i].Get_Time().c_str()) > atof(time_.c_str())))
			{
				cout << info[i].Get_Num() << "\t" << info[i].Get_Seats() << "\t" << info[i].Get_Type() << endl;
			}
			//else cout << "Нет поездов, следующих до " << Destination_ << " и отправляющихся в "<<time_<< endl;
		}
		break;
	case 3:
		cout << "Введите пункт назначения и общие места:" << endl;
		cin >> Destination_ >> num_of_seats_;
		for (int i = 0; i < n; i++) {
			if ((info[i].Get_Destination() == Destination_) && (info[i].Get_Seats() == num_of_seats_))
			{
				cout << info[i].Get_Num() << "\t" << info[i].Get_Time() << "\t" << info[i].Get_Type() << endl;
			}
			//else cout << "Нет поездов, следующих до " << Destination_ << " и имеющих " << num_of_seats_ <<" мест"<< endl;
		}
		break;
	default: cout << "Вы ввели не то число" << endl;
		break;
	}

	system("pause>null");
	return 0;
}
