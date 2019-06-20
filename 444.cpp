#include "stdio.h"
#include "stdlib.h"
#include "string.h"
main()
{
	int i=0,j,k,count=0,numb=0;
	printf("ÇëÊäÈëÊı×Ö£º");
	scanf("%d",&numb);
	for(i = 0 ; i <= numb ;i ++)
	{
		int n[10][10];
		count=0;

		for(j = i+1 ; j < numb ; j ++)
		{
			n[i][j] = j;
			count += j ;
			if(count == numb)
			{
				for(k = i;k <= j;k++)
					printf("%d",n[i][k]);
				break;
			}
			else if(count > numb)
				break;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}