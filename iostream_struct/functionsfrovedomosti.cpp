#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <algorithm>
#include <iterator>

#include "vedomost.h"

using namespace std;

int countWords(string FIO)
{
    return count(FIO.begin(), FIO.end(),' ') + 1;
}


vedomost getVedomost()  {
    vedomost ved;

    cout << "введите номер билета :\n";
    cin >> ved.NomerStudBileta;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//пропускает во входном потоке всё до следующего \n

    while(countWords(ved.FIO) != 3)   {// Вводить ФИО пока правильно не введут
        cout << "введите ФИО :\n";
        getline(cin,ved.FIO);
        cin.clear();
    }

    cout << "введите балл :\n";
    cin>> ved.ball;
    cin.clear();

    return ved;
}

void addNewStudent(vector<vedomost> &vedomosti)    {
    vedomosti.push_back(getVedomost());
    system("clear");
}

void showAllStudent(vector<vedomost> &vedomosti)    {

    system("clear");
    cout << "\n\t Список всех студентов: \n";

    for (auto& it : vedomosti) {
        cout << "\tНомер: " << it.NomerStudBileta << "\t ФИО: " << it.FIO << "\t Баллл: " << it.ball << "\n";
    }

    system("pause");
}

void changeStudent(vector<vedomost> &vedomosti)    {

    uint NomerStudBileta;

    cout << "введите номер билета для удаления:\n";
    cin >> NomerStudBileta;

    for (uint i = 0; i < vedomosti.size(); ++i) {

        if(vedomosti.at(i).NomerStudBileta == NomerStudBileta)  {
            vedomosti.at(i) = getVedomost();
        }
    }

}

void saveData(vector<vedomost> &vedomosti)    {
    fstream outFile("students.data",  ios::out |  ios::binary);
    copy(vedomosti.begin(),vedomosti.end(),ostream_iterator<vedomost>(outFile));
    outFile.close();
}

void loadData(vector<vedomost> &vedomosti)    {
    fstream inFile("students.data",  ios::in |  ios::binary);
    copy(istream_iterator<vedomost>(inFile),istream_iterator<vedomost>(),back_inserter(vedomosti));
    inFile.close();
}

void deleteStudent(vector<vedomost> &vedomosti)    {

    uint NomerStudBileta;

    cout << "введите номер билета для удаления:\n";
    cin >> NomerStudBileta;

    for (uint i = 0; i < vedomosti.size(); ++i) {

        if(vedomosti.at(i).NomerStudBileta == NomerStudBileta)  {
            vedomosti.erase(vedomosti.begin()+i);
        }
    }

}

void deleteAllStudents(vector<vedomost> &vedomosti)    {
    vedomosti.clear();
}

void calculateAverage(vector<vedomost> &vedomosti)  {
    float average = 0;
    for (auto& it : vedomosti) {
        average += it.ball;
    }
    average /= vedomosti.size();

    system("clear");
    cout << "\n\t Средний балл: " << average << "\n";
}
