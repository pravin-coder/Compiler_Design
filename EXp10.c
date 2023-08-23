#include<stdio.h>
#include<conio.h>
#include<string.h>
void print_icg();
void f_left(int );
void f_right(int );
char str[20],left[5],right[5],c,mat[10][10];
int i,j,tmpch=90,w=0;
struct exp{
int pos;
char op;
}k[15];
void search(char ch){
	for(i=0;str[i]!='\0';i++){
		if(str[i]==ch){
			k[j].pos=i;
			k[j].op=ch;
			j=j+1;
		}
	}
}
int main(){
	printf("enter the expression:");
	scanf("%s",str);
	search('/');
	search('*');
	search('+');
	search('-');
	print_icg();
	printf("\n\tQUADRAPLES");
	printf("\n#\t\tOP\t\tARG1\t\tARG2\t\tRESULT");
	for(i=0;i<(strlen(str)/2)-1;i++){
		printf("\n%d\t\t%c\t\t%c\t\t%c\t\t%c",i,mat[i][3],mat[i][2],mat[i][4],mat[i][0]);
	}
}

void print_icg(){
	for(i=0;i<(strlen(str)/2)-1;i++){
		f_left(k[i].pos);
		f_right(k[i].pos);
		str[k[i].pos]=tmpch--;
	//	printf("%s",str);
		printf("\n%c = %s %c %s",str[k[i].pos],left,k[i].op,right);
		mat[i][0]=str[k[i].pos];
		mat[i][1]='=';
		mat[i][2]=left[0];
		mat[i][3]=k[i].op;
		mat[i][4]=right[0];
	}
	for(i=2;i<strlen(str);i++){
		if(str[i]!='$'){
		   c=str[i];
		   break;
		}
	}
	printf("\n%c = %c",str[0],c);
}

void f_left(int ind){
	w=0;
	ind=ind-1;
	while((str[ind]!='/')&&(str[ind]!='*')&&(str[ind]!='+')&&(str[ind]!='-')&&(str[ind]!='=')&&(str[ind]!='\0')){
	 if(str[ind]!='$'){
		left[w]=str[ind];
		w++;
		left[w]='\0';
		str[ind]='$';
	    }
	    ind--;
    }
}

void f_right(int ind){
	w=0;
	ind++;
	while((str[ind]!='/')&&(str[ind]!='*')&&(str[ind]!='+')&&(str[ind]!='-')&&(str[ind]!='=')&&(str[ind]!='\0')){
	 if(str[ind]!='$'){
		right[w]=str[ind];
		w++;
		right[w]='\0';
		str[ind]='$';
	    }
	    ind++;
    }
}
