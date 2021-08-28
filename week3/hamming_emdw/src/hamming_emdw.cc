/*
 * Author     :  (DSP Group, E&E Eng, US)
 * Created on :
 * Copyright  : University of Stellenbosch, all rights retained
 */

// standard headers
#include <iostream>  // cout, endl, flush, cin, cerr

#include "discretetable.hpp"
#include "prlite_zfstream.hpp"

using namespace std;
using namespace emdw;


/**                            **/

#include "emdw.hpp"

int main(int, char *argv[]) {

  // Type Setup
    typedef unsigned T;
    typedef DiscreteTable<T> DT;
    vector<rcptr<Factor>> factors;
    rcptr<vector<T>> bit_domain (new vector<T>{0,1});
    enum{B0,B1,B2,B3,B4,B5,B6,R0,R1,R2,R3,R4,R5,R6};

  factors.push_back(
    uniqptr<DT>(
      new DT({B0, B1, B2, B4},{bit_domain, bit_domain, bit_domain, bit_domain}, 0.0,
        {
          {{0,0,0,0},1.0},
          {{0,0,1,1},1.0},
          {{0,1,0,1},1.0},
          {{0,1,1,0},1.0},
          {{1,0,0,1},1.0},
          {{1,0,1,0},1.0},
          {{1,1,0,0},1.0},
          {{1,1,1,1},1.0},
        }
      ) 
    ) 
  );

  factors.push_back(
    uniqptr<DT>(
      new DT({B0, B2, B3, B5},{bit_domain, bit_domain, bit_domain, bit_domain}, 0.0,
        {
          {{0,0,0,0},1.0},
          {{0,0,1,1},1.0},
          {{0,1,0,1},1.0},
          {{0,1,1,0},1.0},
          {{1,0,0,1},1.0},
          {{1,0,1,0},1.0},
          {{1,1,0,0},1.0},
          {{1,1,1,1},1.0},
        }
      ) 
    ) 
  );

  factors.push_back(
    uniqptr<DT>(
      new DT({B0, B1, B3, B6},{bit_domain, bit_domain, bit_domain, bit_domain}, 0.0,
        {
          {{0,0,0,0},1.0},
          {{0,0,1,1},1.0},
          {{0,1,0,1},1.0},
          {{0,1,1,0},1.0},
          {{1,0,0,1},1.0},
          {{1,0,1,0},1.0},
          {{1,1,0,0},1.0},
          {{1,1,1,1},1.0},
        }
      ) 
    ) 
  );

  cout << *(absorb(factors) -> normalize()) << endl;

  cout << *(absorb(factors) -> observeAndReduce(RVIds{B0,B1,B2,B3}, RVVals{T(1),T(0),T(1),T(0)})) << endl;

} // main
