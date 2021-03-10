/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

%}

/*
 * Define names for regular expressions here.
 */

DARROW          =>
LE              <=
ASSIGN          <-
CLASS           ?i:class
ELSE            ?i:else
IF              ?i:if
IN              ?i:in
INHERITS        ?i:inherits
LET             ?i:let
LOOP            ?i:loop
POOL            ?i:pool
WHILE           ?i:while
CASE            ?i:case
ESAC            ?i:esac
OF              ?i:of
TRUE            true
FALSE           false
%%

 /*
  *  Nested comments
  */


 /*
  *  The multiple-character operators.
  */
<INITIAL>{DARROW}		{ return (DARROW); }
<INITIAL>{LE}		    { return (LE); }
<INITIAL>{ASSIGN}       {return (ASSIGN);}



 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */
<INITIAL>{CLASS}  { return (CLASS);}
<INITIAL>{ELSE}  {return (ELSE);}
<INITIAL>{IF}  {return (IF);}
<INITIAL>{IN}  {return (IN);}
<INITIAL>{INHERITS}  {return (INHERITS);}
<INITIAL>{LET}  {return (LET);}
<INITIAL>{LOOP}  {return (LOOP);}
<INITIAL>{POOL}  {return (POOL);}
<INITIAL>{WHILE}  {return (WHILE);}
<INITIAL>{CASE}  {return (CASE);}
<INITIAL>{ESAC}  {return (ESAC);}
<INITIAL>{OF}  {return (OF);}


<INITIAL>{TRUE}  {cool_yylval.boolean = true;return (BOOL_CONST);}
<INITIAL>{FALSE}  {cool_yylval.boolean = false;return (BOOL_CONST);}


<INITIAL>\+      {return '+';}
<INITIAL>\/      {return '/';}
<INITIAL>-      {return '-';}
<INITIAL>\*      {return '*';}
<INITIAL>=      {return '=';}
<INITIAL><      {return '<';}
<INITIAL>\.      {return '.';}
<INITIAL>~      {return '~';}
<INITIAL>,      {return ',';}
<INITIAL>;      {return ';';}
<INITIAL>:      {return ':';}
<INITIAL>\(      {return '(';}
<INITIAL>\)      {return ')';}
<INITIAL>@      {return '@';}
<INITIAL>\{      {return '{';}
<INITIAL>\}      {return '}';}

%%
