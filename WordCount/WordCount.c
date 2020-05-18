#include <stdio.h>
#include <stdlib.h>

//统计txt文件中的字符数
void charcount(char filtxt1[100])
{
    int count1 = 0;//字符计数变量
    FILE* pc = fopen(filtxt1, "r");//打开txt文件
    if (pc == NULL)//如果文件打开失败或者文件不存在，程序异常退出
    {
        printf("error on open file!");
        exit(1);
    }
    while (getc(pc) != EOF)//遍历文档中的字符并用count1计数
    {
        count1++;
    }
    printf("字符数：%d", count1);
    fclose(pc);//关闭txt文件
}
//统计txt文件中的单词数
void wordcount(char filtxt2[100])
{
    int count2 = 0;//单词计数变量
    char ch;
    FILE* pw = fopen(filtxt2, "r");//打开txt文件
    if (pw == NULL)//如果文件打开失败或者文件不存在，程序异常退出
    {
        printf("error on open file!");
        exit(1);
    }
    //遍历文件中的所有字符用count2计数文件中的' '、'\n'、'\t'、 ','字符数
    while ((ch = getc(pw)) != EOF)
    {
        if (ch == ' ' || ch == ',')
            count2++;
    }
    //由于单词由' '、'\n'、'\t'、 ','字符隔开，故单词数为count2+1
    printf("单词数：%d", ++count2);
    fclose(pw);//关闭txt文件
}
//制作控制参数“-c”（统计字符数）和“-w”（统计单词数）
void Operator(char jud[3], char filtxt[100])
{
    //当输入-c时调用charcount函数计数字符
    if (jud[0] == '-' && jud[1] == 'c')
    {
        charcount(filtxt);
    }
    //当输入-w时调用wordcount函数计数单词
    else if (jud[0] == '-' && jud[1] == 'w')
    {
        wordcount(filtxt);
    }
    else
    {
        printf(" error on input operator or file format!");
        exit(1);
    }
}
int main()
{
    char jud[3], filtxt[100];
    scanf("%s", jud);
    scanf("%s", filtxt);
    Operator(jud, filtxt);
    return 0;
}
