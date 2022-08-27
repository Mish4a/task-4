#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <windows.h>
using namespace std;
class Adress {
private:
	string city;
	string street;
	int building;
	int apartment;
public:
	void change_city(string city) {
		this->city = city;
	}
	void change_street(string street) {
		this->street = street;
	}
	void change_building(int building) {
		this->building = building;
	}
	void change_apartment(int apartment) {
		this->apartment = apartment;
	}
	string output_line() {
		string a = this->city + ", " + this->street + ", " + to_string(this->building) + ", " + to_string(this->apartment);
		return a;
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string city;
	string street;
	int building;
	int apartment;
	Adress adress;
	ifstream in_adress("in.txt");
	if (!in_adress.is_open()) {
		cout << "Файл 'in.txt' не обнаружен.";
		return 1;
	}
	ofstream out_adress("out.txt");
	int n;
	in_adress >> n;
	set <string> mass;
	for (int i = 0; i < n; i++) {
		in_adress >> city >> street >> building >> apartment;
		adress.change_city(city);
		adress.change_street(street);
		adress.change_building(building);
		adress.change_apartment(apartment);
		mass.insert(adress.output_line());
	}
	out_adress << n << endl;
	for (auto i : mass) {
		out_adress << i << endl;
	}
	return 0;
}