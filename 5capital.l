%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void display(char *);
%}
letter [a-z]
letter2 [A-Z]

%%

{letter} { display1(yytext);}
{letter2} {display2(yytext);}
[^/n] {printf("");}

%%
int main()
{
 yylex();
}
 void display1(char *s)
{
 int i;
 for(i=0;s[i]!='\0';i++)
 printf("%c", toupper(s[i]));
}
void display2(char *s)
{
 int i;
 for(i=0;s[i]!='\0';i++)
 printf("%c", tolower(s[i]));
}

int yywrap()
{
return 1;
}

