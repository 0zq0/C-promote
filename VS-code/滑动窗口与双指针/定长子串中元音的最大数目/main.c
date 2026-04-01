#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b))?(a):(b)

int maxVowels(char* s, int k)
{
	int len = (int) strlen(s);
	int vowel = 0;
	int ans = 0;
	for (int i = 0; i < len; i++)//for(int i=0;s[i];i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			vowel++;
		}
		int left = i - k + 1;
		if (left < 0)
		{
			continue;
		}
		ans = MAX(ans, vowel);
		char out = s[left];
		if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u')
		{
			vowel--;
		}
	}
	return ans;
}

int isVowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int Max_Vowels(char* s, int k)
{
	int len = (int) strlen(s);
	int current_count = 0;
	int max_count = 0;
	if (k > len)
	{
		return 0;
	}
	for (int i = 0; i < k; i++)
	{
		if (isVowel(s[i]))
			current_count++;
	}
	max_count = MAX(max_count, current_count);
	for (int i = k; i < s[i]; i++)
	{
		if (isVowel(s[i]))
		{
			current_count++;
		}
		else
		{
			current_count--;
		}

	}
	max_count = MAX(max_count, current_count);
	return max_count;

}

int main()
{
	char arr[] = "abciiidef";
	char* s = "leetcode";
	int k = 0;
	scanf_s("%d", &k);
	int ret1 = 0;
	int ret2 = 0;
	ret1 = Max_Vowels(arr, k);
	ret2 = Max_Vowels(s, k);
	printf("数组arr中的元音最大数目是：%d\n", ret1);
	printf("字符串s中的元音最大数目是：%d\n", ret2);

	return 0;

}

