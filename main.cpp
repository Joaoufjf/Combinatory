#include <iostream>

#include "KnapsackSolver.h"

#include <sstream>

using namespace std;

int main(){


    cout << "Hello world!" << endl;
    //cout << fixed;
    KnapsackSolver* ks = new KnapsackSolver();

    int i = 1;
    int type;
    string description, leave, s;
	bool on, off;
    int value;
    int target;
	int cumulated = 0;

    
	while(cin >> leave >> description >> leave /*ignore*/){
        cin >> s;
		s.erase(s.end() - 3);
        value = atoi(s.c_str());
        cin >> on;
        cin >> off;
        cin >> type;
        
        if(type == 2)
			value *= -1;
        
        cin >> s;
        s.erase(s.end() - 3);
        target = atoi(s.c_str());
        //cout << description << " ";
        //cout << value << " ";
        //cout << on << " ";
        //cout << off << " ";
        //cout << type << " ";
        //cout << value << endl;
		if(!off){
			if(on){
				cout << "Sol + " << description << endl;
				cumulated += value;
			}
			else{
				ks->AddItem(description, false, value);
			}
		}
        i++;
    }

	ks->RecursiveKnapsack(target, cumulated);

    return 0;
}
