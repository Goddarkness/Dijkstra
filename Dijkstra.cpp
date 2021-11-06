#include <iostream>

using namespace std;
class Map
{
public :
    double a[6][6]= { { 0,1,4,-1,-1,-1},{1,0,2,7,5,-1} ,{4,2,0,-1,1,-1}, {-1,7,-1,0,3,2} ,{-1,5,1,3,0,6}, {-1,6,-1,2,-1,0}} ;
    double distance[6]; // 记录起点到改点的距离
    int point [6];  //记录到这个点之前的点
    int n;  //点的个数

    void map( int a); // 输入点的个数
    bool judge[6];  //获得永久标号则为true; judge初始化为false
    void distancefirstset();// 对distance初始化
    void dijkstra();  // 用dijkstra算法计算最短距离和路线
    void showshortestdistance( int po); //将起点到最po点的最短距离显示出来
    void showpath( int po);  //将起点到po点最短的路径显示出来
    void fileread(  char file[]); //从文件中读取图(矩阵形式)
};

void Map::map(int a)
{
    n = a;
}


void Map::distancefirstset()
{
     double maxnumber =0;
    for( int i=0; i<n; i++)
    {
        for ( int j =0 ; j<n ; j++)
        {
          maxnumber = maxnumber+abs(a[i][j]);
        }
    }
    distance[0] = 0;
    for( int i=1; i<n; i++)
    {
            distance[i]=maxnumber;
    }
}

void Map::dijkstra()
{
     int remain = n; //剩余未获得永久标号的个数
     int i=0,j=0;
     point[0] = 0;

     for (  ; remain>0; remain--)
     {
        for( j =0 ; j<n; j++)
        {
            if(  a[i][j] != -1 &&   a[i][j]+ point[i] < distance[j] && ( !judge[j]) && i != j)
            {
                distance[j] = a[i][j] + distance[i];
                 point[j] = i;
            }
        }
        judge[i] = true;
        int mindis =56546;
        int nextpoint = 1;
        for ( int m =1 ; m <n ; m++)
        {
            if ( remain != 1 && (!judge[m]) &&  distance[m] < mindis  )
            {
                mindis = distance[m];
                 nextpoint = m;
            }
        }
        i = nextpoint;
     }
}

void Map::showshortestdistance( int po)
{
    cout << distance[po] << endl;
}

void Map::showpath(  int po)
{
    int storage[n]={0};
    int i = n;
    cout << " v("<<0<<")";
    for(  ; point[po]; i-- )
    {
        storage[i] = point[po];
        po = point[po];
    }
    i++;
    for(  ; i<=n; i++)
    {
        cout<<"->"<<"v("<<storage[i]<<")";
    }
    cout << endl;
}

void Map::fileread(  char file[])
{

    FILE *fp;
    char c;
    if ( (fp = fopen( file,"r")) == NULL)
    {
        printf("cannot open the file\n");
        exit(0);
    }

     while ( c = fgetc(fp)!= EOF)
     {

     }

    if ( fclose(fp))
    {
        printf("cannot close this file\n");
        exit(0);
    }

}

int main()
{
    Map mapp;
    mapp.map(6);
    mapp.distancefirstset();
    mapp.dijkstra();
    mapp.showshortestdistance(5);
    mapp.showpath(5);

    return 0;
}
