/*
 * test.c
 *
 *  Created on: 2019年9月19日
 *      Author: hxf
 */
#include <stdio.h>
#include <string.h>

static int Split(char *pSrc, const char *pSeparator, char **ppDest, int destCnt)
{
	if ((NULL == pSrc) || (strlen(pSrc) == 0)) 					//如果传入的地址为空或长度为0，直接终止
	{
		return 0;
	}

	if ((NULL == pSeparator) || (strlen(pSeparator) == 0))		//如未指定分割的字符串，直接终止
	{
		return 0;
	}

	int count = 0;
	char *pNext = NULL;

	pNext = (char *)strtok(pSrc, pSeparator);

	int i = 0;
	while (pNext != NULL)
	{
		count++;
		if (count > destCnt)		//如分割后的字符串个数大于接受子字符串的数组的大小，则直接弃用，返回0
		{
			return 0;
		}

		//ppDest[i] = pNext;
		//*ppDest = pNext;
		//ppDest++;
		printf("%p, %p, %p\n", ppDest, ppDest[i], *ppDest);
		//printf("%p %p\n", ppDest, (*ppDest));
		i++;
		pNext = (char *)strtok(NULL, pSeparator);
	}

	return count;
}

int main()
{
	char *pWatchInfo[2] = {NULL};
	char src[100] = "/etc/route:access";

	int cnt = Split(src, ":", pWatchInfo, sizeof(pWatchInfo)/sizeof(*pWatchInfo));

	int i = 0;
	printf("cnt:%d\n", cnt);
	for (i = 0; i < 2; i++)
	{
		printf("%s\n", pWatchInfo[i]);
	}

   return 0;
}

