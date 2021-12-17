#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <iterator>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::setprecision;
using std::setw;
using std::left;

class Person
{

protected:
    string Vardas_;
    string Pavarde_;

public:
    Person(string, string);
    Person();
    ~Person();
    virtual void setVardas(string) = 0;
    virtual void setPavarde(string) = 0;
    string getVardas() const;
    string getPavarde() const;
};

class Studentas : public Person
{

public:
    Studentas();
    ~Studentas();
    void setVardas(string);
    void setPavarde(string);
    void setND(vector <double>);
    void setEgzaminas(int);
    string getVardas() const;
    string getPavarde() const;
    int getEgzaminas() const;
    double getFinalMediana() const;
    double getFinalVidurkis() const;
    Studentas& operator=(const Studentas& stud);
    bool operator<(const Studentas& s2);
    bool operator>(const Studentas& s2);
    bool operator!=(const Studentas& s2);
    bool operator==(const Studentas& s2);
    void skaiciavimas();
    Studentas(const Studentas&);
private:
    vector<double> ND;
    int Egzaminas;
    double Vidurkis;
    double Mediana;
    double FinalMediana;
    double FinalVidurkis;
};
void Generavimas(std::size_t i);
void Nuskaitymas(vector<Studentas>& Stud, string filename);
void Ivedimas(vector <Studentas>& Stud);
void Skaiciavimai(vector <Studentas>& Stud);
bool Kvaili1(Studentas& Stud);
bool Kvaili2(Studentas& Stud);
void GeneravimasOutputFiles(vector <Studentas>& Stud, vector <Studentas>& Kvaili, vector <Studentas>& Protingi, int t);
void Spausdinimas(vector <Studentas>& Stud, int t, string text);
bool Skaiciai(const std::string& str);
int Pasirinkimas();