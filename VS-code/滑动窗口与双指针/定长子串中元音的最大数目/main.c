#include<stdio.h>

#define Max(a,b) ((a)>(b))?(a):(b)

int maxVowels(char* s, int k)
{
    int ans = 0;
    int vowel = 0;
    for (int i = 0; s[i]; i++)
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
        ans = Max(ans, vowel);
        char out = s[left];
        if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u')
        {
            vowel--;
        }
    }
    return ans;
}

int main()
{
    printf("hello\n");
    return 0;
}
