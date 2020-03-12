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




static char core_name[14][14] = { "Anything" };
int Check_3core(int stack_core[], int valid_core)   //0=중복 1=허용 
{
	int swtch = 0;
	int i = 1;
	for (; i <= valid_core; ++i)
	{
		if (stack_core[i] == 3)
		{
			if (swtch == 1)
			{
				return 0;
			}
			else if (swtch == 0)
				swtch = 1;
		}
	}
	return 1;
}

int isAnswer(int stack_core[], int valid_core)
{
	int i = 1;
	for (; i <= valid_core; ++i)
	{
		if (stack_core[i] < 2)
			return 0;
	}
	return 1;
}



int Comb_core(int degree, Core core[], int valid_core, int max, int start)
{

	static int* stack_core = (int*)malloc(sizeof(int) * (valid_core + 1));
	static int opti_core = (2 * valid_core + 2) / 3;
	int core1, core2, core3;
	if (degree == 1)  //시잓택초기화

	{
		int i;
		for (i = 0; i <= valid_core; ++i)
		{
			stack_core[i] = 0;
		}
	}

	if (degree == opti_core) 		//최종단계 검사 
	{
		
		core1 = core[start].main_core;
		core2 = core[start].core2;
		core3 = core[start].core3;

		stack_core[core1]++;
		stack_core[core2]++;
		stack_core[core3]++;

		if (isAnswer(stack_core, valid_core) == 1)
		{
			printf("%-16s %-16s %-16s\n", core_name[core[start].main_core], core_name[core[start].core2], core_name[core[start].core3]);
			return 1;
		}
		else
		{
			stack_core[core1]--;
			stack_core[core2]--;
			stack_core[core3]--;

			return 0;
		}
	}




	for (; start <= max - opti_core + degree; ++start)
	{


		core1 = core[start].main_core;
		core2 = core[start].core2;
		core3 = core[start].core3;

		stack_core[core1]++;
		stack_core[core2]++;
		stack_core[core3]++;
		if (degree>1&&Check_3core(stack_core, valid_core)==0)  //3중 2개이상 제외  
		{
			stack_core[core1]--;
			stack_core[core2]--;
			stack_core[core3]--;
			return 0;
		}


		
		if (degree < opti_core)
		{
			
			if (Comb_core(degree + 1, core, valid_core, max, start + 1) == 1)
			{
				printf("%-16s %-16s %-16s\n", core_name[core[start].main_core], core_name[core[start].core2], core_name[core[start].core3]);
				

				if (degree == 1)
				{
					for (int i = 1; i <= valid_core; ++i)
					{
						if (stack_core[i] > 2)
							printf("\n%s를 3중첩한 최적 조합입니다.\n",core_name[i]);
					}
				}
				return 1;
			}
			else
			{
				stack_core[core1]--;
				stack_core[core2]--;
				stack_core[core3]--;

			}
		}
	}
	
}





void main()
{
	Core core[200];
	int num = 0;

	static int valid_core;
	int sum_value;
	int i, j;
	int opti_core;
	int core1, core2, core3;
	printf("유효 코어 종류 개수(2이상) : ");
	scanf_s("%d", &valid_core);
	fflush(stdin);
	sum_value = pow(3, valid_core) - 1;
	opti_core = (2 * valid_core + 2) / 3;

	printf("유효 코어 개수 : %d\n최적 코어 개수 : %d\n", valid_core, opti_core);

	for (i = 0; i < valid_core; ++i)
	{
		printf("%d번 코어이름(7자이하,띄어쓰기x) : ", i + 1);
		scanf_s("%s", core_name[i + 1]);
		fflush(stdin);
	}
	printf("코어확인\n");
	for (i = 1; i <= valid_core; i++)
	{
		printf("%d번 : %-14s    ", i, core_name[i]);
		if (i % 5 == 4)
			printf("\n");
	}
	printf("\n\n");
	printf("-----------------------------\n코어입력 예시\nn번째 코어 : 5 3 6\n맨 앞이 -1이하일시 입력 종료\n최대 200개입력가능\n0은 비유효코어\n---------------------------\n");

	i = 1;
	while (i < 200)
	{
	re_input:
		printf("%d번째 코어 : ", i);
		fflush(stdin);
		scanf_s("%d %d %d", &core1, &core2, &core3);
		fflush(stdin);
		if (core1 <= -1)
		{
			printf("입력 종료. 총 %d개 코어\n", i - 1);
			break;
		}

		if ((core1 == core2) || (core2 == core3) || (core3 == core1))
		{
			printf("다시 입력하세요(중복)\n");
			continue;
		}

		if (core1<0 || core2<0 || core3<0 || core1>valid_core || core2>valid_core || core3>valid_core)
		{
			printf("다시 입력하세요(범위초과)\n");
			continue;
		}


		core[i].main_core = core1;
		core[i].core2 = core2;
		core[i].core3 = core3;
		core[i].num = 1;
		core[i].value = pow(3, core1 - 1) + pow(3, core2 - 1) + pow(3, core3 - 1);
		//	printf("value=%d\n",core[i].value); 

			//중복검사
		for (j = 1; j < i; ++j)
		{
			if (core[j].value == core[i].value && core[j].main_core == core[i].main_core)
			{
				printf("중복되는 코어입니다. 입력시 결과값에서 중복될 수 있습니다. 제거하시겠습니까? (yes : '1'입력)\n");
				fflush(stdin);
				if (getchar() == '1')
				{
					goto re_input;
				}
				else
					break;
			}
		}


		i++;
	};

	printf("계산 시작\n");
	Comb_core(1, core, valid_core, i - 1, 1);

	fflush(stdin);

	getchar();
	getchar();

}






