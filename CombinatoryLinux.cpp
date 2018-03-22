//#include "stdafx.h"
#include <iostream>
//#include <windows.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include <math.h>
#include <ctime>
#include <fstream>
#include <sstream>
#define min(a, b)((a) <(b) ? (a) : (b))

using namespace std;

void comb(int N, int K) {
  std::string bitmask(K, 1);
  bitmask.resize(N, 0);

  do {
    for (int i = 0; i <N; ++i) {
      if (bitmask[i]) {
//        std::cout <<" " <<i;
      }
    }
    //std::cout <<std::endl;
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

int main() {
  std::ofstream out;
  int n = 38;
  stringstream str;
  str << "linux/" << n << ".txt";
  out.open(str.str());
  std::time_t t = std::time(NULL);
  std::tm* tm = std::localtime(&t);
  out <<  tm->tm_mday << "-"
      << (tm->tm_mon + 1) << "-"
      << (tm->tm_year + 1900) << " "
      <<  tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << endl;

  for (int i = 1; i <= n; i++) {
      comb(n, i);
      out <<"loop " << i <<" de " <<n <<endl;
  }
  std::time_t t2 = std::time(NULL);
  tm = std::localtime(&t2);
  out <<  tm->tm_mday << "-"
      << (tm->tm_mon + 1) << "-"
      << (tm->tm_year + 1900) << " "
      <<  tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << endl;
  out << double(difftime(t2, t)) << endl;
  out.close();

  return 0;
}
