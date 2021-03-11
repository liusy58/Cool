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
static int string_buf_index = 0;


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

%x BLOCK_COMMENT LINE_COMMENT TYPE_DECLARE STRING

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
NEW             ?i:new
FI              ?i:fi
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
<INITIAL>{NEW}  {return (NEW);}
<INITIAL>{FI}  {return (FI);}


<INITIAL>{TRUE}  {cool_yylval.boolean = true;return (BOOL_CONST);}
<INITIAL>{FALSE}  {cool_yylval.boolean = false;return (BOOL_CONST);}


<INITIAL>\+      {return '+';}
<INITIAL>\/      {return '/';}
<INITIAL>-      {return '-';}
<INITIAL>\*      {return '*';}
<INITIAL>=      {return '=';}
<INITIAL><      {return '<';}
<INITIAL>>      {return '<';}
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
<INITIAL>\[      {return '[';}
<INITIAL>\]      {return ']';}


<INITIAL>\(\*    {BEGIN(BLOCK_COMMENT);}
<INITIAL>\n      {curr_lineno++;}
<INITIAL>\f     {continue;}
<INITIAL>\r     {continue;}
<INITIAL>\t     {continue;}
<INITIAL>\v     {continue;}
<INITIAL>" "    {continue;}
<INITIAL>--     {BEGIN(LINE_COMMENT);}
<LINE_COMMENT>\n      {curr_lineno++;BEGIN(INITIAL);}
<LINE_COMMENT>.       {continue;}


<INITIAL>IO   {cool_yylval.symbol = idtable.add_string(yytext, yyleng);return(TYPEID);}
<INITIAL>Object   {cool_yylval.symbol = idtable.add_string(yytext, yyleng);return(TYPEID);}
<INITIAL>Int   {cool_yylval.symbol = idtable.add_string(yytext, yyleng);return(TYPEID);}
<INITIAL>String   {cool_yylval.symbol = idtable.add_string(yytext, yyleng);return(TYPEID);}
<INITIAL>Bool   {cool_yylval.symbol = idtable.add_string(yytext, yyleng);return(TYPEID);}
<INITIAL>SELF_TYPE   {cool_yylval.symbol = idtable.add_string(yytext, yyleng);return(TYPEID);}



<INITIAL>[a-zA-Z][a-zA-Z0-9_]*   {cool_yylval.symbol = idtable.add_string(yytext, yyleng);return(OBJECTID);}
<INITIAL>[0-9]*   {cool_yylval.symbol = inttable.add_string(yytext, yyleng);return(INT_CONST);}


<INITIAL>"\""    {string_buf_index = 0;memset(string_buf,'\0',sizeof(string_buf));BEGIN(STRING);}
<STRING>"\""     {
                    BEGIN(INITIAL);
                    string_buf[string_buf_index++] = '\0';
                    printf("in STRING and the string is %s\n",string_buf);
                    cool_yylval.symbol = stringtable.add_string(string_buf,MAX_STR_CONST);
                    return (STR_CONST); }
<STRING>.        {
                    string_buf[string_buf_index++] = *yytext;}


<BLOCK_COMMENT>\*\)    {BEGIN(INITIAL);}
<BLOCK_COMMENT>\n      {curr_lineno++;}
<BLOCK_COMMENT>.       {}


%%
