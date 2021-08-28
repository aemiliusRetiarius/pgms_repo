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

  double P_e = 0.01;

    //P(R0|B0)
    factors.push_back(
        uniqptr<DT>(
            new DT({B0,R0}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0},1-P_e},
                    {{0,1},P_e},
                    {{1,0},P_e},
                    {{1,1},1-P_e},
                }
            )
        )
    );

    //P(R1|B1)
    factors.push_back(
        uniqptr<DT>(
            new DT({B1,R1}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0},1-P_e},
                    {{0,1},P_e},
                    {{1,0},P_e},
                    {{1,1},1-P_e},
                }
            )
        )
    );

    //P(R2|B2)
    factors.push_back(
        uniqptr<DT>(
            new DT({B2,R2}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0},1-P_e},
                    {{0,1},P_e},
                    {{1,0},P_e},
                    {{1,1},1-P_e},
                }
            )
        )
    );

    //P(R3|B3)
    factors.push_back(
        uniqptr<DT>(
            new DT({B3,R3}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0},1-P_e},
                    {{0,1},P_e},
                    {{1,0},P_e},
                    {{1,1},1-P_e},
                }
            )
        )
    );

    //P(R4|B4)
    factors.push_back(
        uniqptr<DT>(
            new DT({B4,R4}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0},1-P_e},
                    {{0,1},P_e},
                    {{1,0},P_e},
                    {{1,1},1-P_e},
                }
            )
        )
    );

    //P(R5|B5)
    factors.push_back(
        uniqptr<DT>(
            new DT({B5,R5}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0},1-P_e},
                    {{0,1},P_e},
                    {{1,0},P_e},
                    {{1,1},1-P_e},
                }
            )
        )
    );

    //P(R6|B6)
    factors.push_back(
        uniqptr<DT>(
            new DT({B6,R6}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0},1-P_e},
                    {{0,1},P_e},
                    {{1,0},P_e},
                    {{1,1},1-P_e},
                }
            )
        )
    );

} // main