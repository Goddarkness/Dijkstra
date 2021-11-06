#include <iostream>

using namespace std;
class Map
{
public :
    double a[6][6]= { { 0,1,4,-1,-1,-1},{1,0,2,7,5,-1} ,{4,2,0,-1,1,-1}, {-1,7,-1,0,3,2} ,{-1,5,1,3,0,6}, {-1,6,-1,2,-1,0}} ;
    double distance[6]; // ��¼��㵽�ĵ�ľ���
    int point [6];  //��¼�������֮ǰ�ĵ�
    int n;  //��ĸ���

    void map( int a); // �����ĸ���
    bool judge[6];  //������ñ����Ϊtrue; judge��ʼ��Ϊfalse
    void distancefirstset();// ��distance��ʼ��
    void dijkstra();  // ��dijkstra�㷨������̾����·��
    void showshortestdistance( int po); //����㵽��po�����̾�����ʾ����
    void showpath( int po);  //����㵽po����̵�·����ʾ����
    void fileread(  char file[]); //���ļ��ж�ȡͼ(������ʽ)
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
     int remain = n; //ʣ��δ������ñ�ŵĸ���
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
