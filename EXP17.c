#include<stdio.h> 
#include<ctype.h>
#include<string.h>
char intercode[5][300]={{"100: if(a<b) goto(103)"},{"101: t=0"},{"102: goto(104)"},{"103: t=1"},{"104:  "}};
int main()
{ int a=0,b=0;
	printf("\nTHREE ADDRESS CODE: \n100: if(a<b) goto(103)\n101: t=0\n102: goto(104)\n103: t=1\n104:  ");
	printf("\n\nenter the value of A:");
	scanf("%d",&a);
	printf("\nenter the value of B:");
	scanf("%d",&b);
	printf("\n\n THE VALUE OF A: %d",a);
	printf("\n THE VALUE OF B: %d",b);
	if(a<=b){
		printf("\n\n%s",intercode[0]);
		printf("\n%s",intercode[3]);
		printf("\n%s",intercode[4]);
	}
	else {
		printf("\n\n%s",intercode[0]);
		printf("\n%s",intercode[1]);
		printf("\n%s",intercode[2]);
		printf("\n%s",intercode[4]);
	}
	
}
