#include <stdio.h>
#include <string.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int lengthOfLongestSubstring(char* s)
{
	int ans = 0;
	int left = 0;
	int cnt[128] = {0};
	
	for (int right = 0; s[right]; right++)
	{
		char c = s[right];
		cnt[c]++;
		while (cnt[c] > 1)
		{
			cnt[s[left]]--;
			left++;
		}
		ans = MAX(ans,right-left+1);

	}
	return ans;

}

int lengthLongestSubstring(char* s)
{
	int last_pos[128];
	memset(last_pos, -1, sizeof(last_pos));
	int max_len = 0;
	int left = 0;
	int len = strlen(s);
	for (int right = 0; right < len; right++)
	{
		unsigned char c = s[right];
		if (last_pos[c] >= left)
		{
			left = last_pos[c] + 1;
		}
		last_pos[c] = right;
		int current_len = right - left + 1;
		if (current_len > max_len)
		{
			max_len = current_len;
		}
	}
	return max_len;
}

int main()
{
	char s1[] = "abcbcabb";
	char s2[] = "bbbbb";
	char s3[] = "pwwkew";

	printf("s1: %s, 最长无重复子串长度: %d\n", s1, lengthOfLongestSubstring(s1));
	printf("s2: %s, 最长无重复子串长度: %d\n", s2, lengthOfLongestSubstring(s2));
	printf("s3: %s, 最长无重复子串长度: %d\n", s3, lengthOfLongestSubstring(s3));
	printf("\n-----------------------------------------\n");
	printf("s1: %s, 最长无重复子串长度: %d\n", s1, lengthLongestSubstring(s1));
	printf("s2: %s, 最长无重复子串长度: %d\n", s2, lengthLongestSubstring(s2));
	printf("s3: %s, 最长无重复子串长度: %d\n", s3, lengthLongestSubstring(s3));
	return 0;
}