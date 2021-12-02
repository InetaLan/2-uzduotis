#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>

const std::string Error = "Duomenys neatitinka reikalavimu. Bandukite dar karta.";

class Studentas
{
private:
    std::string Vardas_;
    std::string Pavarde_;
    std::vector<int> ND_;
    int Egzaminas_;
public:
    Studentas() : ND_(0) { };
    void setStudentas(std::string, std::string, std::string);
    void SetND(int);
    void EmptyND();
    std::string getName() const { return Vardas_; }
    std::string getSurname() const { return Pavarde_; }
    int GautiEgzamina() const { return Egzaminas_; }
    int GautiDydi() const { return ND_.size(); }
    double GP(int, double);
    double GP(int, const std::vector<int>);
    double GP(double (*) (std::vector<int>));
};

double Vidurkis(std::vector<int>);
double Mediana(std::vector<int>);
bool Lyginimas(const Studentas&, const Studentas&);
bool Raides(std::string);
bool Skaiciai(const std::string&);
void DidRaid(std::string&);
void SpausdintiLentele(std::ostream&, std::string::size_type, std::string::size_type);
void SpausdintiVidurki(std::string::size_type, std::string::size_type);
void SpausdintiMediana(std::string::size_type, std::string::size_type);
void Spausdinti(std::ostream&, std::vector<Studentas>, std::string::size_type, std::string::size_type);
void Generavimas(std::size_t);
int Pasirinkimas();
#endif