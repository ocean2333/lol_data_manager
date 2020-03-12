// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include <stdio.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")
#include "RBTree.h"
#include <algorithm>
#include <vector>
#include <iterator>

//数据库列名；注意变量名不要使用相同名称
/*
#define RANK 0
#define NAME 1
#define POSITION 2
#define WIN_RATE 3
#define PICK_RATE 4
#define BAN_RATE 5
#define USING_TIMES 6
#define KILL 7
#define DEATH 8
#define ASISST 9
#define MAX_SERIAL_KILL 10
#define DAMAGE 11
#define AFFORD 12
#define CURE 13
#define LAST_KILL 14
#define ENEMY_MONSTOR_KILL 15
#define TEAM_MONSTOR_KILL 16
#define CASH 17
#define SAME_POSITION_RANK 18
*/

MYSQL* con; //= mysql_init((MYSQL*) 0); 
MYSQL_ROW row;
MYSQL_RES* res;
//数据库信息
char dbuser[30] = "root";
char dbpasswd[30] = "20000613";
char dbip[30] = "localhost";
char dbname[50] = "lol";
char tablename[50] = "lol_data";


struct legend_data {
	int rank;
	char* name;
	char* position;
	float win_rate;
	float pick_rate;
	float ban_rate;
	float using_times;
	float kill;
	float death;
	float asisst;
	int max_serial_kill;
	int damage;
	int afford;
	int cure;
	float last_kill;
	float enemy_monstor_kill;
	float team_monstor_kill;
	int cash;
	int same_position_rank;
}LEGEND_DATA;
/*
结构体组成：
rank				排名
name				英雄
position			位置
win_rate			胜率
pick_rate			登场率
ban_rate			被禁率
using_times			人均使用次数
kill				击杀
death				死亡
asisst				助攻
max_serial_kill		场均最大连杀
damage				造成英雄伤害
afford				承受英雄伤害
cure				总治疗量
last_kill			补刀数
enemy_monstor_kill	击杀敌方野怪
team_monstor_kill	击杀己方野怪
cash				金钱
same_position_rank	同位置排名
*/

legend_data lol_data[300];

int GET_DATA(legend_data lol_data[])//从数据库获取数据保存在结构体中并返回结构体总数
{
	char tmp[400];
	int count = 0;
	
	sprintf(tmp, "select * from %s", tablename);
	int rt = mysql_real_query(con, tmp, strlen(tmp));
	if (rt)
	{
		printf("Error making query: %s !!!\n", mysql_error(con));
	}
	else
	{
		printf("%s executed!!!\n", tmp);
	}
	res = mysql_store_result(con);//将结果保存在res结构体中

	while (row = mysql_fetch_row(res)) {
		for (unsigned int t = 0; t < mysql_num_fields(res); t++) {
			//printf("%s  \n", row[t]);
			switch (t)
			{
			case 0:
				lol_data[count].rank = atoi(row[t]);
				break;
			case 1:
				lol_data[count].name = row[t];
				break;
			case 2:
				lol_data[count].position = row[t];
				break;
			case 3:
				lol_data[count].pick_rate = atof(row[t]);
				break;
			case 4:
				lol_data[count].win_rate = atof(row[t]);
				break;
			case 5:
				lol_data[count].ban_rate = atof(row[t]);
				break;
			case 6:
				lol_data[count].using_times = atof(row[t]);
				break;
			case 7:
				lol_data[count].kill = atof(row[t]);
				break;
			case 8:
				lol_data[count].death = atof(row[t]);
				break;
			case 9:
				lol_data[count].asisst = atof(row[t]);
				break;
			case 10:
				lol_data[count].max_serial_kill = atoi(row[t]);
				break;
			case 11:
				lol_data[count].damage = atoi(row[t]);
				break;
			case 12:
				lol_data[count].afford = atoi(row[t]);
				break;
			case 13:
				lol_data[count].cure = atoi(row[t]);
				break;
			case 14:
				lol_data[count].last_kill = atof(row[t]);
				break;
			case 15:
				lol_data[count].enemy_monstor_kill = atof(row[t]);
				break;
			case 16:
				lol_data[count].team_monstor_kill = atof(row[t]);
				break;
			case 17:
				lol_data[count].cash = atoi(row[t]);
				break;
			case 18:
				lol_data[count].same_position_rank = atoi(row[t]);
				break;
			default:
				printf("error!\n");
				break;
			}
		}
		//printf(".............\n");
		count++;
	}
	
	return count;
}

void LINK_DATABASE() //连接数据库
{
	con = mysql_init((MYSQL*)0);
	if (con != NULL && mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, 3306, NULL, 0)) {
		if (!mysql_select_db(con, dbname)) {
			printf("Select successfully the database!\n");
			con->reconnect = 1;
			const char* query = "set names \'GBK\'";
			//query = query_tmp;
			int rt = mysql_real_query(con, query, strlen(query));
			if (rt) {
				printf("Error making query: %s !!!\n", mysql_error(con));
			}
			else {
				printf("query %s succeed!\n", query);
			}
		}
	}
	else {
		MessageBoxA(NULL, "Unable to connect the database,check your configuration!", "", NULL);
	}
}

int main()
{
	char tmp[400];
	
	const char* query = NULL;
	//int x;
	//int y;
	int count = 0;						//数据个数

	//sprintf(tmp, "insert into %s values(%s,%d,%d)", tablename, "null", x, y); //注意如何向具有自增字段的数据库中插入记录
	//sprintf(tmp, "insert into bl values(null,'x','x','x','x')");
	/*
	rt = mysql_real_query(con, tmp, strlen(tmp));
	if (rt)
	{
		printf("Error making query: %s !!!\n", mysql_error(con));
	}
	else
	{
		printf("%s executed!!!\n", tmp);
	}

	*/

	LINK_DATABASE();					//链接数据库
	count = GET_DATA(lol_data);			//获取数据储存进结构体
	
	for (int i = 0; i < count; i++)		//DEBUG
	{
		printf("rank:%d\nname:%s\nposition:%s\npick rate:%f\n",lol_data[i].rank,lol_data[i].name,lol_data[i].position,lol_data[i].win_rate);

		printf("ban rate:%f\nwin rate:%f\nwin rate:%f\nusing times:%f\n", lol_data[i].ban_rate, lol_data[i].pick_rate, lol_data[i].win_rate, lol_data[i].using_times);
		printf("*************************\n");
	}


	//printf("number of rows %d\n", count);
	//printf("mysql_free_result...\n");
	mysql_free_result(res);
	mysql_close(con);


	RB_Tree<int, int> tree;
	vector<int> v;
	int i = 0;
	for (i = 0; i < 20; ++i)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	stringstream sstr;
	for (i = 0; i < v.size(); ++i)
	{
		tree.Insert(v[i], i);
		cout << "insert:" << v[i] << endl;   //添加结点
	}
	for (i = 0; i < v.size(); ++i)
	{
		cout << "Delete:" << v[i] << endl;
		tree.Delete(v[i]);             //删除结点
		tree.InOrderTraverse();
	}
	cout << endl;
	tree.InOrderTraverse();



	system("pause");
	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


