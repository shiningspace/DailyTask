#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

int task_len;//任务总个数

vector<string> all_thing;//所有任务
vector<int> all_score;//所有任务的分值

int read_int();//整数快读
void new_thing();//新建任务
void autosaving();//保存
void read_all_file();//读取变量

int main()
{
    ios::sync_with_stdio(false);

    read_all_file();

    int s;

    // printf("hello!\n1:new新建任务\n2:check已完成的任务\n3:all所有任务\n4:change更改数据(需要密码)\n//目前只支持数字命令\n");
    printf("hello!\n1:creat a new task\n2:check the finished tasks\n3:show out all the tasks\n4:change some data(need password)\n");
    printf("//only suppose number command now\n");

    cin >> s;

    switch (s)//判断命令
    {
        case 1://new新建任务
        {
            new_thing();
            // autosaving();
            break;
        }
        case 2:
        case 3:
        case 4:

        default:
        {
            // printf("抱歉,不前不支持此指令\n");
            printf("sorry,this command isn't supposed yet\n");
            break;
        }
    }
    system("pause");
}

int read_int()
{
    int num = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        num = num * 10 + c - '0';
        c = getchar();
    }
    return f * num;
}

void new_thing()
{
    ofstream open_file("all_things.txt",ios::app);

    if(open_file.fail())
    {
        printf("fail in opening the file\n");
        exit(0);
    }

    // printf("请输入任务名称:");
    printf("what's the name of this task:");

    string s;
    cin >> s;
    open_file << endl << "task " << task_len << " :" << endl;
    open_file << "    name=" << s << endl;

    // open_file.write(s[0]);
    // all_thing.push_back(s);//把 新的任务 加入到 所有任务 中

    // printf("\n请输入任务分值:");
    printf("what's the score of this task:");

    int num = read_int();
    open_file << "    score=" << num << endl;

    task_len ++;//任务总数+1

    open_file.close();

    // all_score.push_back(read_int());//把 新的任务的分值 加到 所有任务的分值 中

    // printf("\n任务添加完成\n");
    printf("succeed!\n");

    return;
}

void autosaving()
{
    // freopen("all_things.txt","w")
    ofstream OpenFile("all_things.txt",ios::app);//用 插入 方式打开 只写文件 all_things.txt

    if(OpenFile.fail())//判断是否打开失败
    {
        // printf("文件打开失败\n");
        printf("failed in opening the file");

        exit(0);
    }

    // int len = all_score.size();
    // for(int i = 0;i < len;i ++)
    // {
    //     string s = all_thing[i];
    //     OpenFile.write(s,s.size());
    //     int num = all_score[i];
    //     OpenFile.write(num,1);
    // }

    OpenFile.close();//关闭文件
}

void read_all_file()
{
    ifstream iopen_file("all_things.txt");
    // ofstream oopen_file("all_things.txt");

    iopen_file >> task_len;

    // if(task_len == 0)
    // {
    //     task_len;
    //     oopen_file << task_len;
    // }

    iopen_file.close();
    // oopen_file.close();
}