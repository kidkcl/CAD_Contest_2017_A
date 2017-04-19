/****************************************************************************
  FileName     [ cirMiter.h ]
  PackageName  [ cir ]
  Synopsis     [ Define basic gate data structures ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2008-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef CIR_MITER_H
#define CIR_MITER_H

#include <string>
#include <vector>
#include <iostream>

#include "cirDef.h"
#include "cirMgr.h"
#include "sat.h"

using namespace std;

/************************************
 * Class CirMiter definition
************************************/
class CirMiter{
public:
    CirMiter();
    ~CirMiter();

    // init
    void    init();

    // building circuits
    void    readVerilog(const string& fileName1,
                        const string& fileName2);

private:
    CirMgr*         _ckt0;      // revised
    CirMgr*         _ckt1;      // golden
};

#endif // CIR_MITER_H
