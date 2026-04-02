#include<stdio.h>
#include<string.h>

#define MAX(a,b) ((a)>(b))?(a):(b)

double findMaxAverage(int* nums, int numsSize, int k)
{
	int current_sum = 0;
	int max_sum = 0;
	if (k > numsSize||nums == NULL)
	{
		return 0;
	}
	for (int i = 0; i < k; i++)
	{
		current_sum += nums[i];
	}
	max_sum = MAX(max_sum, current_sum);
	for (int i = k; i < numsSize; i++)
	{
		current_sum = current_sum - nums[i - k ] + nums[i];
		max_sum = MAX(max_sum, current_sum);
	}
	return (double)max_sum / k;
}

double findOfMaxAverage(int* nums, int numsSize, int k)
{
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum = sum + nums[i];
		if (i < k - 1)
		{
			continue;
		}
		ans = MAX(ans, sum);
		int out = i - k + 1;
		sum -= nums[out];
	}
	return (double) ans / k;
}
int main()
{
	int arr[] = { 1,12,-5,-6,50,3 };
	int arr1[] = { 1 };
	int k = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	scanf_s("%d", &k);
	double ret = findMaxAverage(arr, len, k);
	double ret1 = findOfMaxAverage(arr, len, k);
	printf("ret1=%f\n", ret1);

	printf("ret=%f\n", ret);
	return 0;
}
