#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include "dataloader.h"
#include "pngtest.cpp"
using namespace std;
struct E {
    int next;
    int len;
    int cost;
};
vector<E> edge[1001];
int Dis[1001];
int cost[1001];
bool mark[1001];

//输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数 s,t;起点s，终点t。n和m为0时输入结束。
// 3 2
// 1 2 5 6
// 2 3 4 5
// 1 3
// 0 0
//输出 一行有两个数， 最短距离及其花费。


int main()
{
    PNGLine(-155.86000061035156, 20.265300750732422,-76.60880279540001,37.132499694799996);
    Dataloader din("/Users/wjh/Desktop/dan/dan/routes.dat", "/Users/wjh/Desktop/dan/dan/airports.dat");
    return 0;
}