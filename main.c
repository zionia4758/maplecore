#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	static int core_num,final_num; //��ȿ�ھ��,��ǥ����  
	static int core_comb[200][3]; //�ھ�3�� ���չ迭  //0�� ���ھ�  
	static char core_name[15][14]={"Anything"};  //�ھ��̸����� 
int main(int argc, char *argv[]) {

	int open_core[200]={}; 
	 
	int i; 
	int j;
	int main_core,core1,core2;

	printf("��ȿ �ھ� ���� ����(4�̻�) : ");
	scanf("%d",&core_num);
	final_num=pow(3,core_num)-1;
	printf("%d",((core_num*2+2)/3)); 
	printf("��ȿ �ھ� ���� ���� : %d\n",core_num);


	for(i=0;i<core_num;++i)
	{
		printf("%d�� �ھ��̸�(7������) : ",i+1);
		scanf("%s",core_name[i+1]);
	}
	printf("�ھ�Ȯ��\n"); 
	for(j=1;j<=i;j++)
	{
		printf("%d�� : %-14s    ",j,core_name[j]); 
		if(j%5==4)
			printf("\n");
	}
	printf("\n\n");
	printf("-----------------------------\n�ھ��Է� ����\nn��° �ھ� : 5 3 6\n�� ���� -1�����Ͻ� �Է� ����\n�ִ� 200���Է°���\n0�� ����ȿ�ھ�\n---------------------------\n"); 
	
	i=1;
	do
	{	
		printf("%d��° �ھ� : ",i); 
		scanf("%d %d %d",&main_core,&core1,&core2);
	
		if(main_core<=-1)
		{
			printf("�Է� ����. �� %d�� �ھ�\n",i-1); 
			break;
		}	
	
		if((main_core==core1)||(main_core==core2)||(core1==core2))
		{
			printf("�ٽ��Է��ϼ���(�ߺ�)\n");
			continue;
		}
		                                                                //  �ھ��������� �����������ڸ�
		if(main_core<0||core1<0||core2<0||main_core>core_num||core1>core_num||core2>core_num)
		{
			printf("�ٽ� �Է��ϼ���(�����ʰ�)\n");
			continue;
		}
																																	 
		open_core[i]=pow(3,main_core-1)+pow(3,core1-1)+pow(3,core2-1);	
		core_comb[i][0]=main_core;
		core_comb[i][1]=core1;
		core_comb[i][2]=core2;
		printf("%d\n",open_core[i]);
		++i;
	}while(i<200);
	printf("��ǥ : %d\ncore_num=%d\n",final_num,core_num);	
	
	comb(1,open_core,i,1,0);
	
	getchar();
	getchar();
	return 0;
}

int comb(int degree,int core[],int max,int start,int result)
{
	if(degree==((2*core_num+2)/3))  //(2*core_num+2)/3 �ּ���ø���ھ��  
	{
		
		for(;start<max;++start)
		{
			//printf("�����ܰ赵�� degree=%d\n",degree); 
			if(result+core[start]==final_num)
			{
				printf("%-16s-%-16s-%-16s	\n",core_name[core_comb[start][0]],core_name[core_comb[start][1]],core_name[core_comb[start][2]]);
				return 1;
			}
		}
		 
		return 0;
	}
	
	else if(degree<((2*core_num+2)/3))
	{
		
		for(;start<=max-((2*core_num+2)/3)+degree;++start)
		{
			result+=core[start];
			if(comb(degree+1,core,max,start+1,result)==1)
			{

				printf("%-16s-%-16s-%-16s	\n",core_name[core_comb[start][0]],core_name[core_comb[start][1]],core_name[core_comb[start][2]]);
				return 1;
			}
			else
				result-=core[start];
			}
		}
				
	
	
	
}




