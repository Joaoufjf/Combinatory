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

  for(int n = 1; n <= 30; n++){
    stringstream str;
    str << "windows/" << n << ".txt";
    out.open(str.str());
    std::time_t t = std::time(nullptr);
    std::tm* tm = std::localtime( & t);
//    std::cout << std::put_time(&tm, "%d-%m-%Y %H:%M:%S") << std::endl;
//    std::cout << std::localtime( & t) << std::endl;
    out << (tm->tm_year + 1900) << '-'
        << (tm->tm_mon + 1) << '-'
        <<  tm->tm_mday << ", "
        <<  tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << endl;

    for (int i = 1; i <= n; i++) {
        comb(n, i);
        out <<"loop " << i <<" de " <<n <<endl;
    }
    t = std::time(nullptr);
    tm = std::localtime( & t);
    out << (tm->tm_year + 1900) << '-'
        << (tm->tm_mon + 1) << '-'
        <<  tm->tm_mday << ", "
        <<  tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << endl;
    out.close();
  }

  //system("pause");
  return 0;
}
