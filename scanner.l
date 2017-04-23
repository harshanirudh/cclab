

%{
#include<stdio.h>
#include<string.h>
int t=1;
int l=1;
%}
key auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
file 	txt|h|c
preprocc include|define
%%
[#]{preprocc}			{printf("\n%d\tpre process directive\t%s",t,yytext);t++;}
[#$&^{}()"'] 			{printf("\n%d\tspecial char\t%s",t,yytext);t++;}
{key} 				{printf("\n%d\tkeyword\t\t%s",t,yytext);t++;}
[a-z]+"."{file} 		{printf("\n%d\tfile\t\t%s",t,yytext);t++;}
[a-z]+"."[a-z]+ 		{printf("\n%d\tidentifier\t%s",t,yytext);t++;}
"++" 				{printf("\n%d\tincrementer\t%s",t,yytext);t++;}
"--" 				{printf("\n%d\tdecrementer\t%s",t,yytext);t++;}
"/*"|"//" 			{printf("\n%d\tcomment begins\t%s",t,yytext);t++;}
"*/" 				{printf("\n%d\tcomment ends\t%s",t,yytext);t++;}
[=+-/%<>] 			{printf("\n%d\toperator\t%s",t,yytext);t++;}
"\\"[btvrfn?0a] 		{printf("\n%d\tescape char\t%s",t,yytext);t++;}
[+-]?[0-9]+ 			{printf("\n%d\tdigit\t\t%s",t,yytext);t++;}
[a-zA-Z][a-zA-Z0-9_]* 	{printf("\n%d\tidentifier\t%s",t,yytext);t++;}
[;] 				{printf("\n%d\tterminator\t%s",t,yytext);t++;}
[\n] 				{l++;}
%%

int main()
{
yyin=fopen("f.txt","r");
yylex();
}

