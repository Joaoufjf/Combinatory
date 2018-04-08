#include <iostream>

#include "KnapsackSolver.h"

#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
	ifstream arq(argv[1]);
    KnapsackSolver* ks = new KnapsackSolver();

    int type;
    string description, leave, s;
	bool on, off;
    int value;
    int target;
	int cumulated = 0;
	
	///read input values
	while(getline(arq, leave, ';')){
	    getline(arq, description, ';');
	    
	    getline(arq, leave, ';');
	    
        getline(arq, s, ';');
		s.erase(s.end() - 3); //.dd
        value = atoi(s.c_str());
        
        getline(arq, s, ';');
        on = atoi(s.c_str());
        
        getline(arq, s, ';');
        off = atoi(s.c_str());
        
        getline(arq, s, ';');
        type = atoi(s.c_str());
        
        ///flip the value if it is negative
        if(type == 2)
			value *= -1;
        ///both value and target are turn into integer values to avoid cumulative error on double
        getline(arq, s);
        s.erase(s.end() - 4); //.dd\n
        target = atoi(s.c_str());
                
		if(!off){
			if(on){
				///cumulates what is already on the knapsack
				cumulated += value;
			}
			else{
				///add an item that is a candidate to the full knapsack
				ks->AddItem(description, false, value);
			}
		}
    }
    
    ///manual input
	//while(cin >> leave >> description >> leave /*ignore*/){
        //cin >> s;
		//s.erase(s.end() - 3);
        //value = atoi(s.c_str());
        //cin >> on;
        //cin >> off;
        //cin >> type;
        
        //if(type == 2)
			//value *= -1;
        
        //cin >> s;
        //s.erase(s.end() - 3);
        //target = atoi(s.c_str());
        
		//if(!off){
			//if(on){
				//cumulated += value;
			//}
			//else{
				//ks->AddItem(description, false, value);
			//}
		//}
        //i++;
    //}
	
	///solves the knapsack
	ks->RecursiveKnapsack(target, cumulated);

    return 0;
}
