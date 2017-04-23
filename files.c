#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp;
	char ch,s[100];char *c;int sum=0;
	int i=0,j,k=0,z=0,l,f=0,h,nl=0,nw=0;
	float real[100],sumf=0;
	char arr[100],farr[100],ex[10];int integer[100];
	fp=fopen("one.txt","r");
	
	strcpy(ex,"95.456r");
	
	while((ch=getc(fp))!=EOF)
	{
		s[i]=ch;
		i++;
	}
	for(j=0;j<=i;j++)
		printf("%c",s[j]);
	printf("no of charecters: %d\n",j);
	
	
for(j=0;j<=i;j++)
{
	if(s[j]=='.')
	{
		for(l=0;l<=k;l++)
			arr[l]=0;
		k=0;
		while(s[j+1]!='\n'&&s[j+1]!=' '&&s[j+1]!='\n')
                        j++;
		continue;
	}
	if(isdigit(s[j]) && (!isalpha(s[j-1])))     // for integers
	{

		arr[k]=s[j];
		k++;
			
		if(s[j+1]=='\n' ||s[j+1]==' ' || s[j+1]=='\0')
		{
			integer[z]=atoi(arr);
			z++;
			for(l=0;l<=k;l++)
			arr[l]=0;
			k=0;
			}
			
			}	
}

k=0;
for(j=0;j<=i;j++)		//for float
{
	if(isdigit(s[j]) || (s[j]=='.' &&(isdigit(s[j-1]) && isdigit(s[j+1]))))
	{
		farr[k]=s[j];
		k++;
	
		
			if(s[j+1]=='\n' ||s[j+1]==' ' || s[j+1]=='\0')
			{
				for(h=0;h<k;h++)
				{
				//	printf(" inside %f",real[f]);
					if(farr[h]=='.')
					{
					
					real[f]=atof(farr);
					f++;
					
					}
				}
			for(l=0;l<=k;l++)
					farr[l]=0;	
			k=0;
			}	
	}
}



for(j=0;j<i;j++)							//no of lines and words
	{
		if(s[j]=='\n'){nl++;}
		if(s[j]=='\n' || s[j]==' '){nw++;		}
	}
	printf("\nNo of lines:%d",nl);
	printf("\nNo of words:%d\n",nw-(nl+z+f));
for(j=0;j<z;j++)							//to print integers
{

printf("integer[%d] :%d \n",j,integer[j]);
}
printf("Total no of integers: %d\n",z);	

for(j=0;j<f;j++)							//to print float
{
	printf("float[%d] :%f \n",j,real[j]);
}
printf("\nTotal no of float values:%d\n",f);

for(i=0;i<z;i++)								//sum of integers
	sum=sum+integer[i];
printf("sum of integers:%d\n",sum);
for(i=0;i<f;i++)								//sum of floats
	sumf=sumf+real[i];
printf("sum of float:%.4f\n",sumf);

}
