#include "Fabryka.h"
import<iostream>;
import<vector>;
import<map>;
import<string>;
import<iterator>;
import<algorithm>;

class Baza_Fabryk {
	size_t size_arr{};
	//std::vector<Produkcja*> Produkcja_arr;
	std::vector<std::shared_ptr<Produkcja>> Produkcja_arr;
	//std::vector<Produkcja*> Prod_temp;
	//std::vector<Produkcja*>::reverse_iterator rev_it;
	struct Comparator {
		bool operator()(const size_t& a, const size_t& b) const {
			return a>b;
		}
	};
public:
	Baza_Fabryk();
	~Baza_Fabryk();
	std::shared_ptr<Produkcja> operator[](const short x) {
		if (x < size_arr)
			return Produkcja_arr[x];
		else
			std::cout << "Nie prawidlowy index!!" << std::endl;
	}
	size_t Get_Size() { return size_arr; }
	void naj_mat_mapa() {
		std::map<size_t, std::shared_ptr<Produkcja>, Comparator> fab_map;
		for (auto fab : Produkcja_arr) {
			fab_map[fab->get_materialy()] = fab;
		}
		for (auto& pair : fab_map) {
			std::cout << "Ilosc materialow: " << pair.first << " Fabryka: " << pair.second->get_nazwa() << std::endl;
		}							
	}
	static void print_Fab_nazwa(std::shared_ptr<Produkcja> fab, short index) { std::cout << "[" << index << "] " << fab->get_nazwa() << std::endl; }
	//void od_ostatniego() {
	//	for (rev_it = Produkcja_arr.rbegin(); rev_it != Produkcja_arr.rend(); rev_it++)
	//		std::cout << (*rev_it)->get_nazwa() << '\n';
	//}
	void reverse_Prod_arr() {
		//std::vector<Produkcja*> Temp;
		//std::copy(Produkcja_arr.begin(), Produkcja_arr.end(), Temp.begin());
		std::reverse(Produkcja_arr.begin(), Produkcja_arr.end());
	}
	void show_all_Fab() { short index = 0; std::for_each(Produkcja_arr.begin(), Produkcja_arr.end(), [&](const auto& element) { print_Fab_nazwa(element, index); index++; }); }
};