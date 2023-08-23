#include<stdio.h>
#include<conio.h>
int main()
{  int i=0,j=0,k=0,b=0,nop;
char pro[20][20],alpha[5],beta[5];
	printf("\nenter the number of productions: ");
	scanf("%d",&nop);
	for(i=0;i<nop;i++){
		printf("\nenter the production number %d :",i+1);
		scanf("%s",pro[i]);
	}
	for(i=0;i<nop;i++){
		k=0,b=0;
		if(pro[i][0]==pro[i][2]){
			for(j=3; pro[i][j]!='|' ;j++){
				alpha[k]=pro[i][j];
				k++;
			}
		//	printf("\nalpha=%s",alpha);
			for(k=j+1;pro[i][k]!='\0';k++){
				beta[b++]=pro[i][k];
			}
		//	printf("\nbeta =%s",beta);
		printf("\nthis production has left recursion:");
		printf("\n%c'=%s%c'/$",pro[i][0],alpha,pro[i][0]);
		printf("\n%c=%s%c'",pro[i][0],beta,pro[i][0]);
			
		}
	else{
			printf("\nthis production does not have left recursion:");
			printf("\n");
			for(j=0;pro[i][j]!='\0';j++)
			printf("%c",pro[i][j]);
		}
	}
}
