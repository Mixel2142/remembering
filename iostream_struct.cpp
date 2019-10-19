/*
Разработать структуру(аналог экзаменационной ведомости)
*/
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct vedomost
{
    uint NomerStudBileta = 0;
    string FIO ;
    float ball = 0;

    friend std::ostream& operator<<(std::ostream &os, const vedomost &ved);
    friend std::istream& operator>>(std::istream &is, vedomost &ved);
};

std::ostream& operator<<(std::ostream &os, const vedomost &ved){
    os << ved.NomerStudBileta << " " << ved.FIO << " " << ved.ball << endl;
    return os;
}

std::istream& operator>>(std::istream &is, vedomost &ved){
    string F,I,O;

    is >> ved.NomerStudBileta >> F >> I >> O >> ved.ball;
    ved.FIO = F+" "+I+" "+O;

    F.clear();
    I.clear();
    O.clear();

    return is;
}

vector<vedomost> vedomosti;

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

void addNewStudent()    {
    vedomosti.push_back(getVedomost());
    system("clear");
}

void showAllStudent()    {

    system("clear");
    cout << "\n\t Список всех студентов: \n";

    for (auto& it : vedomosti) {
        cout << "\tНомер: " << it.NomerStudBileta << "\t ФИО: " << it.FIO << "\t Баллл: " << it.ball << "\n";
    }

    system("pause");
}

void changeStudent()    {

    uint NomerStudBileta;

    cout << "введите номер билета для удаления:\n";
    cin >> NomerStudBileta;

    for (uint i = 0; i < vedomosti.size(); ++i) {

        if(vedomosti.at(i).NomerStudBileta == NomerStudBileta)  {
            vedomosti.at(i) = getVedomost();
        }
    }

}

void saveData()    {
    fstream outFile("students.data", std::ios::out | std::ios::binary);
    copy(vedomosti.begin(),vedomosti.end(),ostream_iterator<vedomost>(outFile));
    outFile.close();
}

void loadData()    {
    fstream inFile("students.data", std::ios::in | std::ios::binary);
    copy(istream_iterator<vedomost>(inFile),istream_iterator<vedomost>(),back_inserter(vedomosti));
    inFile.close();
}

void deleteStudent()    {

    uint NomerStudBileta;

    cout << "введите номер билета для удаления:\n";
    cin >> NomerStudBileta;

    for (uint i = 0; i < vedomosti.size(); ++i) {

        if(vedomosti.at(i).NomerStudBileta == NomerStudBileta)  {
            vedomosti.erase(vedomosti.begin()+i);
        }
    }

}

void deleteAllStudents()    {
    vedomosti.clear();
}

float calculateAverage()  {
    float average = 0;
    for (auto& it : vedomosti) {
        average += it.ball;
    }
    average /= vedomosti.size();

    system("clear");
    cout << "\n\t Средний балл: " << average << "\n";
}

int main()
{
    loadData();
    int action = -1;
    while(1)    {
        cout << "Пожалуйста, введите номер действия:\n" <<
                "(0): добавить нового студента\n" <<
                "(1): показать всех студентов\n" <<
                "(2): изменить запись по номеру студ.\n" <<
                "(3): удалить запись по номеру студ.\n" <<
                "(4): удалить все записи\n" <<
                "(5): посчитать средний балл\n" << // посчитать средний балл
                "(6): выйти\n" << // посчитать средний балл
                endl;

        cin >> action;

        switch(action)   {
        case 0:
            addNewStudent();
            break;

        case 1:
            showAllStudent();
            break;

        case 2:
            changeStudent();
            break;

        case 3:
            deleteStudent();
            break;

        case 4:
            deleteAllStudents();
            break;

        case 5:
            calculateAverage();
            break;

        default:
            goto end;

        }   //switch

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//пропускает во входном потоке всё до следующего \n
    }// while

end:
    saveData();
    return 0;
}
