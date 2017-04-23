%{
#include<stdio.h>

%}
Oct [+-]?[0][0-7]+
Hex [+-]?[0][xX][0-9a-fA-F]+
Dec  [+-]?[0-9]+
invalid [+|-]?[0]?[0-9a-zA-Z]+

%%
[0] printf("decimal");
{Hex} printf("this is a hexadecimal number");
{Oct} printf("this is an octal number");
{Dec} printf("this is decimal number");
[0-9]+[\+\-\*\/]* printf("this  invalid");
{invalid} printf("this is invalid");
%%
int main()
{
        printf("ENTER A NUMBER\n");
        yylex();
}
int yywrap()
{
return 1;
}

