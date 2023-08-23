#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char inp[10],stk[10]={'\0'},ch='E',p1[]={'E','+','E'},p2[]={'E','*','E'},temp[10];
int ip=0,sp=1,f1=0,f2=0;
 int main()
{
stk[0]='$';
int l,i,j,k;
printf("\n\t\t SHIFT REDUCE PARSER\n"); printf("\n GRAMMER\n");
printf("\n E->E+E"); 
printf("\n E->E*E \n E->i ");
printf("\n enter the input symbol:\t"); 
gets(inp);
l=strlen(inp);
inp[l]='$';
printf("\n%s\t\t%s\t\tshift",stk,inp);
//printf("%d",l);
for(i=0;i<l;i++){
    if(inp[i]=='i'){
        stk[sp]=ch;
        sp++;
    	inp[i]=' ';
    	printf("\n%s\t\t%s\t\tShift",stk,inp);	printf("\n%s\t\t%s\t\tReduce",stk,inp);
	}
	else{

		stk[sp]=inp[i];
		sp++;
		inp[i]=' ';
	   printf("\n%s\t\t%s\t\tShift",stk,inp);
	}
    while((stk[sp-2]=='+')||(stk[sp-2]=='*')){
    	stk[sp-1] ='\0';
    	stk[sp-2] ='\0';
    	sp=sp-2;
    	printf("\n%s\t\t%s\t\treduce",stk,inp);
	}	
}
if(strlen(stk)==2){
	if(stk[1]==ch)
	printf("\nthe string is accepted");
}
else{
	printf("\nthe string is not accepted");
}
}
 
