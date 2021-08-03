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

int string_buf_index = 0;
/*
 *  Add Your own definitions here
 */

%}

/*
 * Define names for regular expressions here.
 */

/*
 *definitions allow us to give names to regular expressions
 */

DARROW          =>
ASSIGN          <-
LE              <=
BLANK          " "|"\f"|"\r"|"\t"|"\v"


%x LINE_COMMENT BLOCK_COMMENT STRING

%%

 /*
  *  Nested comments
  */


 /*
  *  The multiple-character operators.
  */


 /*
  * keywords
  */
<INITIAL>[Cc][Ll][Aa][Ss][Ss]       {return (CLASS);}
<INITIAL>[Ee][Ll][Ss][Ee]     {return (ELSE);}
<INITIAL>[Ff][Ii]       {return (FI);}
<INITIAL>[Ii][Ff]        {return (IF);}
<INITIAL>[Ii][Nn]    {return (IN);}
<INITIAL>[Ii][Nn][Hh][Ee][Rr][Ii][Tt][Ss]       {return (INHERITS);}
<INITIAL>[Ii][Ss][Vv][Oo][Ii][Dd]    {return (ISVOID);}
<INITIAL>[Ll][Ee][Tt]        {return (LET);}
<INITIAL>[Ll][Oo][Oo][Pp]     {return (LOOP);}
<INITIAL>[Pp][Oo][Oo][Ll]       {return (POOL);}
<INITIAL>[Tt][Hh][Ee][Nn]        {return (THEN);}
<INITIAL>[Ww][Hh][Ii][Ll][Ee]     {return (WHILE);}
<INITIAL>[Cc][Aa][Ss][Ee]        {return (CASE);}
<INITIAL>[Ee][Ss][Aa][Cc]     {return (ESAC);}
<INITIAL>[Nn][Ee][Ww]     {return (NEW);}
<INITIAL>[Oo][Ff]       {return (OF);}
<INITIAL>[Nn][Oo][Tt]    {return (NOT);}
<INITIAL>f[Aa][Ll][Ss][Ee]      {cool_yylval.boolean = 0;
                        return (BOOL_CONST);}
<INITIAL>t[Rr][Uu][Ee]      {cool_yylval.boolean = 1;
                    return (BOOL_CONST);}




 /*
 * operations
 */
<INITIAL>{DARROW}		{ return (DARROW);}
<INITIAL>{ASSIGN}        { return (ASSIGN);}
<INITIAL>{LE}        { return (LE);}
<INITIAL>"+"       {return ('+');}
<INITIAL>"/"       {return ('/');}
<INITIAL>"-"       {return ('-');}
<INITIAL>"*"       {return ('*');}
<INITIAL>"="       {return ('=');}
<INITIAL>"<"       {return ('<');}
<INITIAL>"."       {return ('.');}
<INITIAL>"~"       {return ('~');}
<INITIAL>","       {return (',');}
<INITIAL>";"       {return (';');}
<INITIAL>":"       {return (':');}
<INITIAL>"("       {return ('(');}
<INITIAL>")"       {return (')');}
<INITIAL>"@"       {return ('@');}
<INITIAL>"{"       {return ('{');}
<INITIAL>"}"       {return ('}');}




 /*  integers
 *
 */





<INITIAL>[0-9]+        {
                            cool_yylval.symbol = inttable.add_string(yytext);
                            return (INT_CONST);}

<INITIAL>[A-Z][_a-zA-Z0-9]*         {
                                        cool_yylval.symbol = stringtable.add_string(yytext);
                                        return (TYPEID);}

<INITIAL>[_a-zA-Z0-9]+         {
                            cool_yylval.symbol = stringtable.add_string(yytext);
                            return (OBJECTID);}
<INITIAL>{BLANK}    {}
<INITIAL>"\n"       {curr_lineno++;}
 /* comments
 *
 */



<INITIAL>"--"                 {BEGIN(LINE_COMMENT);}
<INITIAL>"(*"                 {BEGIN(BLOCK_COMMENT);}
<INITIAL>"*)"            {
                          strcpy(cool_yylval.error_msg,"Unmatched *)");
                          return ERROR;}

 /* LINE_COMMENT
  *
  */

<LINE_COMMENT>"\n"      {curr_lineno++;BEGIN(INITIAL);}
<LINE_COMMENT>.  {}

 /*
 * BLOCK_COMMENT
 */
<BLOCK_COMMENT>"*)"     {BEGIN(INITIAL);}
<BLOCK_COMMENT><<EOF>>         {
                     BEGIN(INITIAL);
                     strcpy(cool_yylval.error_msg,"EOF in comment");
                     return ERROR;}
<BLOCK_COMMENT>\n     {curr_lineno++;}
<BLOCK_COMMENT>.     {}

<INITIAL>\"                 {BEGIN(STRING);
                                memset(string_buf,0,MAX_STR_CONST);
                                string_buf_index = 0;}
<STRING>\"          {   BEGIN(INITIAL);
                        cool_yylval.symbol = stringtable.add_string(string_buf);
                        return STR_CONST;}

<BLOCK_COMMENT><<EOF>>         {
                            BEGIN(INITIAL);
                            strcpy(cool_yylval.error_msg,"EOF in comment");
                            return ERROR;}

 /* STRING
 *
 */

<STRING>\0             {
                        BEGIN(INITIAL);
                       strcpy(cool_yylval.error_msg,"String contains null character");
                       return ERROR;}
<STRING><<EOF>>        {
                        BEGIN(INITIAL);
                       strcpy(cool_yylval.error_msg,"EOF in string constant");
                       return ERROR;}
<STRING>\n             {

                        BEGIN(INITIAL);
                       strcpy(cool_yylval.error_msg,"unterminated string constant");
                       return ERROR;}
<STRING>\\n            {
                       if(string_buf_index >= MAX_STR_CONST){
                           BEGIN(INITIAL);
                           strcpy(cool_yylval.error_msg,"String constant too long");
                           return ERROR;
                       }
                       string_buf[string_buf_index++] = '\n';}
<STRING>\\t            {
                       if(string_buf_index >= MAX_STR_CONST){
                        BEGIN(INITIAL);
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[string_buf_index++] = '\t';}
<STRING>\\b            {
                       if(string_buf_index >= MAX_STR_CONST){
                        BEGIN(INITIAL);
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[string_buf_index++] = '\b';}
<STRING>\\f            {
                       if(string_buf_index >= MAX_STR_CONST){
                        BEGIN(INITIAL);
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[string_buf_index++] = '\f';}
<STRING>\\.            {
                       if(string_buf_index >= MAX_STR_CONST){
                        BEGIN(INITIAL);
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[string_buf_index++] = yytext[1];}
<STRING>.              {
                       if(string_buf_index >= MAX_STR_CONST){
                            BEGIN(INITIAL);
                           strcpy(cool_yylval.error_msg,"String constant too long");
                           return ERROR;
                       }
                       string_buf[string_buf_index++] = *yytext;}

<INITIAL>.    { strcpy(cool_yylval.error_msg,yytext);return ERROR;}
 /*
* Keywords are case-insensitive except for the values true and false,
* which must begin with a lower-case letter.
*/


 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for
  *  \n \t \b \f, the result is c.
  *
  */


%%
