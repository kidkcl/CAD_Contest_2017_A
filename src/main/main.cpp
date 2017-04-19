/****************************************************************************
  FileName     [ main.cpp ]
  PackageName  [ main ]
  Synopsis     [ Define main() ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#include "util.h"
#include "cirMiter.h"
#include "cmdParser.h"

//using namespace std;

//----------------------------------------------------------------------
//    Global cmd Manager
//----------------------------------------------------------------------
int
main(int argc, char** argv)
{
   if(argc == 6) {
       CirMiter* miter = new CirMiter;
   }
   return 0;
}
