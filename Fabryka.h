#pragma once
import <string>;
import <iostream>;
import <iomanip>;
//import <Windows.h>;

size_t gen_num(size_t start, size_t end);


class Fundusz { // class Produkcja
	size_t id_fab{};
	size_t fundusz{};
public:
	//static Elektrownia elektr;
	//static Kopalnia kop;
	Fundusz();
	Fundusz(size_t id, size_t pkt);
	size_t Get_fab_id() const;
	size_t Get_fab_fundusz();
	void set_fundusz(size_t val) { fundusz = val; };
	Fundusz(const Fundusz& other) {
		id_fab = other.id_fab;
		fundusz = other.fundusz;
	};
};

class Kopalnia {
	size_t wegiel{0};
public:
	Kopalnia() : wegiel{gen_num(10,20)} {};
	size_t Get_wegiel() { return wegiel; };
	void set_wegiel(size_t val) { wegiel = val; };
};

class Elektrownia {
	size_t energia{0};
public:
	Elektrownia() : energia{ gen_num(3,12) } {};
	size_t Get_energia() { return energia; };
	void set_energia(size_t val) { energia = val; };
};

class Produkcja {
protected:
	static Fundusz fundusze;
	static Kopalnia kopalnia;
	static Elektrownia elektrownia;
public:
	void virtual ulepsz() = 0; // zaleznie od klasy inne atrybuty boostowane
	void virtual wydobywaj() = 0;
	void virtual pokaz_zasoby() = 0;
	std::string virtual get_nazwa() = 0;
	size_t virtual get_materialy() const = 0;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Fabryka_Wody : public Produkcja {
	std::string nazwa = "Fabryka Wody";
protected:
	size_t woda{0};
	size_t oczyszczona_woda{0};
	short x=4;
public:
	Fabryka_Wody() : woda{ gen_num(40, 100) } {};
	virtual void wydobywaj() {
		if (elektrownia.Get_energia() >= 8 && kopalnia.Get_wegiel() >= 15) {
			oczyszczona_woda = woda / x;
			fundusze.set_fundusz(fundusze.Get_fab_fundusz() - 350);
			elektrownia.set_energia(elektrownia.Get_energia()-5);
			kopalnia.set_wegiel(kopalnia.Get_wegiel() - 10);
		}
		else {
			//Elektrownia::wydobywaj();
			//Kopalnia::wydobywaj();
			elektrownia.set_energia(elektrownia.Get_energia() + gen_num(3, 10));
			kopalnia.set_wegiel(kopalnia.Get_wegiel() + gen_num(10, 20));
			oczyszczona_woda = woda / x;
			fundusze.set_fundusz(fundusze.Get_fab_fundusz() - 500);
			elektrownia.set_energia(elektrownia.Get_energia()+5);
			kopalnia.set_wegiel(kopalnia.Get_wegiel() + 10);
		}// dodac else 
	}; // dodac if ze jesli energia ponizej iles i wegiel ponizej iles to nie da rady 
	virtual void ulepsz() {
		//fundusz -= 6500;
		fundusze.set_fundusz(fundusze.Get_fab_fundusz() - 6500);
		x = 2;
	};
	virtual void pokaz_zasoby() {
		std::cout << "Woda: " << woda <<'\n' << "Oczyszczona Woda: " << oczyszczona_woda << '\n' << "Wegiel: " << kopalnia.Get_wegiel() << '\n' << "Energia: " << elektrownia.Get_energia() << '\n' << "Fundusz: " << fundusze.Get_fab_fundusz() << std::endl;
	};
	virtual std::string get_nazwa() { return nazwa; };
	virtual size_t get_materialy() const { return woda + oczyszczona_woda; }
};

class Huta : public Produkcja {
	std::string nazwa = "Huta";
	size_t metal{0}, stal{};
	bool ulepszona = false;
public:
	Huta() : metal{ gen_num(50,100) } {};
	virtual void wydobywaj() {
		if (elektrownia.Get_energia() >= 10 && kopalnia.Get_wegiel() >= 20 /*&& woda >= 10*/) {
			if (ulepszona == true)
				stal = metal / 2;
			fundusze.set_fundusz(fundusze.Get_fab_fundusz() - 500);
			metal += gen_num(20, 80);
			elektrownia.set_energia(elektrownia.Get_energia()-8);
			kopalnia.set_wegiel(kopalnia.Get_wegiel() - 10);
			//woda -= 10;
		}
		else {
			//std::cout << "Za mala ilosc energi potrzeba uruchomienia elektrowni!!" << std::endl;
			//Fabryka_Wody::wydobywaj();
			if (ulepszona == true)
				stal = metal / 2;
			fundusze.set_fundusz(fundusze.Get_fab_fundusz() - 650);
			metal += gen_num(20, 80);
			elektrownia.set_energia(elektrownia.Get_energia()+8);
			kopalnia.set_wegiel(kopalnia.Get_wegiel() + 10);
			//woda -= 10;
		}
	};
	virtual void ulepsz() {
		if (fundusze.Get_fab_fundusz() >= 7500) {
			fundusze.set_fundusz(fundusze.Get_fab_fundusz() - 7500);
			ulepszona = true;
			std::cout << "Ulepszono pomyslnie!!!" << std::endl;
		}
		else
			std::cout << "Za maly budzet!!!" << std::endl;
	};
	virtual void pokaz_zasoby() {
		if (ulepszona == false)
			std::cout << "Metal kg: " << metal << '\n' << "Fundusz: " << fundusze.Get_fab_fundusz() << '\n';
		else if (ulepszona == true)
			std::cout << "Metal kg: " << metal << '\n' << "Stal kg: " << stal <<'\n'<< "Fundusz: " << fundusze.Get_fab_fundusz() << '\n';
		std::cout << "Wegiel: " << kopalnia.Get_wegiel() << std::endl;
		std::cout <</* "Woda: " << woda << '\n' <<*/ "Energia: " << elektrownia.Get_energia() << std::endl;
	};
	virtual std::string get_nazwa() { return nazwa; };
	virtual size_t get_materialy() const { return metal + stal; }
};