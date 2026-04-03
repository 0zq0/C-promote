#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int* getAverages(int* nums, int numsSize, int k, int* returnSize)
{
	*returnSize = numsSize;
	int* avgs = malloc(numsSize * sizeof(int));
	if (avgs == NULL)
	{
		return NULL;
	}
	memset(avgs, -1, numsSize * sizeof(int));
	long long s = 0;
	for (int i = 0; i < numsSize; i++)
	{
		s += nums[i];
		
		if (i < 2 * k)
		{
			continue;
		}
		avgs[i - k] = (int) s / (2 * k + 1);
		s = s - nums[i - 2 * k];
	}
	return avgs;
}

int* getofAverages(int* nums, int numsSize, int k, int* returnSize)
{
	*returnSize = numsSize;
	int *avgs = malloc(numsSize * sizeof(int));
	if (avgs == NULL)
	{
		return NULL;
	}
	memset(avgs, -1, numsSize * sizeof(int));
	long long s = 0;
	int WindowSize = 2 * k + 1;
	if (numsSize < WindowSize)
	{
		return avgs;
	}
	for (int i = 0; i < WindowSize; i++)
	{
		s += nums[i];
	}
	avgs[k] = (int)s / WindowSize;
	for (int i = WindowSize; i < numsSize; i++)
	{
		s = s + nums[i] - nums[i - WindowSize];
		avgs[i-k] = (int)s / WindowSize;
	}
	return avgs;
}


int main()
{
	int nums[] = { 7,4,3,9,1,8,5,2,6 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = 0;
	scanf_s("%d", &k);
	int returnSize=0;
	int returnSize1=0;

	int *ret = getAverages(nums, numsSize, k, &returnSize);
	int* ret1 = getofAverages(nums, numsSize, k, &returnSize1);

	printf("数组ret：");
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", ret[i]);
	}
	printf("\n数组ret1：");
	for (int i = 0; i < returnSize1; i++)
	{
		printf("%d ", ret1[i]);
	}
	return 0;
}
