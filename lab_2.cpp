
#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>

using namespace std;
class Observe;

class Train
{
private:
	//int* el;
	string Destination, time, type_of_train;
	int *num_of_train, *num_of_seats;
public:
	//Train(string, string, string, int, int);
	Train();
	Train(string, string, string, int, int);
	Train(const Train& trains);

	string Get_Destination() { return Destination; }
	string Get_Time() { return time; }
	string Get_Type() { return type_of_train; }
	int Get_Num() { return *num_of_train; }
	int Get_Seats() { return *num_of_seats; }
	void Set_Trains(string Dest, string Time, string Type_of_train, int Num_of_Train, int Num_of_Seats) {
		num_of_seats = new int; num_of_train = new int;
		Destination = Dest;  time = Time;
		type_of_train = Type_of_train;  *num_of_train = Num_of_Train; *num_of_seats = Num_of_Seats;
	}

	~Train();

	Train& operator=(const Train& trains) {
		//освобождаем память
		delete num_of_seats;
		delete num_of_train;

		num_of_seats = new int; num_of_train = new int;
		*num_of_train = *(trains.num_of_train);
		*num_of_seats = *(trains.num_of_seats);

		return *this;
	}
	friend bool operator == (Train& train_info_main, Train& train_info_comp);
	friend bool operator != (Train& train_info_main, Train& train_info_comp);
	friend void GetInfo(const Train& trains);
	friend class Observe;
};


Train::Train()
{
	num_of_train = num_of_seats = 0;
	Destination = time = type_of_train = " ";
}

Train::Train(string Dest, string Time, string Type_of_train, int Num_of_Train, int Num_of_Seats)
{
	Set_Trains(Dest, Time, Type_of_train, Num_of_Train, Num_of_Seats);
}

Train::Train(const Train& trains)
{
	Destination = trains.Destination;
	time = trains.time;
	type_of_train = trains.type_of_train; *num_of_train = *(trains.num_of_train); 
	*num_of_seats = *(trains.num_of_seats);
}

Train::~Train() {
	delete num_of_seats;
	delete num_of_train;
};

bool operator == (Train& train_info_main, Train& train_info_comp)
{
	if ((train_info_main.Destination != train_info_comp.Destination) || (train_info_main.time != train_info_comp.time) || (train_info_main.type_of_train != train_info_comp.type_of_train) ||
		(train_info_main.num_of_seats != train_info_comp.num_of_seats) || (train_info_main.num_of_train != train_info_comp.num_of_train)) {
		cout << "Значения не равны\n";
		return 0;
	}
	else {
		return 1;
	}
}
bool operator !=(Train& train_info_main, Train& train_info_comp) {
	if ((train_info_main.Destination == train_info_comp.Destination) || (train_info_main.time == train_info_comp.time) || (train_info_main.type_of_train == train_info_comp.type_of_train) ||
		(train_info_main.num_of_seats == train_info_comp.num_of_seats) || (train_info_main.num_of_train == train_info_comp.num_of_train)) {
		cout << "Значения равны\n";
		return 0;
	}
	else {
		return 1;
	}
}

class Observe
{
public:
	Observe();
	~Observe();
	friend void GetInfo(const Train& trains);
private:

};

Observe::Observe()
{
}

Observe::~Observe()
{
}
void GetInfo(const Train& trains)
{
	cout << "Сработал GetInfo" << endl << "Пункт назначения: " << trains.Destination << " Время отправления: " << trains.time << " Тип вагона: " << trains.type_of_train << endl;
	cout << "Номер поезда: " << *(trains.num_of_train) <<" Число мест "<< *(trains.num_of_seats) << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
	string Destination_, time_, type_of_train_;
	int num_of_train_ = 0, num_of_seats_ = 0;
	int n;
	cout << "Введите количество поездов:" << endl;
	cin >> n;
	Train* info_main = new Train[n];
	Train* info_comp = new Train[n];
	/////////////////////////////////////

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

		info_main[i].Set_Trains(Destination_, time_, type_of_train_, num_of_train_, num_of_seats_);
	}
	//присваивание
	if (info_comp == info_main) {
		cout << "Массивы одинаковые" << endl;
	}
	else {
		info_comp = info_main;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		GetInfo(info_comp[i]);
	}
	cout << endl;
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
			if (info_comp[i].Get_Destination() == Destination_)
			{
				cout << info_comp[i].Get_Num() << "\t" << info_comp[i].Get_Time() << "\t" << info_comp[i].Get_Seats() << "\t" << info_comp[i].Get_Type() << endl;
			}
		}
		break;
	case 2:
		cout << "Введите пункт назначения и время:" << endl;
		cin >> Destination_ >> time_;
		time_.replace(time_.find(ToReplace), ToReplace.length(), ReplaceWith);
		for (int i = 0; i < n; i++) {
			info_comp[i].Get_Time().replace(info_comp[i].Get_Time().find(ToReplace), ToReplace.length(), ReplaceWith);
			if ((info_comp[i].Get_Destination() == Destination_) && (atof(info_comp[i].Get_Time().c_str()) > atof(time_.c_str())))
			{
				cout << info_comp[i].Get_Num() << "\t" << info_comp[i].Get_Seats() << "\t" << info_comp[i].Get_Type() << endl;
			}
		}
		break;
	case 3:
		cout << "Введите пункт назначения и общие места:" << endl;
		cin >> Destination_ >> num_of_seats_;
		for (int i = 0; i < n; i++) {
			if ((info_comp[i].Get_Destination() == Destination_) && (info_comp[i].Get_Seats() == num_of_seats_))
			{
				cout << info_comp[i].Get_Num() << "\t" << info_comp[i].Get_Time() << "\t" << info_comp[i].Get_Type() << endl;
			}
		}
		break;
	default: cout << "Вы ввели не то число" << endl;
		break;
	}

	system("pause>null");
	return 0;
}


