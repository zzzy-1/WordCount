// wc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int *getCharNum(char *filename, int *totalNum)
{
	FILE *fp;
	char buffer[1003];
	int bufferLen;
	int i;
	char c;
	int isLastBlank = 0;
	int charNum = 0;
	int wordNum = 0;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror(filename);
		return NULL;
	}
	printf("line words chars\n");
	while (fgets(buffer, 1003, fp) != NULL)
	{
		bufferLen = strlen(buffer);
		for (i = 0; i < bufferLen; i++)
		{
			c = buffer[i];
			if (c == ' ' || c == '\t')
			{
				!isLastBlank && wordNum++ &&charNum++;
				isLastBlank = 1;
			}
			else if (c != '\n' && c != '\r')
			{
				charNum++;
				isLastBlank = 0;
			}
		}
		!isLastBlank && wordNum++;
		isLastBlank = 1;
		totalNum[0]++;
		totalNum[1] += charNum;
		totalNum[2] += wordNum;
		printf("%-7d%-7d%d\n", totalNum[0], wordNum, charNum);
		charNum = 0; wordNum = 0;
	}
	return totalNum;
}

int main()
{
	char filename[30];
	int totalNum[3] = { 0,0,0 };
	printf("Input file name: ");
	scanf("%s", filename);
	if (getCharNum(filename, totalNum))
	{
		printf("Total: %d line,%d words,%d chars\n", totalNum[0], totalNum[2], totalNum[1]);
	}
	else
	{
		printf("Error!\n");
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
