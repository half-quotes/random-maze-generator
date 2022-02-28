//pilot program
#include<bits/stdc++.h>
#include"generate.h"
#include"shortest.h"
#include "project.h"

    void expedition(){
        Graph<string> india;
        // india.printAdj();
        createGraph(india);
        cout<<"Cities Available :\nAmrister\nBengaluru\nDelhi\nAgra\nLucknow\nMumbai\nBhopal\nKolkata\nJaipur\nHyderabad\n";
        string src,dest;
        cout<<"\nEnter source city  ";
        cin>>src;
        cout<<"\nEnter destination city  ";
        cin>>dest;
        india.dijsktraSSSP(src,dest);
    }
    void mazeSolver(){
        int maze[6][6],s1,s2,d1,d2;
        gener8((int *)maze,&s1,&s2,&d1,&d2);
        driver((int *)maze,&s1,&s2,&d1,&d2);
    }
    int main()
    {
        int choice;
        cout<<"ENTER A NUMBER TO CHOOSE A SPECIFIC TASK\n1. To find the path and shortest distance betwenn any two cites.\n2. To create a random maze and get its shortest distance from source to destination\n";
            cin>>choice;
            switch (choice)
            {
            case 1:
                expedition();
                break;
            case 2:
                mazeSolver();
            default:
                break;
            }
    }
