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

int index = 0;
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

BLANK          " "|"\n"|"\f"|"\r"|"\t"|"\v"


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
<INITIAL>[Ii][Ss][Vv][Oo][Ii][Dd]    {return (ISVOID)};}
<INITIAL>[Ll][Ee][Tt]        {return (LET);}
<INITIAL>[Ll][Oo][Oo][Pp]     {return (LOOP);}
<INITIAL>[Pp][Oo][Oo][Ll]       {return (POOL);}
<INITIAL>[Tt][Hh][Ee][Nn]        {return (THEN);}
<INITIAL>[Ww][Hh][Ii][Ll][Ee]     {return (WHILE);}
<INITIAL>[Cc][Aa][Ss][Ee]        {return (CASE);}
<INITIAL>[Ee][Ss][Aa][Cc]     {return (ESAC);}
<INITIAL>[Nn][Ee][Ww]     {return (NEW);}
<INITIAL>[Oo][Ff]       {return (OF);}
<INITIAL>[Nn][Oo][Tt]{return (NOT);}
<INITIAL>f[Aa][Ll][Ss][Ee]      {cool_yylval.boolean = 0;
                        return (BOOL_CONST);}
<INITIAL>t[Rr][Uu][Ee]      {cool_yylval.boolean = 1;
                    return (BOOL_CONST);}


/*
 * operations
 */
<INITIAL>{DARROW}		{ return (DARROW);}
<INITIAL>{ASSIGN}        { return (ASSIGN);}
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

<INITIAL>[1-9][0-9]*        {
                            cool_yylval.symbol = inttable.add_string(yytext);
                            return (INT_CONST);}

<INITIAL>[_a-zA-Z0-9]+         {
                            cool_yylval.symbol = strtable.add_string(yytext);
                            return (OBJECTID);}


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

<LINE_COMMENT>"\n"      {BEGIN(INITIAL);}


/*
 * BLOCK_COMMENT
 */
<BLOCK_COMMENT>"*)"     {BEGIN(INITIAL);}
<BLOCK_COMMENT>0         {
                     strcpy(cool_yylval.error_msg,"EOF in comment");
                     return ERROR;}

/* STRING
 *
 */

<STRING>\0             {
                       strcpy(cool_yylval.error_msg,"String contains null character");
                       return ERROR;}
<STRING>0              {
                       strcpy(cool_yylval.error_msg,"EOF in string constant");
                       return ERROR;}
<STRING>\n             {
                       strcpy(cool_yylval.error_msg,"unterminated string constant");
                       return ERROR;}
<STRING>\\n            {
                       if(index >= MAX_STR_CONST){
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[index++] = '\n';}
<STRING>\\t            {
                       if(index >= MAX_STR_CONST){
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[index++] = '\t';}
<STRING>\\b            {
                       if(index >= MAX_STR_CONST){
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[index++] = '\b';}
<STRING>\\f            {
                       if(index >= MAX_STR_CONST){
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[index++] = '\f';}
<STRING>\\.            {
                       if(index >= MAX_STR_CONST){
                       strcpy(cool_yylval.error_msg,"String constant too long");
                       return ERROR;
                       }
                       string_buf[index++] = yytext[1];}
<STRING>.              {
                       if(index >= MAX_STR_CONST){
                           strcpy(cool_yylval.error_msg,"String constant too long");
                           return ERROR;
                       }
                       string_buf[index++] = *yytext;}


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
