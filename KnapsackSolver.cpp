#include "KnapsackSolver.h"

KnapsackSolver::KnapsackSolver(){
    lowest = numeric_limits<int>::infinity();
    sum = 0;
}

KnapsackSolver::~KnapsackSolver(){
	
}

///insert a candidate
void KnapsackSolver::AddItem(string name, bool status, int value){
    if(value < lowest)
        lowest = value;
    knapsack.push_back(make_tuple(name, status, value));
}

///print the knapsack
void KnapsackSolver::Print(bool all){
	int sum = 0;
    cout << "[";
    for(auto t : knapsack){
        if(all){
            cout << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")\n ";
        }
        else{
            if(get<1>(t))
                cout << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")\n ";
        }
        if(get<1>(t))
			sum += get<2>(t);
    }
    cout << "] = " << sum << " & " << target - cumulated << endl;
}

bool KnapsackSolver::IncreasingSortItems(tuple<string, bool, int> a, tuple<string, bool, int> b){
    return get<2>(a) < get<2>(b);
}

bool KnapsackSolver::DecreasingSortItems(tuple<string, bool, int> a, tuple<string, bool, int> b){
    return get<2>(a) > get<2>(b);
}

/***
	start the recursive search
	the sorting bring the property of consecutiveness
	therefore, when an item is added is possible to determine if
	the insertion of the next item keep the knapsack feasible
***/
void KnapsackSolver::RecursiveKnapsack(int target, int cumulated){
    this->target = target;
    this->cumulated = cumulated;
    
    sort(knapsack.begin(), knapsack.end(), IncreasingSortItems);
	
	//Print(true);
	
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
 * total: stands for the amount on the current knapsack
 * target: stands for the ideal knapsack
 * lastAdd: stands fot the last inserted value on the knapsack
***/
void KnapsackSolver::SmartRecursiveKnapsack(int total, int lastAdd){
    if(total > target)
        return;
    else{
		if(total == target){
			cout << "Solution" << endl;
			Print(0);
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

/*** NOTES
 * The best way to solve the problem is
 * * Metaheuristic = not sure if is possible to acquire all solutions
 * * Dynamic = The space complexity makes it unfeasible, for now
 ***/
