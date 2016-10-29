/*
2016-17ѧ�� �ﶬѧ�� ���ݽṹ���� ������ʦ
��Ŀ1  ��������
��С�黥���ļ���ɾ������13�� ë˳�� ���� ��� ��Ʒ 
We declare that all the work done in this project is of our independent effort as a group. 
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

double pow1_1(double X,unsigned N);   /* ����������������algorithm 1��algorithm 2�ĵݹ���ѭ���� */
double pow2_1(double X,unsigned N);
double pow2_2(double X,unsigned N);

int main()                     /* �����������Ժ��� */
{
	double X=1.001;
	int N=1000;           /* ����ֵX��N��ѭ������K��������Ԥ�ȳ�ʼ���� */ 
	long long K=10000000;    /* ���ǵ�32λ��64λ�����Ĳ������long long */ 
	clock_t start,stop;        /* ����ticks */
	double duration;           /* ������ʱ */
	double r1=0,r2=0,r3=0;/* ������ */
	int i;                     /* ѭ��ʱ�ĸ�������*/

	printf("������X��N��K \n");scanf("%lf%d%ld",&X,&N,&K);
	
	r1=pow1_1(X,N);
	r2=pow2_1(X,N);
	r3=pow2_2(X,N); 
	printf("���������%lf %lf %lf \n",r1,r2,r3);  /* �������Ƿ���ȷ */
	
	/* pow1_1����ʱ�� */
	start = clock();      /* ��ʱ��ʼ */ 
	for(i=1;i<=K;i++){    /* ѭ���ظ�K�� */
		pow1_1(X,N);
	}	
	stop = clock();	
	duration = ((double)(stop - start))/CLK_TCK; 
    printf("pow1_1��ticks=%d, duration=%lf \n",stop - start,duration) ;
    
    /* pow2_1����ʱ�� */
    start = clock(); 
	for(i=1;i<=K;i++){
	pow2_1(X,N); 
	}	
	stop = clock();	
	duration = ((double)(stop - start))/CLK_TCK; 
    printf("pow2_1��ticks=%d, duration=%lf \n",stop - start,duration) ;

    /* pow2_2����ʱ�� */
    start = clock(); 
	for(i=1;i<=K;i++){
	pow2_2(X,N); 
	}	
	stop = clock();	
	duration = ((double)(stop - start))/CLK_TCK; 
    printf("pow2_2��ticks=%d, duration=%lf \n",stop - start,duration) ;
    
    system("pause") ;
return 1;

}



/*��һ����ѭ������۴γ�*/
double pow1_1(double X,unsigned N) 
{  
	int n;               /*Ϊ��ֹ�ں������ƻ�N������ĸ�������*/ 
	double result=1;  /*����������ʼ��Ϊ1 ����N=0 ��ֱ�ӻ᷵��*/ 
	for(n=N;n>=1;n--){
		result= X*result;
	}
    return result;
}





/*�ڶ����ǵݹ��ġ��۰뷨�����ݣ��㷨���̲ĵ�2.4.4��*/
double pow2_1(double X,unsigned N)
{
	if(N==0)return 1;   /*�ݹ���� */
	if(N%2==0)return pow2_1(X*X,N/2);   /*�����ż��������X^(N/2)*X^(N/2) */
	else return (X*pow2_1(X*X,N/2));    /*���������������X^(N/2)*X^(N/2)*X */
}




 
/*��������ѭ����ġ��۰뷨�����ݣ��㷨˼�������Ŀ�ĵ� */ 
 double pow2_2(double X,unsigned N)
{
	double result=1;   /*���ս������ʼ��Ϊ1 */
	short int l[32]={0}; 
	 /*�����㷨˼�룬��������⣬������ò���һЩ�ռ����ָ��n�ı仯���̣���Ҫ����ż�Ա仯��
	 ��������N�����ֵ���ᳬ��(2^32 -1),�����������ȡ32 */
	int n,d;              /*����������dΪ����l[]���α� */
	d=0;
	
	for(n=N;n>=1;n=n/2){    /*���������������У�ÿһ���м�ָ������ż�ԣ�����¼�������� */
		l[d]=2+n%2;         /*�����ż������l[d]=2���������������l[d]=3*/
		d++;
	}
	
	/*����������l[d]�еļ�¼��ʼ�������result��d�����ʼ������Ϊ��һ���õ���dֵ��Ϊ���ֵ��
	�պþ�������Ҫ�� */
	for(;d>=0;d--){
		if (l[d]==3) result=result*result*X;   /*����ָ������ż��ѡ��ͬ�Ĺ�ʽ */
		else if (l[d]==2) result=result*result;
	
	}
	/*printf("%ld\n",result); /*���ڼ�����*/
	return result;
}
