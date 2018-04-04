#include <iostream>

#include "KnapsackSolver.h"

#include <sstream>

using namespace std;

int main(){


    cout << "Hello world!" << endl;
    cout << fixed;
    KnapsackSolver* ks = new KnapsackSolver();

    int i = 1;
    int type;
    float value;
    float target;

    cin >> target;

    ///#pragma omp parallel for  ----usar -fopenmp
    while(cin >> type){
        cin >> value;
        cout << type << " " << value << endl;
        stringstream str;
        str << i;
        ks->AddItem(str.str(), false, type == 1 ? value : (value * -1.0));
        i++;
    }

//    ks->Print(true);
    cout << target << endl;
    ks->RecursiveKnapsack(target);
//    ks->Print();


    return 0;
}
