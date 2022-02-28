#include <stdio.h>
#include<array>
#include <stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

int a[6][6];
int x,y,x2,y2;
int countr=2;
// random variable uing rand function
// num = (rand() % (upper – lower + 1)) + lower
//random source cell index
int q=(rand()%5);
int w=(rand()%5);
//checking if is among 4 valid neighbour
int valid_neighbour(int i,int j)
{
    
    if(i<0 || i>4 || j<0 || j>4||a[i][j]==1)
    {//cout<<i<<"u"<<j<<"u\n";//debugging
    return 0;
    }
    else
    return 1;
}
//generating random binary maze using modified DFS
void gener8(int *maze,int *s1,int *s2, int *d1,int *d2)
{
    //intializing all 0
    for(int t1=0;t1<6;t1++)
    {
        for(int t2=0;t2<6;t2++)
        {
            a[t1][t2]=0;
        }
    }
   
    srand(time(0));//resetting
    
    x=q;
    y=w;
    //source cell as 1
    a[x][y]=1;
    int c[4],x1=0,g;
    while(x1!=-1)
    {
    //srand(time(0));
    //int weight=(rand()%21);//debugging
    int b[4][2]={{x-1,y},{x+1,y},{x,y-1},{x,y+1}};// cell index for possible neighbour
    x1=-1;

    for(int p=0;p<4;p++)
    {
    if(valid_neighbour(b[p][0],b[p][1])==1)//checking all 4 neighbour
    {
        c[++x1]=p;//if neighbour is possible than store p index in array c
    }
    }
    srand(time(0));
    if(x1!=-1&&x1!=0)
    g=(rand()%(x1+1));//randomly choosing an index of array c making that index neighbour from array b maze's next cell
    if(x1==0)
    g=0;//if only one neighbour is there
    else{
        //if there is no neighbour present 
    x2=x;
    y2=y;//last cell of maze
    }
    int a1=b[c[g]][0],a2=b[c[g]][1];
    a[a1][a2]=1;//marking that next cell 1 from generated index g for array c which will get index of neighbour from array b
    ;
    //cout<<weight;
    //cout<<a1<<" "<<a2<<" "<<x<<" "<<y<<g<<"\n";//debugging
    x=a1,y=a2;
    
    }

    cout<<"random generated maze\n";
    srand(time(0));
    for(int g1=0;g1<6;g1++)
    {
        
        for(int h=0;h<6;h++)
        {
            *((maze+g1*6) + h)=a[g1][h];
            cout<<a[g1][h]<<"       ";
        }
        cout<<"\n";
    }

    *s1=q;
    *s2=w;
    *d1=x2;
    *d2=y2;
    cout<<"source "<<q<<" "<<w<<"\n";
    //cout<<a[q][w]<<"\n";//debugging
    cout<<"destination "<<x2<<" "<<y2<<"\n";
    //cout<<a[x2][y2]<<"\n";//debugging

    
}
