#include "Baza_Fabryk.h"

Baza_Fabryk::Baza_Fabryk() : size_arr{gen_num(2,10)} {
	//Fundusze_arr.emplace_back(std::make_unique<Fundusz>());
	//auto back_insert_iter = std::back_inserter(Produkcja_arr);
	for (size_t ind = 0; ind < size_arr; ind++) {
		if (gen_num(0, 1) == 0)
			Produkcja_arr.push_back(std::make_shared<Fabryka_Wody>());//new Fabryka_Wody;
		else
			Produkcja_arr.push_back(std::make_shared<Huta>());
	}
	/*for (size_t ind = 0; ind < size_arr; ind++) {
		if (gen_num(0, 1) == 0)
			Produkcja_arr.push_back(new Fabryka_Wody);
		else
			Produkcja_arr.push_back(new Huta);
	}*/
}

Baza_Fabryk::~Baza_Fabryk(){
	//for (auto* fabryka : Produkcja_arr) {
	//	delete fabryka;
	//}
}