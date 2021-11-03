#include <iostream>

using namespace std;
class Map
{
public :
    double a[6][6]= { { 0,1,4,-1,-1,-1},{1,0,2,7,5,-1} ,{4,2,0,-1,1,-1}, {-1,7,-1,0,3,2} ,{-1,5,1,3,0,6}, {-1,6,-1,2,-1,0}} ;
    double distance[6];
    int point [6];  //记录到这个点之前的点
    int n=6;

    bool judge[6];  //获得永久标号则为true;
    void judgefirstchange();
    void distancefirstset();// 对distance初始化
    void dijkstra();
};

void Map::judgefirstchange()
{
    for( int i=0; i<n; i++)
    {
       judge[i] = false;
    }
}

void Map::distancefirstset()
{
     double maxnumber =0;
    for( int i=0; i<n; i++)
    {
        for ( int j =0 ; j<5 ; j++)
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

int main()
{
    Map mapp;
    mapp.judgefirstchange();
    mapp.distancefirstset();
    mapp.dijkstra();
    cout << mapp.distance[5]<<"  "  <<mapp.point[5]<< endl ;

    return 0;
}
