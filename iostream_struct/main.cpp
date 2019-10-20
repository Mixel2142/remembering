/*
Разработать структуру(аналог экзаменационной ведомости)
*/
#include <iostream>
#include "vedomost.h"
#include "functionsfrovedomosti.cpp"

using namespace std;

int main()
{
    vector<vedomost> vedomosti;

    loadData(vedomosti);
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
            addNewStudent(vedomosti);
            break;

        case 1:
            showAllStudent(vedomosti);
            break;

        case 2:
            changeStudent(vedomosti);
            break;

        case 3:
            deleteStudent(vedomosti);
            break;

        case 4:
            deleteAllStudents(vedomosti);
            break;

        case 5:
            calculateAverage(vedomosti);
            break;

        default:
            goto end;

        }   //switch

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//пропускает во входном потоке всё до следующего \n
    }// while

end:
    saveData(vedomosti);
    return 0;
}
