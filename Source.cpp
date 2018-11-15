#include<stdio.h> 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int min(int x, int y, int z)
{
	return min(min(x, y), z);
}

int Edit_Distance(string str1, string str2, int m, int n, int count)
{
	count++;
	if (m == 0) return n;
	if (n == 0) return m;

	if (str1[m - 1] == str2[n - 1])
		return Edit_Distance(str1, str2, m - 1, n - 1, count);

	return 1 + min(Edit_Distance(str1, str2, m, n - 1, count),
		Edit_Distance(str1, str2, m - 1, n, count),
		Edit_Distance(str1, str2, m - 1, n - 1, count)
	);
}
