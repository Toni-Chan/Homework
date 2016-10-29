/*
2016-17学年 秋冬学期 数据结构基础 冯雁老师
项目1  正数的幂
（小组互评文件中删除）第13组 毛顺龙 陈潼 张岱 出品 
We declare that all the work done in this project is of our independent effort as a group. 
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

double pow1_1(double X,unsigned N);   /* 函数声明，依次是algorithm 1、algorithm 2的递归版和循环版 */
double pow2_1(double X,unsigned N);
double pow2_2(double X,unsigned N);

int main()                     /* 主函数、测试函数 */
{
	double X=1.001;
	int N=1000;           /* 测试值X、N与循环次数K，在这里预先初始化了 */ 
	long long K=10000000;    /* 考虑到32位与64位机器的差别，用了long long */ 
	clock_t start,stop;        /* 计算ticks */
	double duration;           /* 计算用时 */
	double r1=0,r2=0,r3=0;/* 检验结果 */
	int i;                     /* 循环时的辅助变量*/

	printf("请输入X、N和K \n");scanf("%lf%d%ld",&X,&N,&K);
	
	r1=pow1_1(X,N);
	r2=pow2_1(X,N);
	r3=pow2_2(X,N); 
	printf("结果依次是%lf %lf %lf \n",r1,r2,r3);  /* 检验结果是否正确 */
	
	/* pow1_1的用时： */
	start = clock();      /* 计时开始 */ 
	for(i=1;i<=K;i++){    /* 循环重复K次 */
		pow1_1(X,N);
	}	
	stop = clock();	
	duration = ((double)(stop - start))/CLK_TCK; 
    printf("pow1_1的ticks=%d, duration=%lf \n",stop - start,duration) ;
    
    /* pow2_1的用时： */
    start = clock(); 
	for(i=1;i<=K;i++){
	pow2_1(X,N); 
	}	
	stop = clock();	
	duration = ((double)(stop - start))/CLK_TCK; 
    printf("pow2_1的ticks=%d, duration=%lf \n",stop - start,duration) ;

    /* pow2_2的用时： */
    start = clock(); 
	for(i=1;i<=K;i++){
	pow2_2(X,N); 
	}	
	stop = clock();	
	duration = ((double)(stop - start))/CLK_TCK; 
    printf("pow2_2的ticks=%d, duration=%lf \n",stop - start,duration) ;
    
    system("pause") ;
return 1;

}



/*第一个是循环版的累次乘*/
double pow1_1(double X,unsigned N) 
{  
	int n;               /*为防止在函数中破坏N而引入的辅助变量*/ 
	double result=1;  /*储存结果，初始化为1 。若N=0 则直接会返回*/ 
	for(n=N;n>=1;n--){
		result= X*result;
	}
    return result;
}





/*第二个是递归版的“折半法”求幂，算法见教材的2.4.4节*/
double pow2_1(double X,unsigned N)
{
	if(N==0)return 1;   /*递归出口 */
	if(N%2==0)return pow2_1(X*X,N/2);   /*如果是偶数，计算X^(N/2)*X^(N/2) */
	else return (X*pow2_1(X*X,N/2));    /*如果是奇数，计算X^(N/2)*X^(N/2)*X */
}




 
/*第三个是循环版的“折半法”求幂，算法思想详见项目文档 */ 
 double pow2_2(double X,unsigned N)
{
	double result=1;   /*最终结果，初始化为1 */
	short int l[32]={0}; 
	 /*根据算法思想，需逆向求解，因而不得不花一些空间记忆指数n的变化过程（主要是奇偶性变化）
	 另外由于N的最大值不会超过(2^32 -1),所以数组个数取32 */
	int n,d;              /*辅助变量，d为数组l[]的游标 */
	d=0;
	
	for(n=N;n>=1;n=n/2){    /*计算逆向求解过程中，每一个中间指数的奇偶性，并记录在数组中 */
		l[d]=2+n%2;         /*如果是偶数，则l[d]=2；如果是奇数，则l[d]=3*/
		d++;
	}
	
	/*接下来根据l[d]中的记录开始正向计算result，d无需初始化，因为上一步得到的d值（为最大值）
	刚好就是所需要的 */
	for(;d>=0;d--){
		if (l[d]==3) result=result*result*X;   /*根据指数的奇偶性选择不同的公式 */
		else if (l[d]==2) result=result*result;
	
	}
	/*printf("%ld\n",result); /*用于检验结果*/
	return result;
}
