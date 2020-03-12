#include "Function2.h"
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")

MYSQL* con; //= mysql_init((MYSQL*) 0); 
MYSQL_ROW row;
MYSQL_RES* res;
//数据库信息
char dbuser[30] = "root";
char dbpasswd[30] = "12345678";
char dbip[30] = "localhost";
char dbname[50] = "lol";
char tablename[50] = "lol_data";

legend_data lol_data[300];
HashMap<int, Node*> nodeMap;
HashMap<int, Node*> maps[5];
window3::window3(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


int GET_DATA(legend_data lol_data[300])//从数据库获取数据保存在结构体中并返回结构体总数
{
	char tmp[400];
	int count = 0;

	sprintf(tmp, "select * from %s", tablename);
	int rt = mysql_real_query(con, tmp, strlen(tmp));
	/*if (rt)
	{
		printf("Error making query: %s !!!\n", mysql_error(con));
	}
	else
	{
		printf("%s executed!!!\n", tmp);//这波浪线是啥啊不用管就是字面意思啊没\0= =
	}*/
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
				lol_data[count].CN_name = row[t];
				break;
			case 2:
				lol_data[count].EN_name = row[t];
				break;
			case 3:
				lol_data[count].position = row[t];
				break;
			case 4:
				lol_data[count].win_rate = atof(row[t]);
				break;
			case 5:
				lol_data[count].pick_rate = atof(row[t]);
				break;
			case 6:
				lol_data[count].ban_rate = atof(row[t]);
				break;
			case 7:
				lol_data[count].using_times = atof(row[t]);
				break;
			case 8:
				lol_data[count].kill = atof(row[t]);
				break;
			case 9:
				lol_data[count].death = atof(row[t]);
				break;
			case 10:
				lol_data[count].asisst = atof(row[t]);
				break;
			case 11:
				lol_data[count].max_serial_kill = atoi(row[t]);
				break;
			case 12:
				lol_data[count].damage = atoi(row[t]);
				break;
			case 13:
				lol_data[count].afford = atoi(row[t]);
				break;
			case 14:
				lol_data[count].cure = atoi(row[t]);
				break;
			case 15:
				lol_data[count].last_kill = atof(row[t]);
				break;
			case 16:
				lol_data[count].enemy_monstor_kill = atof(row[t]);
				break;
			case 17:
				lol_data[count].team_monstor_kill = atof(row[t]);
				break;
			case 18:
				lol_data[count].cash = atoi(row[t]);
				break;
			case 19:
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


void init() {

	char tmp[400];
	const char* query = NULL;
	int count = 0;						//数据个数
	LINK_DATABASE();					//链接数据库
	count = GET_DATA(lol_data);			//获取数据储存进结构体

	BoardData data;
	data.init();

	auto TopNode = new Node;
	auto JugNode = new Node;
	auto MidNode = new Node;
	auto AdcNode = new Node;
	auto SupNode = new Node;
	TopNode = createHeadNode(TopNode);
	JugNode = createHeadNode(JugNode);
	MidNode = createHeadNode(MidNode);
	AdcNode = createHeadNode(AdcNode);
	SupNode = createHeadNode(SupNode);
	Node* nodes[5] = { TopNode,JugNode,MidNode,AdcNode,SupNode };
	float win_rate[5];
	for (int i = 0; i < count; i++)		//DEBUG
	{
		//printf("rank:%d\nname:%s\nposition:%s\n", lol_data[i].rank, lol_data[i].EN_name, lol_data[i].position);
		//printf("ban rate:%f\npick rate:%f\nwin rate:%f\nusing times:%f\n", lol_data[i].ban_rate, lol_data[i].pick_rate, lol_data[i].win_rate, lol_data[i].using_times);
		addNode(createNode(lol_data[i]), nodes);
		//printf("Node generate Ok!");
		//printf("*************************\n");
	}
	for (int i = 0; i < 5; ++i) {
		maps[i] = createHashMap(nodes[i]);
	}
	topMapInit(nodes[0]);
	jugMapInit(nodes[1]);
	midMapInit(nodes[2]);
	adcMapInit(nodes[3]);
	supMapInit(nodes[4]);
}

void window3::clicked_confirm() {
	init();
	float win_rate[5];
	std::string s[10];
	s[0] = ui.lineEdit->text().toStdString();
	s[1] = ui.lineEdit_3->text().toStdString();
	s[2] = ui.lineEdit_5->text().toStdString();
	s[3] = ui.lineEdit_6->text().toStdString();
	s[4] = ui.lineEdit_9->text().toStdString();
	s[5] = ui.lineEdit_2->text().toStdString();
	s[6] = ui.lineEdit_4->text().toStdString();
	s[7] = ui.lineEdit_8->text().toStdString();
	s[8] = ui.lineEdit_7->text().toStdString();
	s[9] = ui.lineEdit_10->text().toStdString();
	BoardData data = getAllHeroInfo(s, data, maps);
	getWinrate(win_rate, data);
	QString best_way = QString::fromStdString(graphCreate(win_rate));
	 
	//std::string s = text_generate();
	ui.textBrowser_2->setText(best_way);
}
