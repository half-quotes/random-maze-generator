#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> m;
    public:
    void addEdge(T u,T v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist));
        if(bidir)
            m[v].push_back(make_pair(u,dist));
    }
    void printAdj(){
        // iterate over all keys in the map
        for(auto j:m){
            cout<<j.first<<"->";
            for(auto l:j.second){
                cout<<'('<<l.first<<","<<l.second<<')';
            }
            cout<<endl;
        }
    }
    void dijsktraSSSP(T src,T destination){
        // We need distance array for every node.
        unordered_map<T,int> dist;
        unordered_map<T,T> parent;
        // initial dist. will be INFINITY
        for(auto j:m){
            dist[j.first] = INT_MAX;
            parent[j.first] = j.first;
        }
        // make set to find min. dist
        set<pair<int,T>> s;
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            // find pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodedist = p.first;
            s.erase(s.begin());
            // Iterate over nbrs of current node
            for(auto childpair:m[node]){
                if(nodedist+childpair.second<dist[childpair.first]){
                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        // node is found
                        s.erase(f);
                    }
                    // Insert new pair
                    dist[dest] = nodedist+childpair.second;
                    s.insert(make_pair(dist[dest],dest));
                    parent[dest] = node;
                }
            }
            if(node==destination){
                break;
            }
        }
        vector<T> path;
        path.insert(path.begin(),destination);
        T temp = destination;
        while(true){
            if(parent[temp]!=temp){
                path.insert(path.begin(),parent[temp]);
                temp = parent[temp];
            }else{
                break;
            }
        }
        if(dist[destination]==0 || dist[destination]==INT_MAX){
            cout<<"There is no path between "<<src<<" and "<<destination<<endl;
            return;
        }
        cout<<"Path between cities is : ";
        for(auto i:path){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<destination<<" is located at a distance of "<<dist[destination]<<" from "<<src<<endl;
    }
};

void createGraph(Graph<string> &india){
    india.addEdge("Amrister","Lucknow",13);
    india.addEdge("Amritsar","Bengaluru",2);
    india.addEdge("Agra","Amritsar",1);
    india.addEdge("Delhi","Agra",2);
    india.addEdge("Delhi","Mumbai",30);
    india.addEdge("Delhi","Amritsar",25);
    india.addEdge("Mumbai","Agra",5);
    india.addEdge("Mumbai","Ahmedabad",14);
    india.addEdge("Mumbai","Bhopal",4);
    india.addEdge("Bhopal","Delhi",11);
    india.addEdge("Bhopal","Kolkata",9);
    india.addEdge("Bengaluru","Lucknow",12);
    india.addEdge("Bengaluru","Bhopal",17);
    india.addEdge("Bengaluru","Jaipur",8);
    india.addEdge("Ahmedabad","Kolkata",3);
    india.addEdge("Ahmedabad","Hyderabad",6);
    india.addEdge("Kolkata","Mumbai",9);
    india.addEdge("Jaipur","Kolkata",8);
    india.addEdge("Hyderabad","Jaipur",7);
}
