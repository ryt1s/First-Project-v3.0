#include "..\include\io.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

void generuotiFaila(const string& fname, int nStudentu, int nNd) {
    ofstream f(fname);
    if (!f) { cerr << "Nepavyko sukurti failo: " << fname << "\n"; return; }

    f << setw(20) << left << "Pavarde" << setw(20) << "Vardas";
    for (int i = 1; i <= nNd; ++i) f << setw(5) << ("ND" + to_string(i));
    f << setw(10) << "Egzaminas\n";

    mt19937 rng(static_cast<unsigned>(time(nullptr)));
    uniform_int_distribution<int> d(1, 10);

    for (int i = 1; i <= nStudentu; ++i) {
        f << setw(20) << left << ("Pavarde" + to_string(i))
          << setw(20) << ("Vardas" + to_string(i));
        for (int j = 0; j < nNd; ++j) f << setw(5) << d(rng);
        f << setw(10) << d(rng) << "\n";
    }
    cout << "Sugeneruotas failas: " << fname << " (" << nStudentu << " irasu)\n";
}

template<typename C> void nuskaitytiIsFailoTemplate(const string& fname, C& studentai) {
    ifstream f(fname);
    if (!f) { cerr << "Nepavyko atidaryti failo: " << fname << "\n"; return; }
    string header; getline(f, header);

    Student s;
    while (f >> s) studentai.push_back(move(s));
}

template<typename C> void issaugotiIFailaTemplate(const string& fname, const C& studs, int m) {
    ofstream f(fname, ios::out | ios::trunc);
    if (!f) return;

    f << left << setw(25) << "Pavarde" << setw(25) << "Vardas";
    if (m == 3) f << setw(15) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)";
    else f << setw(15) << "Galutinis";
    f << "\n";

    string buf; buf.reserve(1<<20);
    for (const auto& s : studs) {
        ostringstream line;
        line << setw(25) << s.pavarde() << setw(25) << s.vardas();
        if (m == 3)
            line << setw(15) << fixed << setprecision(2) << s.galVid()
                 << setw(15) << fixed << setprecision(2) << s.galMed();
        else
            line << setw(15) << fixed << setprecision(2) << (m==1 ? s.galVid() : s.galMed());
        line << "\n";

        buf.append(line.str());
        if (buf.size() > (1<<20)) { f.write(buf.data(), buf.size()); buf.clear(); }
    }
    if (!buf.empty()) f.write(buf.data(), buf.size());
}

void nuskaitytiIsFailo(const string& f, vector<Student>& s){ nuskaitytiIsFailoTemplate(f,s); }
void nuskaitytiIsFailo(const string& f, list<Student>& s){ nuskaitytiIsFailoTemplate(f,s); }
void issaugotiIFaila(const string& f, const vector<Student>& s,int m){ issaugotiIFailaTemplate(f,s,m); }
void issaugotiIFaila(const string& f, const list<Student>& s,int m){ issaugotiIFailaTemplate(f,s,m); }

int inputSkaicius(const string& msg, int min, int max) {
    int v;
    while (true) {
        cout << msg;
        if (!(cin >> v)) { cin.clear(); cin.ignore(1000,'\n'); cout << "Klaida! Iveskite sveika skaiciu.\n"; continue; }
        if (v < min || v > max) { cout << "Balas turi buti nuo " << min << " iki " << max << ". Bandykite dar karta.\n"; continue; }
        break;
    }
    return v;
}
