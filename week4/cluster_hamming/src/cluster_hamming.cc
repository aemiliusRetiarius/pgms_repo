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

  //P(B4|B0,B1,B2)
    rcptr<Factor> C7(
        uniqptr<DT>(
            new DT({B0,B1,B2,B4}, {bit_domain,bit_domain,bit_domain,bit_domain}, 0.0,
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

    //P(B5|B0,B2,B3)
    rcptr<Factor> C8(
        uniqptr<DT>(
            new DT({B0,B2,B3,B5}, {bit_domain,bit_domain,bit_domain,bit_domain}, 0.0,
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

    //P(B6|B0,B1,B3)
    rcptr<Factor> C9(
        uniqptr<DT>(
            new DT({B0,B1,B3,B6}, {bit_domain,bit_domain,bit_domain,bit_domain}, 0.0,
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
    //double P_e = 0.9;

    //P(R0|B0)
    rcptr<Factor> C0(
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
    rcptr<Factor> C1(
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
    rcptr<Factor> C2(
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
    rcptr<Factor> C3(
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
    rcptr<Factor> C4(
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
    rcptr<Factor> C5(
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
    rcptr<Factor> C6(
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

    rcptr<Factor> M07(
        uniqptr<DT>(
            new DT({B0}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M70(
        uniqptr<DT>(
            new DT({B0}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M17(
        uniqptr<DT>(
            new DT({B1}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M71(
        uniqptr<DT>(
            new DT({B1}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M27(
        uniqptr<DT>(
            new DT({B2}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M72(
        uniqptr<DT>(
            new DT({B2}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M47(
        uniqptr<DT>(
            new DT({B4}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M74(
        uniqptr<DT>(
            new DT({B4}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M38(
        uniqptr<DT>(
            new DT({B3}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M83(
        uniqptr<DT>(
            new DT({B3}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M58(
        uniqptr<DT>(
            new DT({B5}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M85(
        uniqptr<DT>(
            new DT({B0}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M69(
        uniqptr<DT>(
            new DT({B6}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M96(
        uniqptr<DT>(
            new DT({B6}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M89(
        uniqptr<DT>(
            new DT({B3}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M98(
        uniqptr<DT>(
            new DT({B3}, {bit_domain}, 0.0,
                {
                    {{0}, 1.0},
                    {{1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M78(
        uniqptr<DT>(
            new DT({B0,B2}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0}, 1.0},
                    {{0,1}, 1.0},
                    {{1,0}, 1.0},
                    {{1,1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M87(
        uniqptr<DT>(
            new DT({B0,B2}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0}, 1.0},
                    {{0,1}, 1.0},
                    {{1,0}, 1.0},
                    {{1,1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M79(
        uniqptr<DT>(
            new DT({B0,B1}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0}, 1.0},
                    {{0,1}, 1.0},
                    {{1,0}, 1.0},
                    {{1,1}, 1.0},
                }
            )
        )
    );

    rcptr<Factor> M97(
        uniqptr<DT>(
            new DT({B0,B1}, {bit_domain,bit_domain}, 0.0,
                {
                    {{0,0}, 1.0},
                    {{0,1}, 1.0},
                    {{1,0}, 1.0},
                    {{1,1}, 1.0},
                }
            )
        )
    );

} // main
