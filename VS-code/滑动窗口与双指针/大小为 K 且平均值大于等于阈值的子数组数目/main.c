#include<stdio.h>
#include<string.h>

#define MAX(a,b) ((a)>(b))?(a):(b)


int numOfSubarrays(int* arr, int arrSize, int k, int threshold)
{
	int current_sum = 0;
	int pow = 0;
	int limit = threshold * k;
	for (int i = 0; i < k; i++)
	{
		current_sum += arr[i];
	}
	if (current_sum >= limit)
	{
		pow++;
	}
	for (int i = k; i < arrSize; i++)
	{
		current_sum = current_sum + arr[i] - arr[i - k];
		if (current_sum >= limit)
		{
			pow++;
		}
	}
	return pow;
}

int numSubarrays(int* arr, int arrSize, int k, int threshold)
{
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum += arr[i];
		if (i < k - 1)
		{
			continue;
		}
		if (sum >= threshold * 3)
		{
			ans++;
		}
		sum -= arr[i - k + 1];
	}
	return ans;
}



int main()
{
	int arr[] = { 11,13,17,23,29,31,7,5,2,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = 0;
	int threshold = 0;
	scanf_s("%d %d", &k, &threshold);
	int ret = numOfSubarrays(arr, len, k, threshold);
	int ret1 = numSubarrays(arr, len, k, threshold);
	printf("ret1=%d\n", ret1);

	printf("ret=%d\n", ret);
	return 0;
}
