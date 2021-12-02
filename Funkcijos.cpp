#include "biblioteka.h"


void Studentas::setStudentas(std::string vardas_, std::string pavarde_, std::string Egzaminas)
{
    Vardas_ = vardas_;
    Pavarde_ = pavarde_;
    Egzaminas_ = std::stoi(Egzaminas);
}

void Studentas::SetND(int Score)
{
    ND_.push_back(Score);
}


void Studentas::EmptyND()
{
    ND_.clear();
}

double Studentas::GP(int Exam, double HomeworkScore)
{
    return 0.4 * HomeworkScore + 0.6 * Exam;
}

double Studentas::GP(int Exam, const std::vector<int> Homework)
{
    if (ND_.size() == 0)
        throw std::domain_error("Studentas neatliko nei vieno namu darbo.");
    return GP(Egzaminas_, Vidurkis(ND_));
}

double Studentas::GP(double (*Criteria)(std::vector<int>))
{
    return GP(Egzaminas_, Criteria(ND_));
}


double Vidurkis(std::vector<int> HomeworkScore)
{
    if (HomeworkScore.size() == 0)
        throw std::domain_error("Skaiciavimo atlikti negalima. Iveskite duomenis.");

    return std::accumulate(HomeworkScore.begin(), HomeworkScore.end(), 0.0) / HomeworkScore.size();
}


double Mediana(std::vector<int> HomeworkScore)
{
    typedef std::vector <int>::size_type VecSize;
    VecSize size = HomeworkScore.size();

    if (size == 0)
        throw std::domain_error("Skaiciavimo atlikti negalima. Iveskite duomenis.");

    sort(HomeworkScore.begin(), HomeworkScore.end());

    VecSize Middle = size / 2;

    if (size % 2 == 0)
        return (HomeworkScore[Middle - 1] + HomeworkScore[Middle]) / 2;
    else
        return HomeworkScore[Middle];
}


bool Lyginimas(const Studentas& x, const Studentas& y)
{
    return x.getSurname() < y.getSurname();
}

bool Raides(std::string Input)
{
    for (int i = 0; i < Input.length(); i++)
    {
        if (isalpha(Input[i]) == false)
            return false;
    }
    return true;
}


bool Skaiciai(const std::string& str)
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

void DidRaid(std::string& Text)
{
    if (islower(Text.at(0)))
        Text.at(0) = toupper(Text.at(0));

    for (int i = 1; i < Text.length(); i++)
        if (isupper(Text.at(i)))
            Text.at(i) = tolower(Text.at(i));
}


void SpausdintiLentele(std::ostream& out, std::string::size_type x, std::string::size_type y)
{
    out << "Vardas" << std::string(x - 5, ' ')
        << "Pavarde" << std::string(y - 6, ' ') << "Galutinis pazymys" << std::endl;

    auto Spaces = x + y + 18;
    for (auto i = 0; i <= Spaces; i++)
        out << "-";
    out << std::endl;
}


void SpausdintiVidurki(std::string::size_type x, std::string::size_type y)
{
    std::cout << "Vardas" << std::string(x - 5, ' ')
        << "Pavarde" << std::string(y - 6, ' ') << "Galutinis pazymys (vid.)" << std::endl;

    auto Spaces = x + y + 24;
    for (auto i = 0; i <= Spaces; i++)
        std::cout << "-";
    std::cout << std::endl;
}


void SpausdintiMediana(std::string::size_type x, std::string::size_type y)
{
    std::cout << "Vardas" << std::string(x - 5, ' ')
        << "Pavarde" << std::string(y - 6, ' ') << "Galutinis pazymys (med.)" << std::endl;

    auto Spaces = x + y + 24;
    for (auto i = 0; i <= Spaces; i++)
        std::cout << "-";
    std::cout << std::endl;
}


void Spausdinti(std::ostream& out, std::vector<Studentas> Main, std::string::size_type x, std::string::size_type y)
{
    for (std::vector<Studentas>::iterator IT = Main.begin(); IT != Main.end(); IT++)
    {
        out << (*IT).getName() << std::string(x + 1 - (*IT).getName().size(), ' ');
        out << (*IT).getSurname() << std::string(y + 1 - (*IT).getSurname().size(), ' ');
        std::streamsize prec = std::cout.precision();
        out << std::fixed << std::setprecision(2) << (*IT).GP(Vidurkis) << " "
            << (*IT).GP(Mediana) << std::setprecision(prec) << std::endl;
    }
    for (auto i = 0; i != x + y + 10; i++)
        out << "-";
    out << std::endl;
}

void Generavimas(std::size_t i)
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution <int> Interval(1, 10), Amount(10, 20);

    int NumberOfStudents = i,
        AmountOfResults = Amount(eng);

    std::ofstream Write;
    Write.open("Studentai_" + std::to_string(i) + ".txt");

    for (size_t j = 1; j <= NumberOfStudents; j++)
    {
        Write << "Vardas" + std::to_string(j) << " Pavarde" + std::to_string(j) << " " << Interval(eng);

        std::vector <int> Results;
        std::vector <int>::iterator IT;

        for (size_t k = 0; k < AmountOfResults; k++)
            Results.push_back(Interval(eng));

        for (IT = Results.begin(); IT < Results.end(); IT++)
            Write << " " << *IT;

        Write << std::endl;
    }
    Write.close();
}
int Pasirinkimas()
{
    std::string Entry;
    int EntryChoice;
    std::cout << "Kaip norite gauti stendentu duomenis?\n Spauskite:"
        "\n1. jeigu norite duomenis nuskaityti is failo 'kursiokai.txt',"
        "\n2. jeigu norite duomenis ivesti pats/pati"
        "\n3. jeigu norite nuskaityti duomenis is sugeneruotu failu" << std::endl;

    while (std::cin >> Entry)
    {
        if (Entry == "1")
        {
            EntryChoice = 1;
            break;
        }
        else if (Entry == "2")
        {
            EntryChoice = 2;
            break;
        }
        else if (Entry == "3")
        {
            EntryChoice = 3;
            break;
        }
        else
            std::cout << Error << std::endl;
    }std::cin.ignore();
    return EntryChoice;
}