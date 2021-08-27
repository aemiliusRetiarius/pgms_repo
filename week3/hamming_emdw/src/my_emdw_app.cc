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

/**                            **/

#include "emdw.hpp"

int main(int, char *argv[]) {

  unsigned seedVal = emdw::randomEngine.getSeedVal();
  cout <<  seedVal << endl;
  emdw::randomEngine.setSeedVal(seedVal);

  typedef DiscreteTable<unsigned> DT;

  rcptr< vector<unsigned> > aDom (
    new vector<unsigned>{0,1});

  rcptr<Factor> F0(
    uniqptr<DT>(
      new DT({0,1},{aDom,aDom}) ) );
  cout << *F0 << endl;

  prlite::gzofstream ofile("tmp.gz", static_cast<std::ios::openmode>(std::ios::out) );
  ofile << *F0 << endl;
  ofile.close();

} // main
