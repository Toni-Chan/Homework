#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */

ElementType EvalPostfix( char *expr )
{
	double Res_Stack[400], dtemp=0, dot=0;
	int Opr_Stack[400], resp=0, oprp=0, minus=0, num=0;
	char *temp=expr;
	while (temp)
	{
		switch(*temp)
		{
			case '.':
			dot=0.1;
			break;
			
			case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9': case '0':
			num=1;
			if (dot!=0)
			{
				dtemp+=(*temp-48)*dot;
				dot*=0.1;
			}
			else
			{
				dtemp*=10;
				dtemp+=*temp-48;
			}
			break;
			
			case ' ':
			if (num==0) break;
			if (minus) dtemp=-dtemp;
			Res_Stack[++resp]=dtemp;
			minus=0;
			dtemp=0;
			dot=0;
			num=0;
			break;
			
			case '+': case '-':
			if (*(temp+1)!=' ' && *(temp+1)!=0 && *temp=='-') 
			{
				minus=1;
				break;
			}
			if (*temp=='+')
			Opr_Stack[++oprp]=3;
			if (*temp=='-')
			Opr_Stack[++oprp]=4;
			while (Opr_Stack[oprp]<=4 && oprp>=1 && resp>1)
			{
				if (Opr_Stack[oprp]==1)
					Res_Stack[resp-1]=Res_Stack[resp-1]*Res_Stack[resp];
				else if (Opr_Stack[oprp]==2)
				{
					if (Res_Stack[resp]==0) 
					return Infinity;
					Res_Stack[resp-1]=Res_Stack[resp-1]/Res_Stack[resp];
				}
				else if (Opr_Stack[oprp]==3)
					Res_Stack[resp-1]=Res_Stack[resp-1]+Res_Stack[resp];
				else if (Opr_Stack[oprp]==4)
					Res_Stack[resp-1]=Res_Stack[resp-1]-Res_Stack[resp];
				Res_Stack[resp]=0;
				Opr_Stack[oprp]=0;
				resp--;
				oprp--;
				if (oprp<0 || resp<1) return Infinity; 
			}
			break;
			
			case '*': case '/':
			if (*temp=='*')
			Opr_Stack[++oprp]=1;
			if (*temp=='/')
			Opr_Stack[++oprp]=2;
			while (Opr_Stack[oprp]<=2 && oprp>=1 && resp>1)
			{
				if (Opr_Stack[oprp]==1)
					Res_Stack[resp-1]=Res_Stack[resp-1]*Res_Stack[resp];
				else if (Opr_Stack[oprp]==2)
				{
					if (Res_Stack[resp]==0) 
					return Infinity;
					Res_Stack[resp-1]=Res_Stack[resp-1]/Res_Stack[resp];
				}
				Res_Stack[resp]=0;
				Opr_Stack[oprp]=0;
				resp--;
				oprp--;
				if (oprp<0 || resp<1) return Infinity; 
			}
			break;
			
			case 0:
			if (num!=0)
			{
				if (minus) dtemp=-dtemp;
				Res_Stack[++resp]=dtemp;
				minus=0;
				dtemp=0;
				dot=0;
				num=0;
			}
			while (Opr_Stack[oprp]<=4 && oprp>=1 && resp>1)
			{
				if (Opr_Stack[oprp]==1)
					Res_Stack[resp-1]=Res_Stack[resp-1]*Res_Stack[resp];
				else if (Opr_Stack[oprp]==2)
				{
					if (Res_Stack[resp]==0) 
					return Infinity;
					Res_Stack[resp-1]=Res_Stack[resp-1]/Res_Stack[resp];
				}
				else if (Opr_Stack[oprp]==3)
					Res_Stack[resp-1]=Res_Stack[resp-1]+Res_Stack[resp];
				else if (Opr_Stack[oprp]==4)
					Res_Stack[resp-1]=Res_Stack[resp-1]-Res_Stack[resp];
				Res_Stack[resp]=0;
				Opr_Stack[oprp]=0;
				resp--;
				oprp--;
				if (oprp<0 || resp<1) return Infinity; 
			} 
			if (resp!=1 || oprp!=0) return Infinity;
			return  Res_Stack[1];
			break;
			
			default:
			break;
		}
		temp++;
	}
	return Res_Stack[1];
}