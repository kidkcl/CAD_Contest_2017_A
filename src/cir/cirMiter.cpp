/****************************************************************************
  FileName     [ cirGate.cpp ]
  PackageName  [ cir ]
  Synopsis     [ Define class CirAigGate member functions ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2008-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdarg.h>
#include <cassert>

#include "cirMiter.h"
#include "util.h"

using namespace std;


/**************************************/
/*   class CirMiter member functions  */
/**************************************/
CirMiter::CirMiter(): _ckt0(NULL), _ckt1(NULL) {
    init();
}

CirMiter::~CirMiter() {
    if(_ckt0 != NULL) delete _ckt0;
    if(_ckt1 != NULL) delete _ckt1;
}

void CirMiter::init() {
    if(_ckt0 != NULL) delete _ckt0;
    if(_ckt1 != NULL) delete _ckt1;
    _ckt0 = new CirMgr;
    _ckt1 = new CirMgr;
}

void CirMiter::readVerilog(const std::string& fileName1, const std::string& fileName2) {
    init();
    _ckt0->readVerilog(fileName1);
    _ckt1->readVerilog(fileName2);
}
