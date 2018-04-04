#include "KnapsackSolver.h"

KnapsackSolver::KnapsackSolver(){
    //ctor
    lowest = INFINITY;
}

void KnapsackSolver::AddItem(string name, bool status, float value){
    if(value < lowest)
        lowest = value;
    knapsack.push_back(make_tuple(name, status, value));
}

void KnapsackSolver::Print(bool all){
    cout << "[";
    for(auto t : knapsack){
        if(all){
            cout << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << "), ";
        }
        else{
            if(get<1>(t))
                cout << get<2>(t) << " + ";
        }
    }
    cout << "]" << endl;
}

bool KnapsackSolver::IncreasingSortItems(tuple<string, bool, float> a, tuple<string, bool, float> b){
    return get<2>(a) < get<2>(b);
}

bool KnapsackSolver::DecreasingSortItems(tuple<string, bool, float> a, tuple<string, bool, float> b){
    return get<2>(a) > get<2>(b);
}

void KnapsackSolver::RecursiveKnapsack(float target){
    cout << "Target = " << target << endl;
    sort(knapsack.begin(), knapsack.end(), IncreasingSortItems);
    time_t s;
    ofstream arq;
    streambuf *coutbuf;

//    /// Normal
//    arq.open("NormalKnapsack.txt");
//    coutbuf = std::cout.rdbuf();
////    cout.rdbuf(arq.rdbuf());
//
//    s = time(NULL);
//    NormalRecursiveKnapsack(0, target, -1);
//    cout << time(NULL) - s << endl;
//
//    arq.close();
//    cout.rdbuf(coutbuf);

    ///Smart
    arq.open("SmartKnapsack.txt");
    coutbuf = std::cout.rdbuf();
//    cout.rdbuf(arq.rdbuf());

    s = time(NULL);
    SmartRecursiveKnapsack(0, target, -1);
    cout << time(NULL) - s << endl;

    arq.close();
    cout.rdbuf(coutbuf);

//    ///AlternativeSmart
//    arq.open("SmartKnapsack.txt");
//    coutbuf = std::cout.rdbuf();
////    cout.rdbuf(arq.rdbuf());
//
//    s = time(NULL);
//
//    for(auto item : knapsack)
//        get<2>(item) += lowest;
//
//    AlternativeSmartRecursiveKnapsack(0, target, -1);
//    cout << time(NULL) - s << endl;
//
//    arq.close();
//    cout.rdbuf(coutbuf);
}
/***
    value: stands for the amount on the current knapsack
    target: stands for the ideal knapsack
    lastAdd: stands fot the last inserted value on the knapsack
***/
void KnapsackSolver::NormalRecursiveKnapsack(float value, float target, int lastAdd){
    if(value == target){
        float sum = 0;
        for(auto item : knapsack)
            if(get<1>(item))
                sum += get<2>(item);
        Print();
        cout << "Sum = " << sum << endl;
    }
    for(int i = lastAdd + 1; i < knapsack.size(); i++){
        if(!get<1>(knapsack.at(i))){
            get<1>(knapsack.at(i)) = 1;
            NormalRecursiveKnapsack(value + get<2>(knapsack.at(i)), target, i);
            get<1>(knapsack.at(i)) = 0;
        }
    }
}

void KnapsackSolver::SmartRecursiveKnapsack(float value, float target, int lastAdd){
    if(value == target){
        float sum = 0;
        for(auto item : knapsack)
            if(get<1>(item))
                sum += get<2>(item);
        Print();
        cout << "Sum = " << sum << endl;
        return;
    }
    else if(value > target)
        return;
    else{
        for(int i = lastAdd + 1; i < knapsack.size(); i++){
            if(!get<1>(knapsack.at(i))){
                get<1>(knapsack.at(i)) = 1;
                SmartRecursiveKnapsack(value + get<2>(knapsack.at(i)), target, i);
                get<1>(knapsack.at(i)) = 0;
            }
        }
    }
}

void KnapsackSolver::AlternativeSmartRecursiveKnapsack(float value, float target, int lastAdd){
    if(value == target){
        float sum = 0;
        for(auto item : knapsack)
            if(get<1>(item))
//                sum += get<2>(item);
        Print();
        cout << "Sum = " << sum << endl;
        return;
    }
    else if(value > target)
        return;
    else{
        for(int i = lastAdd + 1; i < knapsack.size(); i++){
            if(!get<1>(knapsack.at(i))){
                get<1>(knapsack.at(i)) = 1;
                SmartRecursiveKnapsack(value + get<2>(knapsack.at(i)), target, i);
                get<1>(knapsack.at(i)) = 0;
            }
        }
    }
}

KnapsackSolver::~KnapsackSolver(){
    //dtor
}
