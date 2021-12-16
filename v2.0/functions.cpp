#ifndef functions_h
#define functions_h
#include "functions.h"
using namespace std;

double vidurkis(vector<int> nd)
{
    /** vidurkio skaiciavimo funkcija
     *
     * Priima sveika skaiciu vektoriu
     *
     * Grazina double tipo vidurki
     *
     */

    int suma = 0;
    for (int i : nd)
    {
        suma += i;
    }
    return suma / nd.size();
}



list<studentas> generavimas(int kiek, list<StudentasClass>& studentaiClass)
{

    /** Duomenu generavimo funkcija
     *
     * Priima kieki kaip sveika skaiciu ir list tipo sarasa su reiksmem studentaiClass, kuri galima redaguoti
     *
     * Grazina list sarasa studentas tipo reiksmiu
     */

    list<studentas> studentai;
    for (int i = 0; i < kiek; i++)
    {
        studentas temp;
        string vardas = "Vardas" + to_string(i + 1);
        string pavarde = "Pavarde" + to_string(i + 1);
        int egz = egz = rand() % 10 + 1;
        int ND1 = rand() % 10 + 1;
        int ND2 = rand() % 10 + 1;
        int ND3 = rand() % 10 + 1;
        int ND4 = rand() % 10 + 1;
        int ND5 = rand() % 10 + 1;
        vector<int> nd;
        nd.push_back(ND1);
        nd.push_back(ND2);
        nd.push_back(ND3);
        nd.push_back(ND4);
        nd.push_back(ND5);

        temp.vardas = vardas;
        temp.pavarde = pavarde;
        temp.nd = nd;
        temp.egz = egz;
        temp.rezultatas = 0.4 * vidurkis(nd) + 0.6 * temp.egz;
        studentai.push_back(temp);

        StudentasClass studClass(vardas, pavarde, nd, egz);
        studentaiClass.push_back(studClass);
    }
    return studentai;
}

void dalijimas_struct(list<studentas> studentai)
{
    /** Dalija studentas tipo reiksmiu sarasa i nuskriaustus ir protingus ir istiria laika
     *
     *  Priima sarasa studentai, kur reiksmes studentas tipo
     *
     *  Nieko negrazina
     *
     */

    auto start_time = std::chrono::high_resolution_clock::now();
    int dydis = studentai.size();
    vector<studentas> nuskriausti;
    vector<studentas> protingi;
    for (studentas stud : studentai)
    {
        if (stud.rezultatas < 5)
        {
            nuskriausti.push_back(stud);
        }
        else
        {
            protingi.push_back(stud);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << dydis << " STRUCT dalijimas: " << time / std::chrono::milliseconds(1) / 1000.0 << " sec" << endl;
}

void dalijimas_class(list<StudentasClass> studentai)
{
    /** Dalija StudentasClass tipo reiksmiu sarasa i nuskriaustus ir protingus ir istiria laikas
    *
    *  Priima sarasa studentai, kur reiksmes StudentasClass tipo
    *
    *  Nieko negrazina
    *
    */
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<StudentasClass> nuskriausti;
    vector<StudentasClass> protingi;
    for (StudentasClass stud : studentai)
    {
        if (stud.getRezultatas() < 5)
        {
            nuskriausti.push_back(stud);
        }
        else
        {
            protingi.push_back(stud);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << dydis << " CLASS dalijimas: " << time / std::chrono::milliseconds(1) / 1000.0 << " sec" << endl;
}

void testuoti(int kiek)
{
    /** Apjungia duomenu generavima ir laiko tyrimus i viena funkcija
     *
     * Priima sveika skaiciu kiek, kuris parodo su kiek studentu bus tiriamas laikas
     * Negrazina nieko
     *
     */

    list<studentas> studentai;
    list<StudentasClass> studentaiClass;
    studentai = generavimas(kiek, studentaiClass);
    dalijimas_struct(studentai);
    dalijimas_class(studentaiClass);
    cout << endl;
}
#endif