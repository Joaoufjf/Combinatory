#ifndef KNAPSACKSOLVER_H
#define KNAPSACKSOLVER_H

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <limits>
#include <cmath>
#include <unistd.h> // for usleep

using namespace std;

class KnapsackSolver
{
    public:
        KnapsackSolver();
        virtual ~KnapsackSolver();

        void RecursiveKnapsack(int target, int cumulated);
        void AddItem(string name, bool status, int value);

        void Print(bool all = false);
    protected:

    private:
        vector<tuple<string, bool, int> > knapsack;
        int lowest;
	int sum;
	int target;
	int cumulated;

        static bool IncreasingSortItems(tuple<string, bool, int> a, tuple<string, bool, int> b);
        static bool DecreasingSortItems(tuple<string, bool, int> a, tuple<string, bool, int> b);
        static bool StatusSortItems(tuple<string, bool, int> a, tuple<string, bool, int> b);
        void NormalRecursiveKnapsack(int total, int lastAdd);
        void SmartRecursiveKnapsack(int total, int lastAdd);
        void AlternativeSmartRecursiveKnapsack(int total, int lastAdd);
};

#endif // KNAPSACK_H
