#include "Fabryka.h"
#include "Baza.h"
#include "Baza_Fabryk.h"
import <random>;
import <iostream>;
import <fstream>;
import <iomanip>;

size_t gen_num(size_t start, size_t end) {
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<size_t> uniformDist(start, end);
    return uniformDist(engine);
}

void menu() {
    Baza* baza{ nullptr };
    Baza* baza2{ nullptr };
    Baza* baza3{ nullptr };
    Baza_Fabryk* baza4{ nullptr };
    baza4 = new Baza_Fabryk;
    std::ofstream file("Dane_baza.txt");
    std::ifstream plik("Dane_dla_obiektu.txt");
    size_t choice{};
    do {
        std::cout << "Menu\n\n";
        std::cout << "1. Stworz Baze" << std::endl;
        std::cout << "2. Pokaz baze" << std::endl;
        std::cout << "3. Dodaj gracza" << std::endl;
        std::cout << "4. Usun gracza" << std::endl;
        std::cout << "5. Pokaz wyniki" << std::endl;
        std::cout << "6. Skopiuj Baze" << std::endl;
        std::cout << "7. Pokaz skopiowana baze" << std::endl;
        std::cout << "8. Zapisz isteniejaca baze do pliku" << std::endl;
        std::cout << '\n';
        std::cout << "9. Utworz obiekt z danych z pliku 'Dane_dla_obiektu.txt'" << std::endl;
        std::cout << "10. Pokaz obiekt o podanym indeksie z bazy z pliku 'Dane_dla_obiektu.txt'" << std::endl;
        std::cout << '\n';
        std::cout << "11. Zarzadzaj fabrykami\n\n" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Wybiez opcje : ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            if (baza == nullptr) {
                baza = new Baza;
            }
            else {
                std::cout << "Baza juz istnije" << std::endl;
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if (baza != nullptr)
                std::cout << *baza;
            //baza->print();
            else
                std::cout << "Brak Bazy !" << std::endl;
            system("pause");
            system("cls");
            break;
        case 3:
            if (baza != nullptr) {
                baza->dodaj_gracza();
                std::cout << "Gracz zostal dodany !" << std::endl;
                std::ofstream file("Dane_baza.txt");
                file << *baza;
                file.close();
            }
            else
                std::cout << "Stworz Baze !" << std::endl;
            system("pause");
            system("cls");
            break;
        case 4:
            if (baza != nullptr) {
                baza->usun_gracza();
                std::cout << "Gracz zostal usuniety !" << std::endl;
                std::ofstream file("Dane_baza.txt");
                file << *baza;
                file.close();
            }
            else
                std::cout << "Stworz Baze !" << std::endl;
            system("pause");
            system("cls");
            break;
        case 5:
            if (baza != nullptr)
                baza->more_than();
            else
                std::cout << "Stworz Baze !" << std::endl;
            system("pause");
            system("cls");
            break;
        case 6:
            if (baza == nullptr)
                std::cout << "Najpierw stworz Baze!!!" << std::endl;
            else {
                baza2 = new Baza(*baza);
                std::cout << "Baza zostala pomyslnie skopiowana" << std::endl;
                //baza = new Baza;
            }
            system("pause");
            system("cls");
            break;
        case 7:
            if (baza2 != nullptr)
                std::cout << *baza2;
                //baza2->print();
                //std::cout << "Test bo operator jak cos";
            else
                std::cout << "Brak Bazy !" << std::endl;
            system("pause");
            system("cls");
            break;
        case 8:
            file << *baza;
            file.close();
            std::cout << "Zapisano do pliku pomyslnie!!" << std::endl; //plik nadpisuje sie po wyjsciu z programu ale trzba nadpisac w czasie dzialania np po dodaniu/usunieciu Gracza
            /*if (file.is_open()) {
                file << *baza;
                file.close();
            }
            else
                std::cout << "Nie mozna bylo utworzyc pliku" << std::endl;*/
            system("pause");
            system("cls");
            break;
        case 9:
            //std::ifstream plik("Dane_dla_obiektu.txt");
            size_t size;
            if (plik.is_open()) {
                plik >> size;
                baza3 = new Baza(size);
                //baza3->Produkcja_arr.clear();         
                plik >> *baza3;
                std::cout << *baza3;
                plik.close();
            }
            else
                std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
            system("pause");
            system("cls");
            break;
        case 10:
            std::cout << "Podaj indeks ktory chcesz konkretnie zobaczyc z bazy3: "; size_t x; std::cin >> x;
            std::cout << std::setw(20) << std::setfill('*') << '\n';
            std::cout << "ID Fabryki o indeksie " << x << ":" << (*baza3)[x]->Get_fab_id() << " " << "fundusz " << (*baza3)[x]->Get_fab_fundusz() << std::endl; std::cout << std::setw(20) << std::setfill('*') << '\n';
            system("pause");
            system("cls");
            break;
        case 11: {
            //baza4 = new Baza_Fabryk;
            bool wybor=false;
            short y, x, z; //indeks = "10" jako string bo kompilator wymaga roznych sygnatur argumentow poprzedni operator juz ma liczbe
            while (wybor == false) {
                std::cout << "Masz " << baza4->Get_Size() << " fabryk pod zarzadem wybierz indeks aby zobaczyc dzialania: " << std::endl;
                std::cin >> y;
                std::cout << "Wybrany obiekt to: " << (*baza4)[y]->get_nazwa() << '\n' << "Chcesz kontynuowac??" << '\n' << "1. TAK | 2. NIE" << std::endl; std::cin >> z;
                if (z != 1) continue;
                //std::cout << trzeba dodac zmienna ktora bedzie trzymac nazwe dla fabryki skroci to menu bo na razie jest zle/po staremu teraz dopiero po wylosowaniu wiadomo co jest co nie wczesniej
                std::cout << "\n\n" << std::setw(30) << std::setfill('-') << "\n\n";
                std::cout << "1. Pokaz zasoby Fabryki" << '\n' << "2. Uruchom Fabryke" << '\n' << "3. Ulepsz Fabryke" << '\n' << "4. Sprawdz ilosc w fabrykach materialow" << '\n' << "5. Wyswietl wszystkie fabryki" << '\n' << "6. Odwroc kolejnosc fabryk" << std::endl;
                std::cout << "\n\n" << std::setw(30) << std::setfill('-') << "\n\n";
                std::cin >> x;
                switch (x) {
                case 1:
                    std::cout << "Zasoby: \n\n";
                    (*baza4)[y]->pokaz_zasoby();
                    std::cout << std::endl;
                    break;
                case 2:
                    (*baza4)[y]->wydobywaj();
                    std::cout << "Wydobycie zakonczone pomyslnie!!!" << std::endl;
                    break;
                case 3:
                    (*baza4)[y]->ulepsz();
                    break;
                case 4:
                    baza4->naj_mat_mapa();
                    break;
                case 5:
                    baza4->show_all_Fab();
                    break;
                case 6:
                    baza4->reverse_Prod_arr();
                    break;
                }
                std::cout << "Kontyuuj 1/0 ??" << std::endl; std::cin >> wybor;
            }
            //wsk = &kopalnia;
            //wsk->wydobywaj();
            //wsk->pokaz_zasoby();
            system("pause");
            system("cls");
            break;
        }
        case 0:
            if (baza != nullptr) {
                delete baza;
                baza = nullptr;
            }
            if (baza == nullptr)
                std::cout << "Baza jest pusta !" << std::endl;
            break;
        default:
            std::cout << "Bledny wybor. Powtorz\n";
            system("pause");
            system("cls");
        }
    } while (choice != 0);
}