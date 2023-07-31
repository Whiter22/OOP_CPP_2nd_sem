#include "Fabryka.h"
#include "Baza.h"
import <iostream>;

size_t gen_num(size_t start, size_t end);

Baza::Baza() : size_arr{ gen_num(1,10) } {
	//Fundusze_arr = new Fundusz * [size_arr];
	for (size_t ind = 0; ind < size_arr; ind++) {
		//Fundusze_arr[ind] = new Fundusz;
		Fundusze_arr.push_back(new Fundusz);
		//if (gen_num(0, 1) == 0)
		//	Produkcja_arr.push_back(new Huta);
		//else
		//	Produkcja_arr.push_back(new Fabryka_Wody);
	}
}

Baza::Baza(size_t arr_size) : size_arr(arr_size), Fundusze_arr(arr_size, nullptr) {
	/*for (size_t ind = 0; ind < size_arr; ind++)
		Fundusze_arr[ind] = new Fundusz;*/
}

Baza::~Baza() {
	for (size_t i = 0; i < size_arr; ++i) {
		delete Fundusze_arr[i];
	}
	//delete[] Fundusze_arr;
	//Fundusze_arr = nullptr;
	//size_arr = 0;
}

Baza::Baza(const Baza& other) : size_arr(other.size_arr)/*, Fundusze_arr(new Fundusz* [other.size_arr])*/
{
	Fundusze_arr.reserve(size_arr);
	/*for (size_t i = 0; i < size_arr; ++i)
	{
		Fundusze_arr[i] = new Fundusz(*other.Fundusze_arr[i]);
	}*/
	for (auto& fab : other.Fundusze_arr) {
		Fundusze_arr.push_back(new Fundusz(*fab));
	}
}
/*Baza::Baza(const Baza& Baza) {
	auto copy_Fundusze_arr = new Gracz*[size_arr];
	for (size_t i = 0; i < size_arr; ++i){
		copy_Fundusze_arr[i] = new Gracz(*Baza.Fundusze_arr[i]);
	}
}*/

void Baza::dodaj_gracza() {
	//auto new_Fundusze_arr = new Fundusz * [size_arr + 1];
	/*for (size_t i = 0; i < size_arr; ++i) {
		new_Fundusze_arr[i] = Fundusze_arr[i];
	}
	new_Fundusze_arr[size_arr] = new Fundusz;
	delete[] Fundusze_arr;
	Fundusze_arr = new_Fundusze_arr;*/
	//file << "ID Gracza: " << Fundusze_arr[size_arr]->Get_fab_id << "fundusz: " << Fundusze_arr[size_arr]->Get_fab_fundusz;
	++size_arr;
	Fundusze_arr.push_back(new Fundusz);
}

void Baza::usun_gracza() {
	if (!Fundusze_arr.empty()) {
		delete Fundusze_arr.back();
		Fundusze_arr.pop_back();
		--size_arr;
	}
	/*auto new_Fundusze_arr = new Fundusz * [size_arr - 1];
	for (size_t i = 0; i < size_arr - 1; ++i) {
		new_Fundusze_arr[i] = Fundusze_arr[i];
	}
	delete Fundusze_arr[size_arr - 1];
	delete[] Fundusze_arr;
	Fundusze_arr = new_Fundusze_arr;*/
	//--size_arr;
}

/*void Baza::print() {
	for (size_t i=0; i < size_arr; ++i) {
		std::cout << "ID Gracza: " << Fundusze_arr[i]->Get_fab_id() << " " << " " << "fundusz: " << Fundusze_arr[i]->Get_fab_fundusz() << '\n';
	}
	std::cout << std::endl;
}*/

void Baza::more_than() {
	//size_t max = Fundusze_arr[0]->Get_fab_fundusz();
	for (size_t i = 0; i < size_arr; ++i) {
		if (Fundusze_arr[i]->Get_fab_fundusz() >= 16000) {
			std::cout << "BOGATA: " << "\n";
			std::cout << "ID FABRYKI: " << Fundusze_arr[i]->Get_fab_id() << " " << " " << "fundusz: " << Fundusze_arr[i]->Get_fab_fundusz() << '\n';
			std::cout << "<--------------------------------------------------------------------------------------------------------------------->" << '\n';
		}
		else if (Fundusze_arr[i]->Get_fab_fundusz() < 16000 && Fundusze_arr[i]->Get_fab_fundusz() >= 13500) {
			std::cout << "DOBRZE FINANSOWA: " << "\n";
			std::cout << "ID FABRYKI: " << Fundusze_arr[i]->Get_fab_id() << " " << " " << "fundusz: " << Fundusze_arr[i]->Get_fab_fundusz() << '\n';
			std::cout << "<--------------------------------------------------------------------------------------------------------------------->" << '\n';
		}
		else if (Fundusze_arr[i]->Get_fab_fundusz() < 13500 && Fundusze_arr[i]->Get_fab_fundusz() > 7000) {
			std::cout << "ŒREDNIO FINANSOWA: " << "\n";
			std::cout << "ID FABRYKI: " << Fundusze_arr[i]->Get_fab_id() << " " << " " << "fundusz: " << Fundusze_arr[i]->Get_fab_fundusz() << '\n';
			std::cout << "<--------------------------------------------------------------------------------------------------------------------->" << '\n';
		}
		else {
			std::cout << "S£ABO FINANSOWA: " << "\n";
			std::cout << "ID FABRYKI: " << Fundusze_arr[i]->Get_fab_id() << " " << " " << "fundusz: " << Fundusze_arr[i]->Get_fab_fundusz() << '\n';
			std::cout << "<--------------------------------------------------------------------------------------------------------------------->" << '\n';
		}
	}
	std::cout << "<--------------------------------------------------------------------------------------------------------------------->" << '\n';
	std::cout << "Srednia finansow: " << oblicz_srednia_wynikow() << std::endl;

}