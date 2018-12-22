#include <cstdio>
#include <cstring>

using namespace std;

char temp[20001];
int del(char* str, int index);


int main()
{
#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char str[20001];
	scanf("%[^\n]", &str);
	//str[0] = '\0';
	int line = 0;
	scanf("%d\n", &line);

	//strcpy���ַ�������ɾȥ���������������µĿռ�
	int len = strlen(str);

	for (int i = 0; i < line; ++i)
	{
		int index;
		scanf("%d\n", &index);
		char letter;
		scanf("%c\n", &letter);

		// ����letter
		strcpy(temp, str + index);
		strcpy(str + index + 1, temp);
		str[index] = letter;

		// ѭ��ɾȥ
		while (true)
		{
			index = del(str, index);
			if (index < 0 || strlen(str) == 0)
				break;
		}

		if (strlen(str) != 0)
			printf("%s\n", str);
		else
			printf("-\n");
	}

#ifndef _OJ_
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

int del(char* str, int index)
{
	// ��ǰ����letter��ͬ��
	char letter = str[index];
	int begin = index;
	while (begin >= 0 && str[begin] == letter)
		begin--;

	int end = index;
	while (end < strlen(str) && str[end] == letter)
		end++;

	if (end - begin - 1 > 2)
	{
		strcpy(temp, str + end);
		strcpy(str + begin + 1, temp);
		return begin + 1;
	}
	return -1;
}