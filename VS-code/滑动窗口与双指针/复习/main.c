#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>   // 包含 malloc、free 等函数的声明

#define MAX(a,b) ((a)>(b)?(a):(b))

//最小偶倍数
int smallestEvenMultiple(int n) 
{
	if (n % 2 == 0)
	{
		return n;
	}
	else
	{
		return n * 2;
	}
}

//数组异或操作
int xorOperation(int n, int start) 
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int num = start + 2 * i;
		result ^= num;

	}
	return result;
}

//转换成小写字母
char* toLowerCase(char* s) 
{
	int nums = (int)strlen(s);
	for (int i = 0; i < nums; i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			s[i] = s[i] + 32;
		}
	}
	return s;
}

//各位相加
int addDigits(int num)
{

	while (num >= 10)
	{
		int sum = 0;
		while (num > 0)
		{
			sum += num % 10;
			num = num / 10;
		}
		num = sum;
	}
	return num;
}

//int addDigits(int num)
//{
//	return num == 0 ? 0 : ((num - 1) % 9 + 1);
//}

//2的幂
bool isPowerOfTwo(int n)
{
	if (n <= 0) return false;
	while (n % 2 == 0)
	{
		n = n / 2;
	}
	return n == 1;
}
//bool isPowerOfTwo(int n)
//{
//	return n > 0 && (n & (n - 1)) == 0;
//}

//丑数
bool isUgly(int n)
{
	if (n <= 0) return false;
	while (n % 3 == 0)
	{
		n /= 3;
	}
	while (n % 5 == 0)
	{
		n /= 5;
	}
	return (n & (n - 1)) == 0;
}

//重新排列数组
int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{
	int* ans = (int*)malloc(sizeof(int) * numsSize);

	for (int i = 0; i < n; i++)
	{
		ans[2 * i] = nums[i];
		ans[2 * i + 1] = nums[i + n];

	}
	*returnSize = n * 2;
	return ans;
}

int maxScore(char* s)
{
	int len = (int)strlen(s);
	int ans = 0;
	int score = 0;
	if (s[0] == '0')
	{
		score++;
	}
	for (int i = 1; i < len; i++)
	{
		if (s[i] == '1')
		{
			score++;
		}
	}
	ans = score;
	for (int i = 1; i < len - 1; i++)
	{
		if (s[i] == '0')
		{
			score++;
		}
		else
		{
			score--;
		}
		ans = MAX(ans, score);
	}
	return ans;
}

int main()
{

	return 0;
}
