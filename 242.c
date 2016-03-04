/*************************************************************************
    > File Name: 242.c
    > Author: duqinglong
    > Mail: du_303412@163.com 
    > Created Time: Fri 04 Mar 2016 11:06:51 AM CST
 ************************************************************************/
/*
bool isAnagram(char* s, char* t) {
	int lengthS, lengthT;
	if (s == NULL && t == NULL)
		return true;
	else if ((s && !t) || (!s && t))
		return false;
	lengthS = strlen(s), lengthT = strlen(t);
	if (lengthS != lengthT)
		return false;
	sortString(s);
	sortString(t);
	while (*s && *t)
	{
		if (*s != *t)
			return false;
		*s++, *t++;
	}
	return true;
}

void sortString(char* s)
{
	int lengthS, i, j;
	char temp;
	lengthS = getLength(s);
	for (i = 0; i < lengthS; i++)
	{
		for (j = 0; j < lengthS - i - 1; j++)
		{
			if (s[j] > s[j+1])
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
}
*/

bool isAnagram(char* s, char* t)
{
	int a[256] = {};
	if (strlen(s) != strlen(t))
		return false;
	while (*s)
		a[*s++]++;
	while (*t)
	{
		if (a[*t] > 0)
			a[*t++]--;
		else
			return false;
	}
	return true;
}
