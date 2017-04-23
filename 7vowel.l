%{
        #include<stdio.h>
        int vowel=0;
        int cons=0;
%}

%%
"a"|"e"|"i"|"o"|"u"|"A"|"E"|"I"|"O"|"U" {printf("%s vowel\n",yytext);vowel++;}
[a-zA-Z] {printf("%s consonant\n",yytext);cons++;}
[\n] { return 0;}
%%
int yywrap()
{
        return 1;
}

int main()
{
        printf("Enter a string\n");
        yylex();
        printf("\nvowel=%d and consonant=%d\n",vowel,cons);
        return 0;
}

