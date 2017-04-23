#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp;
	char ch,c;
	int i=0,j,flag=0,to=0;
	char s[100][100]={"do","double","else","enum","extern","float","for","goto","if",	"int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while","continue","break","case","char","const","default","auto"};
	char st[10];
	fp=fopen("f.txt","r");
	printf("Token no\t\tToken\t\tLexame \n");
	while((ch=getc(fp))!=EOF)
	{
		i=0;
		flag=0;
		if(ch>=42&&ch<=47)
		{
			to++;
			printf("%d\t\toperator\t\t%c\n",to,ch);
		}
		if((ch>=32&&ch<=41)||(ch>=91&&ch<=96)||(ch>=58&&ch<=63)||(ch>=123&&ch<=126))
		{
			to++;
			printf("%d\t\tspecial character\t\t%c\n",to,ch);
		}
		if(isdigit(ch))
		{
			to++;
			printf("%d\t\tdigit\t\t\t%c\n",to,ch);
		}
		if(isalpha(ch))
		{
			st[i]=ch;
			i++;
			ch=getc(fp);
			while(isalnum(ch)&&ch!=' ')
			{
				st[i]=ch;
				i++;
				ch=getc(fp);
			}
			st[i]='\0';
			for(j=0;j<32;j++)
			{
				if(strcmp(st,s[j])==0)
				{
					flag=1;
					break;
				}
			}
			to++;
			if(flag==1)
				printf("%d\t\tkeyword\t\t\t%s \n",to,st);
			else
				printf("%d\t\tidentifier\t\t%s\n",to,st);
			if(ch=='.')
			{
				i=0; int k=1;
				if(isalpha(c=getc(fp)))
				{
					st[i]=c;
					i++;
					c=getc(fp);
					while(isalnum(c)&&c!=' ')
					{
						st[i]=c;
						i++;
						k++;
						c=getc(fp);
					}
					st[i]='\0';
					to++;
					printf("%d\t\tExtension\t\t.%s\n",to,st);
					ch=c;
				}
				else
				{
					if(ch>=42&&ch<=47)
					{
						to++;
						printf("%\t\toperator\t\t%c\n",to,ch);
					}
					if((c>=32&&c<=41)||(c>=91&&c<=96)||(c>=58&&c<=63)||(c>=123&&c<=126))
					{
						to++;
						printf("%d\t\tspecial character\t\t%c\n",to,c);
					}
				}
			}	
			if((ch>=32&&ch<=41)||(ch>=91&&ch<=96)||(ch>=58&&ch<=63)||(ch>=123&&ch<=126))
			{
				to++;
				printf("%d\t\tspecial character\t\t%c\n",to,ch);
			}
		}
	}
}

