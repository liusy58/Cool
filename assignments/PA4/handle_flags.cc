//
// See copyright.h for copyright notice and limitation of liability
// and disclaimer of warranty provisions.
//
#include "copyright.h"

#include <stdio.h>
#include <stdlib.h>
#include "cool-io.h"
#include <unistd.h>
#include "cgen_gc.h"

//
// coolc provides a debugging switch for each phase of the compiler,
// switches to control garbage collection policy, and a switch to enable 
// optimization.  The optimization flag is ignored by the reference compiler.
//
// All flags that can be set on the command line should be defined here;
// otherwise, it is necessary to pollute test drivers for components of the
// compiler with declarations of extern'ed debugging flags to satisfy the
// linker.  The exceptions to this rule are yy_flex_debug and cool_yydebug, 
// which are defined in files generated by flex and bison.
//

extern int yy_flex_debug;       // for the mylexer; prints recognized rules
extern int cool_yydebug;        // for the parser
       int lex_verbose;         // also for the mylexer; prints tokens
       int semant_debug;        // for semantic analysis
       int cgen_debug;          // for code gen
       bool disable_reg_alloc;  // Don't do register allocation

       int cgen_optimize;       // optimize switch for code generator 
       char *out_filename;      // file name for generated code
       Memmgr cgen_Memmgr = GC_NOGC;      // enable/disable garbage collection
       Memmgr_Test cgen_Memmgr_Test = GC_NORMAL;  // normal/test GC
       Memmgr_Debug cgen_Memmgr_Debug = GC_QUICK; // check heap frequently

// used for option processing (man 3 getopt for more info)
extern int optind, opterr;
extern char *optarg;

void handle_flags(int argc, char *argv[]) {
  int c;
  int unknownopt = 0;

  // no debugging or optimization by default
  yy_flex_debug = 0;
  cool_yydebug = 0;
  lex_verbose  = 0;
  semant_debug = 0;
  cgen_debug = 0;
  cgen_optimize = 0;
  disable_reg_alloc = 0;
  

  while ((c = getopt(argc, argv, "lpscvrOo:gtT")) != -1) {
    switch (c) {
#ifdef DEBUG
    case 'l':
      yy_flex_debug = 1;
      break;
    case 'p':
      cool_yydebug = 1;
      break;
    case 's':
      semant_debug = 1;
      break;
    case 'c':
      cgen_debug = 1;
      break;
    case 'v':
      lex_verbose = 1;
      break;
    case 'r':
      disable_reg_alloc = 1;
      break;
#else
    case 'l':
    case 'p':
    case 's':
    case 'c': 
    case 'v':
    case 'r':
      cerr << "No debugging available\n";
      break;
#endif
    case 'g':  // enable garbage collection
      cgen_Memmgr = GC_GENGC;
      break;
    case 't':  // run garbage collection very frequently (on every allocation)
      cgen_Memmgr_Test = GC_TEST;
      break;
    case 'T':  // do even more pedantic tests in garbage collection
      cgen_Memmgr_Debug = GC_DEBUG;
      break;
    case 'o':  // set the name of the output file
      out_filename = optarg;
      break;
    case 'O':  // enable optimization
      cgen_optimize = 1;
      break;
    case '?':
      unknownopt = 1;
      break;
    case ':':
      unknownopt = 1;
      break;
    }
  }

  if (unknownopt) {
      cerr << "usage: " << argv[0] << 
#ifdef DEBUG
	  " [-lvpscOgtTr -o outname] [input-files]\n";
#else
      " [-OgtT -o outname] [input-files]\n";
#endif
      exit(1);
  }

}
