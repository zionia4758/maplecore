 #include <stdio.h>
#include <stdlib.h>
#include <Math.h>

typedef struct core
{
	int num;
	int value;
	int main_core;
	int core2;
	int core3;
}Core;

static char core_name[14][14]={"Anything"};

void main()
{
	Core core[200];
	int num=0;

	int valid_core;
	int sum_value;
	int i,j;
	int opti_core;
	int core1,core2,core3;
	printf("��ȿ �ھ� ���� ����(2�̻�) : ");
	scanf("%d",&valid_core);
	fflush(stdin);
	sum_value=pow(3,valid_core)-1;
	opti_core=(2*valid_core+2)/3;
	
	printf("��ȿ �ھ� ���� : %d\n���� �ھ� ���� : %d\n",valid_core,opti_core);
	
	for(i=0;i<valid_core;++i)
	{
		printf("%d�� �ھ��̸�(7������,����x) : ",i+1);
		scanf("%s",core_name[i+1]);
		fflush(stdin);
	}
	printf("�ھ�Ȯ��\n"); 
	for(i=1;i<=valid_core;i++)
	{
		printf("%d�� : %-14s    ",i,core_name[i]); 
		if(i%5==4)
			printf("\n");
	}
	printf("\n\n");
	printf("-----------------------------\n�ھ��Է� ����\nn��° �ھ� : 5 3 6\n�� ���� -1�����Ͻ� �Է� ����\n�ִ� 200���Է°���\n0�� ����ȿ�ھ�\n---------------------------\n"); 
	
	i=1;
	while(i<200)
	{
		re_input:
		printf("%d��° �ھ� : ",i);
		fflush(stdin);
		scanf("%d %d %d",&core1,&core2,&core3);
		fflush(stdin);
		if(core1<=-1)
		{
			printf("�Է� ����. �� %d�� �ھ�\n",i-1);
			break;
		}
		
		if((core1==core2)||(core2==core3)||(core3==core1))
		{
			printf("�ٽ� �Է��ϼ���(�ߺ�)\n");
			continue; 
		}
		
		if(core1<0|| core2<0 || core3<0 ||core1>valid_core || core2>valid_core|| core3>valid_core)
		{
			printf("�ٽ� �Է��ϼ���(�����ʰ�)\n");
			continue;
		}
		
	
		core[i].main_core=core1;
		core[i].core2=core2;
		core[i].core3=core3;
		core[i].num=1;
		core[i].value=pow(3,core1-1)+pow(3,core2-1)+pow(3,core3-1);
		printf("value=%d\n",core[i].value); 
		
		//�ߺ��˻�
		for(j=1 ;j<i;++j)
		{
			if(core[j].value==core[i].value &&core[j].main_core==core[i].main_core)
			{
				printf("�ߺ��Ǵ� �ھ��Դϴ�. �Է½� ��������� �ߺ��� �� �ֽ��ϴ�. �����Ͻðڽ��ϱ�? (yes : '1'�Է�)\n");
				fflush(stdin);
				if(getchar()=='1')
				{
					goto re_input;
				}
				else
					break;
			}
		}
		
		
		i++;
	};

 	printf("��� ����\n"); 
	Comb_core(1,core,opti_core,i-1,1,0,sum_value);



	
}

int Comb_core(int degree,Core core[],int opti_core,int max,int start,int result,int sum_value)
{
	
	if(degree==opti_core)
	{
		for(;start<=max;++start)
		{
			printf("�����ܰ� i=%d\nresult=%d\n",start,result+core[start].value);
			if(result+core[start].value== sum_value)
			{
				printf("%-16s %-16s %-16s\n",core_name[core[start].main_core],core_name[core[start].core2],core_name[core[start].core3]);
	
				return 1;
			}
		}
		return 0;
	}
	
	if(degree<opti_core)
	{
		for(;start<=max-opti_core+degree;++start)
		{
			result+=core[start].value;
			if(Comb_core(degree+1,core,opti_core,max,start+1,result,sum_value)==1)
			{
				printf("%-16s %-16s %-16s\n",core_name[core[start].main_core],core_name[core[start].core2],core_name[core[start].core3]);
				return 1;
			}
			else 
				result-=core[start].value;
		}
	}
	
}














