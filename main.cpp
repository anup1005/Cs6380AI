#include<bits/stdc++.h>
#include<vector>
using namespace std;
    int minimum(vector<double> v){    // it is used to determine minimum element index in a vector
       int len=v.size();
       int min=0;
       for(int j=0;j<len;j++){
           if(v[min]>v[j])
                min=j;
       }
       return min;
    }
    void print (vector<int> v){    //it is used to print a vector
        int len=v.size();
        for(int i=0;i<len;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }


int main(){
    string s;
    cin>>s;
    if(s=="non"){     // taking input whether input distance is eucledian or non eucledian
	cin>>s;
	}
    int n;
    double x,y;
    cin>>n;
    for(int i=1;i<=n;i++)   // taking input coordinates of cities
        cin>>x>>y;
        
    double temp;
    vector<vector<double>> adjl;
    for(int i=0;i<n;i++){     //storing distance between cities in adjacency matrix
        vector<double>  v;
        for(int j=0;j<n;j++){
            cin>>temp;
            v.push_back(temp);
        }
        adjl.push_back(v);
    }
    
    vector<int> res;
    vector<vector<int>> resultpath;
    double sum;
    vector<double> resultsum;
    vector<bool> visited(n,false);
    int ch=0;
    
    for(int c=0;c<n;c++){     //applying greedy heuristic by always choosing the nearest neighbour
        int curr=c;
        for(int i=0;i<n;i++)     visited[i]=false;
        sum=0;   
        res.clear();
        vector<vector<double>> adjm=adjl;
        visited[curr]=true;
        res.push_back(curr);
        for(int count=1;count<n;count++){
            auto ind=minimum(adjm[curr]);
            while(visited[ind]==true){
                adjm[curr][ind]=DBL_MAX;
                ind=minimum(adjm[curr]);
        }
            sum+=(adjm[curr][ind]);
            visited[ind]=true;
            res.push_back(ind);
            curr=ind;
    }
    sum+=adjm[c][curr];
    

    if(ch==0){
        print(res);
        ch=1;
    }
    else{
        int min=minimum(resultsum);
        if(sum<resultsum[min]){
            print(res);
        }
            
        }
        resultpath.push_back(res);
        resultsum.push_back(sum);
    }
    
}