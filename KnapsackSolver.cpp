#include "KnapsackSolver.h"

KnapsackSolver::KnapsackSolver(){
    //ctor
    lowest = numeric_limits<int>::infinity();
    sum = 0;
}

void KnapsackSolver::AddItem(string name, bool status, int value){
    if(value < lowest)
        lowest = value;
    knapsack.push_back(make_tuple(name, status, value));
}

void KnapsackSolver::Print(bool all){
    cout << "[";
    for(auto t : knapsack){
        if(all){
            cout << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")\n ";
        }
        else{
            if(get<1>(t))
                cout << get<0>(t) << " + ";
        }
    }
    cout << "]" << endl;
}

bool KnapsackSolver::IncreasingSortItems(tuple<string, bool, int> a, tuple<string, bool, int> b){
    return get<2>(a) < get<2>(b);
}

bool KnapsackSolver::DecreasingSortItems(tuple<string, bool, int> a, tuple<string, bool, int> b){
    return get<2>(a) > get<2>(b);
}

void KnapsackSolver::RecursiveKnapsack(int target, int cumulated){
    this->target = target;
    this->cumulated = cumulated;
    
    sort(knapsack.begin(), knapsack.end(), DecreasingSortItems);
	
	Print(true);
	
    time_t s;
    ofstream arq;
    streambuf *coutbuf;

    ///Smart
    arq.open("SmartKnapsack.txt");
    coutbuf = std::cout.rdbuf();
//    cout.rdbuf(arq.rdbuf());

    s = time(NULL);
    SmartRecursiveKnapsack(cumulated, -1);
    cout << time(NULL) - s << endl;

    arq.close();
    cout.rdbuf(coutbuf);
}
/***
    total: stands for the amount on the current knapsack
    target: stands for the ideal knapsack
    lastAdd: stands fot the last inserted value on the knapsack
***/
void KnapsackSolver::NormalRecursiveKnapsack(int value, int lastAdd){
	//for(int i = 0; i < lastAdd + 1; i++) cout << " ";
	//cout << "Atual " << target - value << endl;
	//for(auto item : knapsack)
		//cout << get<1>(item) << " ";
	//cout << endl;
	//usleep(200000);
    if(target - value == 0){
		cout << "Solução = " << endl;
        Print(true);
    }
    for(int i = 0; i < knapsack.size(); i++){
        if(!get<1>(knapsack.at(i))){
            get<1>(knapsack.at(i)) = true;
            NormalRecursiveKnapsack(value + get<2>(knapsack.at(i)), i);
            get<1>(knapsack.at(i)) = false;
        }
    }
}

void KnapsackSolver::SmartRecursiveKnapsack(int total, int lastAdd){
    if(total > target)
        return;
    else{
		if(total == target){
			//int sum = 0;
			//for(auto item : knapsack)
			//    if(get<1>(item))
			//        sum += get<2>(item);
			Print(1);
			//cout << "Sum = " << sum << endl;
			return;
		}
        for(int i = lastAdd + 1; i < knapsack.size(); i++){
            if(!get<1>(knapsack.at(i))){
                get<1>(knapsack.at(i)) = 1;
                SmartRecursiveKnapsack(total + get<2>(knapsack.at(i)), i);
                get<1>(knapsack.at(i)) = 0;
            }
        }
    }
}

void KnapsackSolver::AlternativeSmartRecursiveKnapsack(int value, int lastAdd){
    if(value == target){
        int sumi = 0;
        for(auto item : knapsack)
            if(get<1>(item))
                sumi += get<2>(item);
        Print();
        cout << "Sum = " << sumi << endl;
        return;
    }
    else if(value > target)
        return;
    else{
        for(int i = lastAdd + 1; i < knapsack.size(); i++){
            if(!get<1>(knapsack.at(i))){
                get<1>(knapsack.at(i)) = 1;
         	sum += get<2>(knapsack.at(i));
         	NormalRecursiveKnapsack(value + get<2>(knapsack.at(i)), i);
	    	sum -= get<2>(knapsack.at(i));
                get<1>(knapsack.at(i)) = 0;
            }
        }
    }
}

KnapsackSolver::~KnapsackSolver(){
    //dtor
}
