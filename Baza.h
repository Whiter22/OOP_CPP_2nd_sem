#pragma once
#include "Fabryka.h"
import <ostream>;
import <iostream>;
import <vector>;
import <string>;
class Baza {
    size_t size_arr{};
    //Fundusz** Fundusze_arr{ nullptr };
    std::vector<Fundusz*> Fundusze_arr;
    //std::vector<Produkcja*> Produkcja_arr;
    class Statystyki {
        friend class Baza;

        size_t ilosc_wynikow{};
        size_t suma_wynikow{};

    public:
        void dodaj_wynik(size_t wynik) {
            suma_wynikow += wynik;
            ++ilosc_wynikow;
        }

        size_t oblicz_srednia_wynikow() const {
            return suma_wynikow / ilosc_wynikow;
        }
    };
public:
    Baza();
    Baza(size_t arr_size);
    ~Baza();
    Baza(const Baza& other);
    void dodaj_gracza();
    void usun_gracza();
    //void print();
    size_t Get_Size() { return size_arr; };
    void more_than();
    //Produkcja* GetProdbyInd(short ind) { return (ind < Produkcja_arr.size()) ? Produkcja_arr[ind] : nullptr; };

    size_t oblicz_srednia_wynikow() const {
        static Statystyki statystyki;
        for (size_t i = 0; i < size_arr; ++i) {
            statystyki.dodaj_wynik(Fundusze_arr[i]->Get_fab_fundusz());
        }
        return statystyki.oblicz_srednia_wynikow();
    }

    friend std::ostream& operator<<(std::ostream& out, const Baza& b) {
        for (size_t i = 0; i < b.size_arr; ++i) {
            out << "ID Fabryki: " << b.Fundusze_arr[i]->Get_fab_id() << " " << " " << "fundusz: " << b.Fundusze_arr[i]->Get_fab_fundusz() << '\n';
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& is, Baza& b) {
        b.Fundusze_arr.resize(b.size_arr);
        for (int i = 0; i < b.size_arr; ++i) {
            size_t id, pkt;
            is >> id >> pkt; //b.Fundusze_arr.push_back(new Fundusz(id, pkt));
            b.Fundusze_arr[i] = new Fundusz(id, pkt);
        }
        //b.size_arr = b.Fundusze_arr.size();
        return is;
    }
    Baza& operator=(const Baza& right) {
        if (&right != this) {
            this->Baza::~Baza();
            this->Baza::Baza(right);
        }
    }
    Fundusz* operator [](const size_t size) {
        return Fundusze_arr[size];
    }
    //Produkcja* operator [](const short x) {
    //    //int ind = std::stoi(strInd);
    //    //std::cout << ind << '\n';
    //    return Produkcja_arr[x];
    //}
};
