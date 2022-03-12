// лаб3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>

using namespace std;

//базовый класс:
class Company
{
public:
	Company();
	Company(string, int, int);
	void Set_Company_info(string estate_set, int num_of_workers_set, int money_set) { estate = estate_set; num_of_workers = num_of_workers_set; money = money_set; }
	string Get_Estate() { return estate; }
	int Get_num_of_workers() { return num_of_workers; }
	int Get_money_info() { return money; }

	~Company();

private:
	string estate; //имущество
	int num_of_workers, money;
};
Company::Company()
{
}

Company::Company(string Estate, int Num_Of_Workers, int Money)
{
	estate = Estate;
	num_of_workers = Num_Of_Workers;
	money = Money;
}

Company::~Company(){}

//наследник Страховая компания:
class InsuranceCompany : public Company
{
public:
	InsuranceCompany();
	InsuranceCompany(int);
	~InsuranceCompany();
	void Set_Ins_Company(int insured_sum_set) { insured_sum = insured_sum_set; }
	int Get_insured_sum() { return insured_sum; }

private:
	
	int insured_sum; //сумма страховки
};

InsuranceCompany::InsuranceCompany()
{
}
InsuranceCompany::InsuranceCompany( int insured_sum_info)
{
	insured_sum = insured_sum_info;
}

InsuranceCompany::~InsuranceCompany()
{
}
//наследник от Страховой компании - Фабрика:
class Factory : public InsuranceCompany
{
public:
	Factory();
	Factory(string, int);

	void Set_Factory_Info(string insured_estate_set, int insured_money_set) { insured_estate = insured_estate_set; insured_money = insured_money_set; }
	string Get_insured_estate() { return insured_estate; }
	int Get_insured_money() { return insured_money; }

	~Factory();

private:
	string insured_estate; //застрахованное имущество
	int insured_money; //застрахованный капитал
};

Factory::Factory(string insured_estate_info, int insured_money_info)
{
	insured_estate = insured_estate_info;
	insured_money = insured_money_info;
}

Factory::Factory()
{
}

Factory::~Factory()
{
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.

	std::vector<std::vector<std::string>> v;
	string Estate_info, insured_estate;
	int num_of_workers_info, money_info, insurance_sum, insuredMoney;
	int n;
	cout << "Введите целое неотрицательное число:" << endl;
	cin >> n;
	//Company* info_comp = new Company[n];
	//InsuranceCompany* info_insurance = new InsuranceCompany[n];
	Factory* info_factory = new Factory[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите имущество Вашей организации: " << endl;
		//while (std::getline(std::cin, Estate_info, '\n') && !Estate_info.empty())
		//{
		//	std::istringstream is(Estate_info);
		//	std::vector<std::string> row((std::istream_iterator<std::string>(is)),
		//		std::istream_iterator<std::string>());
		//	v.push_back(row);
		//}
		std::cin.ignore();
		std::getline(std::cin, Estate_info, '\n');
		cout << "Введите количество сотрудников Вашей организации: " << endl;
		cin >> num_of_workers_info;
		cout << "Введите бюджет организации (в рублях) : " << endl;
		cin >> money_info;
		cout << "Введите страховую сумму (в рублях) : " << endl;
		cin >> insurance_sum;
		cout << "Введите застрахованный капитал: " << endl;
		cin >> insuredMoney;
		cout << "Введите застрахованное имущество: " << endl;
		cin >> insured_estate;

		info_factory[i].Set_Company_info(Estate_info, num_of_workers_info, money_info);
		info_factory[i].Set_Ins_Company(insurance_sum);
		info_factory[i].Set_Factory_Info(insured_estate, insuredMoney);
	}
	cout << "Информация, которую вы ввели:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Порядковый номер: " << i + 1 << endl;
		/*for (const auto& row : v)
		{
			for (const auto& s : row) std::cout << s << ' ';
			std::cout << std::endl;
		}*/
		cout << info_factory[i].Get_Estate() << "\t" << info_factory[i].Get_num_of_workers() << "\t" << info_factory[i].Get_money_info() <<
			"\t" << info_factory[i].Get_insured_sum() << "\t" << info_factory[i].Get_insured_estate() << "\t"
			<< info_factory[i].Get_insured_estate() << endl;
	}
	
	return 0;
}


