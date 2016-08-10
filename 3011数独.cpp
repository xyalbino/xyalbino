#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

const int N = 30;
const int INF = 1000000;

int Map[N][N];
int k, f, flag0;

struct node
{
    int x, y;
}road[90];

bool check(int r, int s)//�ж��Ƿ�������������
{
    int i, j;
    int x = road[r].x;
    int y = road[r].y;
    for(i = 0; i < 9; i ++)
        if(Map[x][i] == s || Map[i][y] == s) return false;//ͬ��ͬ�в�������ͬ������
    x = x / 3 * 3;
    y = y / 3 * 3;
    for(i = 0; i < 3; i ++)
        for(j = 0; j < 3; j ++)
            if(Map[x + i][y + j] == s) return false;//3*3�ĸ�����û����ͬ������
    return true;
}

void dfs(int r)
{
    int i,j,s;
    if(r == k) //�Ѿ������������ʺŴ�����Ѱ���˿��н�
    {
        f = 1;
        for(i = 0; i < 9; i ++)
        {
            for(j = 0; j < 9; j ++)
                printf("%d", Map[i][j]);
            printf("\n");
        }
                flag0 = 0;//�п��н�
    }
    if(f) return;
    for(s = 1; s <= 9; s ++)//�ؼ����֣��ݹ�ķ���Ѱ�ҿ��н�
    {
        if(check(r, s))
        {
            Map[road[r].x][road[r].y] = s;
            dfs(r + 1);
            Map[road[r].x][road[r].y] = 0;//������ʱ���¸�ֵ0���ٴ�Ѱ�ҿ��н�
        }
    }
}

int main()
{

    char a, tag[10];
    int T, i, j, flag = 0;
    scanf("%d", &T);
    while(T --)
    {
        flag0 = 1;
        if(flag) printf("---\n");
        flag = 1;
        k = f = 0;
        for(i = 0; i < 9; i ++)
            for(j = 0; j < 9; j ++)
            {
                cin >> a;
                if(a == '?')
                {
                    Map[i][j] = 0;  //map��ʾijλ�õ�ֵ������Ϊ0
                    road[k].x = i;
                    road[k].y = j; //roadk��ʾ�ڼ����ʺţ�road.x,road.y��ʾ����λ��
                    k++;
                }
                else Map[i][j] = a - '0';
            }
        cin >> tag;//tag����---������ö���
        dfs(0);
        if(flag0) printf("impossible\n");
    }
    return 0;
}
