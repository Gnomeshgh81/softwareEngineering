#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[]) {
	FILE* fp;
	int c = fopen_s(&fp, argv[argc - 1],"r");
	if (fp == NULL) {
		printf("文件不存在");
	}
	else {

		if (argv[argc - 2][1] == 'w') {
			int c;
			int pro = 0;
			int count = 0;
			while ((c = fgetc(fp)) != EOF) {
				if (c == ' '||c==',') {
					if (pro != ' ' && pro != ',') {
						count++;
					}
				}
				pro = c;
			}
			printf("一共有%d个单词", count + 1);
		}
		else if (argv[argc - 2][1] == 'c') {
			int c;
			int count = 0;
			while ((c = fgetc(fp)) != EOF) {
				count++;
			}
			printf("文本中共有%d个字符", count);
		}
		else {
			printf("命令错误！\n");
		}
	}
}