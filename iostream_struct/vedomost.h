#ifndef VEDOMOST_H
#define VEDOMOST_H

#include <iostream>
#include <string>

using namespace std;

struct vedomost
{
    uint NomerStudBileta = 0;
    string FIO ;

    float ball = 0;

    friend ostream& operator<<( ostream &os, const vedomost &ved)   {
        os << ved.NomerStudBileta << " " << ved.FIO << " " << ved.ball <<  endl;
        return os;
    }

    friend istream& operator>>( istream &is, vedomost &ved) {
        string F,I,O;

        is >> ved.NomerStudBileta >> F >> I >> O >> ved.ball;
        ved.FIO = F+" "+I+" "+O;

        F.clear();
        I.clear();
        O.clear();

        return is;
    }
};


#endif // VEDOMOST_H
