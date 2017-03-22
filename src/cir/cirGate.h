/****************************************************************************
  FileName     [ cirGate.h ]
  PackageName  [ cir ]
  Synopsis     [ Define basic gate data structures ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2008-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef CIR_GATE_H
#define CIR_GATE_H

#include <string>
#include <vector>
#include <iostream>
#include "cirDef.h"
#include "sat.h"

using namespace std;

// TODO: Feel free to define your own classes, variables, or functions.

class CirGate;

//------------------------------------------------------------------------
//   Define classes
//------------------------------------------------------------------------
class CirGateV
{
#define NEG 0x1
public:
   CirGateV() {}
   CirGateV(CirGate* g, size_t phase) _gateV(size_t(g)+phase) {}
   ~CirGateV() {}
   CirGate* getGate() { return (CirGate*)(_gateV & ~(size_t)NEG); }
   bool     isInv() { return (_gateV & NEG); }

private:
   size_t _gateV;
};
//------------------------------------------------------------------------
//   Define classes
//------------------------------------------------------------------------
class CirGate
{
public:
   CirGate(unsigned g, unsigned l) _id(g), _lineNo(l), {}
   virtual ~CirGate() {}

   // Basic access methods
   string getTypeStr() const = 0;
   unsigned getLineNo() const { return _lineNo; }
   unsigned getGateId() const { return _id; }
   virtual bool isAig() const { return false; }

   // Printing functions
   virtual void printGate() const = 0; // for cirp -netlist
   void reportGate() const; // for cirg
   void reportFanin(int level) const;
   void reportFanout(int level) const;

   // Helper functions
   size_t fanoutSize() { return _fanoutList.size(); }
   
private:
   unsigned    _id;
   unsigned    _lineNo;
   CirGateV    _phase;
protected:
   fanoutArr   _fanoutList;
};


//------------------------------------------------------------------------
//   Define classes
//------------------------------------------------------------------------
class CirPiGate: public CirGate
{
public:
   CirPiGate(unsigned g, unsigned l) CirGate(g,l), _name(0) {}
   ~CirPiGate() {}
   string getTypeStr() { return "PI"; }
   bool isPi() { return true; }
private:
   char* _name;
};

//------------------------------------------------------------------------
//   Define classes
//------------------------------------------------------------------------
class CirPoGate: public CirGate
{
public:
   CirPoGate(unsigned g, unsigned l) CirGate(g,l), _name(0) {}
   ~CirPoGate() {}
   string getTypeStr() { return "PO"; }
   bool isPo() { return true; }
private:
   char* _name;
};

//------------------------------------------------------------------------
//   Define classes
//------------------------------------------------------------------------
class CirAigGate: public CirGate
{
public:
   CirAigGate(unsigned g, unsigned l) CirGate(g,l) {}
   ~CirAigGate() {}
   CirGateV getIn0() { return _in0; }
   CirGateV getIn1() { return _in1; }
   CirGate* getIn0Gate() { return _in0.getGate(); }
   CirGate* getIn1Gate() { return _in1.getGate(); }
   unsigned getNumFanin() { return 2; }

   string getTypeStr() { return "AIG"; }
   bool isAig() { return true; }
private:
   CirGateV _in0;
   CirGateV _in1;

};
//------------------------------------------------------------------------
//   Define classes
//------------------------------------------------------------------------
class CirUndefGate: public CirGate
{
public:
   CirUndefGate(unsigned g) CirGate(g,0), _name(0) {}
   ~CirUndefGate() {}
   string getTypeStr() { return "UNDEF"; }
   bool isUndef() { return true; }
private:
   char* _name;
};

#endif // CIR_GATE_H
