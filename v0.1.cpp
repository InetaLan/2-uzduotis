// v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::left;
using std::setw;
using std::istream;

struct studentas {
    string vardas, pavarde;
    float  nd[10]{};
    //Tarkime, kad namų darbų daugiausiai gali būti 10 - 
    // todėl renkamės statinį masyvą ir nurodome masyvo dydį [10]
    float egz;
    float galutinis;
};

void pildymas(studentas& kint); // Funkcijos prototipas, kuris turi būti aprašytas pries funkciją main.
void print(studentas& kin);


int main()
{
    studentas studentai[30];
    int studsk;
    cout << "Keliu studentu duomenis ivesite? "; cin >> studsk;
   
    for (int i = 0; i < studsk; i++)
        pildymas(studentai[i]);

    cout
        << "\n"
        << left << setw(15) << "Vardas"
        << left << setw(20) << "Pavarde"
        << left << setw(25) << "Egzamino ivertinimas"
        << left << setw(20) << "Galutinis balas"
        << endl
        << string(15 + 20 + 2*20, '-') << "\n";

    for (int i = 0; i < studsk; i++)
        print(studentai[i]);

}

//Funkcijos kūnas;
void pildymas(studentas& kint) {

    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    
    int n; //Namų darbų skaičius
    float sum = 0, vid = 0; //Sum-> namų darbų suma, vid-> namų darbų vidurkis;

    cout << "Kiek ivesite namu darbu? (1-10) ";
    while(!(cin>> n) || n <1 || n>10)
    {
        cout << "Ivesta negalima reiksme - patikslinkite." << endl;
        cout << "Kiek ivesite namu darbu?" << endl;
        cin.clear();
        cin.ignore();
    }

    cout << "Iveskite pazymius: " << endl;
    for (int i = 0; i < n; i++) {
        
        while (!(cin >> kint.nd[i]) || kint.nd[i] < 1 || kint.nd[i] > 10)
        {
            cout << "Ivesta negalima reiksme - patikslinkite." << endl;
            cout << "Iveskite pazymius: " << endl;
            cin.clear();
            cin.ignore();
        }
        
        sum += kint.nd[i];
    };
    
    vid = sum / n;

    cout << "Iveskite egzamino pazymi: "; 
    while (!(cin >> kint.egz) || kint.egz < 1 || kint.egz>10)
    {
        cout << "Ivesta negalima reiksme - patikslinkite." << endl;
        cout << "Iveskite egzamino pazymi: ";
        cin.clear();
        cin.ignore();
    }

    kint.galutinis = 0.4 * vid + 0.6 * kint.egz;
}

void print(studentas& kin) {
    cout
        << left        << setw(15)        << kin.vardas
        << left        << setw(20)        << kin.pavarde
        << left        << setw(25)        << kin.egz
        << left        << setw(20)        << std::setprecision(3) << kin.galutinis
        << endl;
}



float mediana(vector<float> vec) {
    typedef vector<float>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("Negalima skaiciuoti medianos tusciam vektoriui");
    sort(vec.begin(), vec.end());
    vecSize vid = size / 2;
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid];


}
