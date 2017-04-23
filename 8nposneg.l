%{
#include<stdio.h>

int pos_int_count=0;
int neg_int_count=0;
int pos_float_count=0;
int neg_float_count=0;

%}

%%
[+]?[0-9]+ {/*printf("+ve Integer");*/pos_int_count++;}
[-][0-9]+ {/*printf("-ve Integer");*/neg_int_count++;}
[+]?[0-9]+[.][0-9]+ {/*printf("+ve Float");*/pos_float_count++;}
[-][0-9]+[.][0-9]+ {/*printf("-ve Float");*/neg_float_count++;}
%%

void main(int argc,char *argv[])
{
        //printf("Enter any Number: ");
        yyin=fopen(argv[1],"r");
        yylex();
        printf("No of +ve integers: %d\n",pos_int_count);
        printf("No of -ve integers: %d\n",neg_int_count);
        printf("No of +ve float: %d\n",pos_float_count);
        printf("No of -ve float: %d\n",neg_float_count);
}

