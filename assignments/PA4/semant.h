#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>  
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"
#include <map>
#include <unordered_map>
#include <set>

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.

class ClassTable {
private:
  int semant_errors;
  void install_basic_classes();
  ostream& error_stream;

  SymbolTable<Symbol,Symbol> attrs;
  void installClasses(Classes &classes);
  int checkInheritanceCycle(Classes &classes);
  void installMethods();
  int checkMain();
  void checkMethods();
public:

  ClassTable(Classes);
  int errors() { return semant_errors; }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
  std::unordered_map<Symbol,Class_> class_table; // Symbol -> class
  std::unordered_map<Class_,std::set<method_class*>> method_table; // class -> methods

  std::vector<Class_> getAncestors(Class_ curr_class);
  bool canConform(Symbol ltype,Symbol rType);
};


#endif

