#include <string>
#include <map>
#include <iostream>
#include <cstdio>
#include <cassert>

#include "matrix.h"

typedef std::map<std::string, Matrix*> var_storage;

using std::size_t;
using std::cin;
using std::cout;

int main(int, char **) {
    std::string cmd, arg1, arg2;
    var_storage vars;

/*
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
*/

    while (cin)
    {
        cin >> cmd;
        if (cmd == "exit")
        {
            break;
        }
        else if (cmd == "init")
        {
            size_t rows, cols;
            cin >> arg1 >> rows >> cols;
            assert(!vars.count(arg1) && "Already created var");
            vars[arg1] = new Matrix(rows, cols);
        }
        else if (cmd == "#")
        {
            cin >> arg1;
            assert(vars.count(arg1) && "Unknows var");
            cout << vars[arg1]->get_rows() << " ";
            cout << vars[arg1]->get_cols() << std::endl;
        }
        else if (cmd == "get")
        {
            size_t i, j;
            cin >> arg1 >> i >> j;
            assert(vars.count(arg1) && "Unknows var");
            cout << vars[arg1]->get(i, j) << std::endl;
        }
        else if (cmd == "set")
        {
            size_t i, j;
            int v;
            cin >> arg1 >> i >> j >> v;
            assert(vars.count(arg1) && "Unknows var");
            vars[arg1]->set(i, j, v);
        }
        else if (cmd == "print")
        {
            cin >> arg1;
            assert(vars.count(arg1) && "Unknows var");
            vars[arg1]->print(stdout);
        } else if (cmd == "cp_init")
        {
            cin >> arg1 >> arg2;
            assert(!vars.count(arg1) && "Already created var");
            assert(vars.count(arg2) && "Unknows var");
            vars[arg1] = new Matrix(*vars[arg2]);
        } else if (cmd == "=")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg2) && "Unknows var");
            if (vars.count(arg1) == 0) {
                vars[arg1] = new Matrix(0, 0);
            }
            *vars[arg1] = *vars[arg2];
        }
        else if (cmd == "==")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg1) && "Unknows var");
            assert(vars.count(arg2) && "Unknows var");
            cout << (*vars[arg1] == *vars[arg2]) << std::endl;
        }
        else if (cmd == "!=")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg1) && "Unknows var");
            assert(vars.count(arg2) && "Unknows var");
            cout << (*vars[arg1] != *vars[arg2]) << std::endl;
        }
        else if (cmd == "+=")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg1) && "Unknows var");
            assert(vars.count(arg2) && "Unknows var");
            *vars[arg1] += *vars[arg2];
        }
        else if (cmd == "-=")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg1) && "Unknows var");
            assert(vars.count(arg2) && "Unknows var");
            *vars[arg1] -= *vars[arg2];
        }
        else if (cmd == "*=")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg1) && "Unknows var");
            assert(vars.count(arg2) && "Unknows var");
            *vars[arg1] *= *vars[arg2];
        }
        else if (cmd == "+")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg1) && "Unknows var");
            assert(vars.count(arg2) && "Unknows var");
            (*vars[arg1] + *vars[arg2]).print(stdout);
        }
        else if (cmd == "-")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg1) && "Unknows var");
            assert(vars.count(arg2) && "Unknows var");
            (*vars[arg1] - *vars[arg2]).print(stdout);
        }
        else if (cmd == "*")
        {
            cin >> arg1 >> arg2;
            assert(vars.count(arg1) && "Unknows var");
            assert(vars.count(arg2) && "Unknows var");
            (*vars[arg1] * *vars[arg2]).print(stdout);
        }

    }

    for (var_storage::iterator it = vars.begin(); it != vars.end(); ++it)
    {
        delete it->second;
    }
}