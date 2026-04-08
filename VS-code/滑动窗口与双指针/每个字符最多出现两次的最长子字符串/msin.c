#include <string.h>
#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
int maximumLengthSubstring(char* s)
{
    int count[128] = { 0 };
    int max_len = 0;
    int left = 0;

    for (int right = 0; s[right]; right++)
    {
        char c = s[right];
        count[c]++;
        while (count[c] > 2)
        {
            count[s[left]]--;
            left++;
        }
        int current_len = right - left + 1;
        max_len = MAX(max_len, current_len);
    }
    return max_len;
}

int maximumOfLengthSubstring(char* s)
{
    int ans = 0;
    int left = 0;
    int cnt[128] = { 0 };
    int max_len = 0;
    for (int right = 0; s[right]; right++)
    {
        char c = s[right];
        cnt[c]++;
        while (cnt[c] > 2)
        {
            cnt[s[left]]--;
            left++;
        }
        int current_len = right - left + 1;
        max_len = MAX(max_len, current_len);
    }
    return max_len;

}
// 测试用例
int main() 
{
    char s1[] = "bcbbb cba";  // 示例1：输入"bcbbb cba"（去空格为"bcbbbcba"）
    char s2[] = "aaaa";       // 示例2：输入"aaaa"
    printf("示例1输出：%d\n", maximumLengthSubstring(s1));
    printf("示例2输出：%d\n", maximumLengthSubstring(s2));
    printf("\n-----------------------------------------\n");
    printf("示例1输出：%d\n", maximumOfLengthSubstring(s1));
    printf("示例2输出：%d\n", maximumOfLengthSubstring(s2));
    return 0;
}
