#ifndef KNAPSACKSOLVER_H
#define KNAPSACKSOLVER_H

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <ctime>
#include <fstream>

using namespace std;

class KnapsackSolver
{
    public:
        KnapsackSolver();
        virtual ~KnapsackSolver();

        void RecursiveKnapsack(float target);
        void AddItem(string name, bool status, float value);

        void Print(bool all = false);
    protected:

    private:
        vector<tuple<string, bool, float> > knapsack;
        float lowest;

        static bool IncreasingSortItems(tuple<string, bool, float> a, tuple<string, bool, float> b);
        static bool DecreasingSortItems(tuple<string, bool, float> a, tuple<string, bool, float> b);
        void NormalRecursiveKnapsack(float total, float target, int lastAdd);
        void SmartRecursiveKnapsack(float total, float target, int lastAdd);
        void AlternativeSmartRecursiveKnapsack(float total, float target, int lastAdd);
};

#endif // KNAPSACK_H
