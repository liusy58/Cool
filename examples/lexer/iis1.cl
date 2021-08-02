(* Integers, Identifiers, and Special Notation *)

0007 123 +1 -1 +90 -09 +11113 -4r *a *self* c++ 
5! = 120, 2 + 2 = 5 or E = mc2; p + 1 @ p = 1:  for x in range(len(b))
new / <- <<==> {( Int: Objet, Bool; String.string SELF_TYPE isvoid })
class Class if then else fi testing Testing ~007agent_bond james_007B0N3SS___
loop pool while tRuE or noT faLsE let in case of ESAC

(*
#3 INT_CONST 0007
#3 INT_CONST 123
#3 '+'
#3 INT_CONST 1
#3 '-'
#3 INT_CONST 1
#3 '+'
#3 INT_CONST 90
#3 '-'
#3 INT_CONST 09
#3 '+'
#3 INT_CONST 11113
#3 '-'
#3 INT_CONST 4
#3 OBJECTID r
#3 '*'
#3 OBJECTID a
#3 '*'
#3 OBJECTID self
#3 '*'
#3 OBJECTID c
#3 '+'
#3 '+'
#4 INT_CONST 5
#4 ERROR "!"
#4 '='
#4 INT_CONST 120
#4 ','
#4 INT_CONST 2
#4 '+'
#4 INT_CONST 2
#4 '='
#4 INT_CONST 5
#4 OBJECTID or
#4 TYPEID E
#4 '='
#4 OBJECTID mc2
#4 ';'
#4 OBJECTID p
#4 '+'
#4 INT_CONST 1
#4 '@'
#4 OBJECTID p
#4 '='
#4 INT_CONST 1
#4 ':'
#4 OBJECTID for
#4 OBJECTID x
#4 IN
#4 OBJECTID range
#4 '('
#4 OBJECTID len
#4 '('
#4 OBJECTID b
#4 ')'
#4 ')'
#5 NEW
#5 '/'
#5 ASSIGN
#5 '<'
#5 LE
#5 DARROW
#5 '{'
#5 '('
#5 TYPEID Int
#5 ':'
#5 TYPEID Objet
#5 ','
#5 TYPEID Bool
#5 ';'
#5 TYPEID String
#5 '.'
#5 OBJECTID string
#5 TYPEID SELF_TYPE
#5 ISVOID
#5 '}'
#5 ')'
#6 CLASS
#6 CLASS
#6 IF
#6 THEN
#6 ELSE
#6 FI
#6 OBJECTID testing
#6 TYPEID Testing
#6 '~'
#6 INT_CONST 007
#6 OBJECTID agent_bond
#6 OBJECTID james_007B0N3SS___
#7 LOOP
#7 POOL
#7 WHILE
#7 BOOL_CONST true
#7 OBJECTID or
#7 NOT
#7 BOOL_CONST false
#7 LET
#7 IN
#7 CASE
#7 OF
#7 ESAC
*)

<INITIAL> \"                 {BEGIN(STRING);
                   memset(str,0,MAX_STR_CONST);
                   index = 0;}
<STRING> \"          {   BEGIN(INITIAL);
                        cool_yylval.symbol = strtable.add_string(str);
                        return STR_CONST;}

<BLOCK_COMMENT> 0         {
                     strcpy(cool_yylval.error_msg,"EOF in comment");
                     return ERROR;}

/* STRING
 *
 */

<STRING>\0             {
                       strcpy(cool_yylval.error_msg,"String contains null character");
                       return ERROR;}
<STRING> 0              {
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



