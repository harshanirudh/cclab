%{
        #include<stdio.h>
        int c=0,m=0;
%}
%%
[/][/]([a-zA-Z0-9]*|[\t]?)+[^\n]+  {c++;fprintf(yyout,"\n");}
[/][*]([a-zA-Z0-9 ]*|[\n]?|[\t]?)+[*][/] {m++;}
%%
int main()
{
        yyin = fopen("in.txt","r");
        yyout = fopen("commentoutput.c","w");
        yylex();
        printf("Number of single line comments %d\n",c);
        printf("Number of multiline coments %d\n",m);
}
int yywrap()
{
return 1;
}

