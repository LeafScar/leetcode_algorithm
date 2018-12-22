#include <cstdio>
#include <string>

using namespace std;

char temp[10001];
void del(char* str, int index, char letter);


int main()
{
#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char str[10001];
	scanf("%s\n", &str);
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
		del(str, index, letter);
	}

#ifndef _OJ_
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

void del(char* str, int index, char letter)
{
	// ��ǰ����letter��ͬ��
	int begin = index;
	while (str[begin] == letter && begin >= 0)
		begin--;

	int end = index;
	while (str[end] == letter)
		end++;

	if (end - begin - 1 > 2)
	{
		strcpy(temp, str + end);
		strcpy(str + begin + 1, temp);
	}
}