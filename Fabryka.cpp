#include "Fabryka.h"
import <iostream>;


Fundusz Produkcja::fundusze;
Kopalnia Produkcja::kopalnia;
Elektrownia Produkcja::elektrownia;
size_t gen_num(size_t start, size_t end);

Fundusz::Fundusz() : id_fab{ gen_num(100000, 200000) }, fundusz{ gen_num(10000, 40000) } {}

Fundusz::Fundusz(size_t id, size_t pkt) : id_fab(id), fundusz(pkt) {}

size_t Fundusz::Get_fab_id() const {
	return id_fab;
}

size_t Fundusz::Get_fab_fundusz(){
	return fundusz;
}
/*
std::string Gracz::Get_gracz_nick() const
{
	return nick;
}
*/