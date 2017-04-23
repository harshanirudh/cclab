#include<stdio.h>
#include<ctype.h>
void first(char[],char );
void final(char[],char);
int nop;
char productionSet[10][10];
main()
{
        int i;
        char choice;
        char c;
        char result[20];
        printf("How many number of productions ? :");
        scanf(" %d",&nop);
        for(i=0;i<nop;i++)//read production string eg: E=E+T
        {
                printf("Enter productions Number %d : ",i+1);
                scanf(" %s",productionSet[i]);
        }
        do
        {
                printf("\n Find the FIRST of  :");
                scanf(" %c",&c);
                first(result,c); //Compute FIRST; Get Answer in 'result' array
                printf("\n first(%c)= { ",c);
                for(i=0;result[i]!='\0';i++)
                        printf(" %c ",result[i]);       //Display result
                printf("}\n");
                printf("press 'y' to continue : ");
                scanf(" %c",&choice);
        }
        while(choice=='y'||choice =='Y');
}
void first(char* Result,char c)
{
        int i,j,k;
        char subResult[20];
        int foundEpsilon;
        subResult[0]='\0';
        Result[0]='\0';
        if(!(isupper(c)))
        {
                final(Result,c);
                return ;
        }
        for(i=0;i<nop;i++)
        {
                if(productionSet[i][0]==c)
                {
                        if(productionSet[i][2]=='$') final(Result,'$');
                        else
                        {
                                j=2;
                                while(productionSet[i][j]!='\0')
                                {
                                        foundEpsilon=0;
                                        first(subResult,productionSet[i][j]);
                                        for(k=0;subResult[k]!='\0';k++)
                                                final(Result,subResult[k]);
                                        for(k=0;subResult[k]!='\0';k++)
                                                if(subResult[k]=='$')
                                                {
                                                        foundEpsilon=1;
                                                        break;
                                                }
                                        if(!foundEpsilon)
                                                break;
                                        j++;
                                }
                        }
                }
        }
        return ;
}
void final(char Result[],char val)
{
        int k;
        for(k=0 ;Result[k]!='\0';k++)
                if(Result[k]==val)
                        return;
        Result[k]=val;
        Result[k+1]='\0';
}

