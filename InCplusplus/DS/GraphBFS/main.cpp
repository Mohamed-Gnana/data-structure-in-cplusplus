#include <iostream>
#include <list>

using namespace std;

class Graph{

private:
    int V ;
    list<int>* adj ;

public:
    Graph (int virtices) {
        V = virtices ;
        adj = new list<int>[V];
    }

    void addedges (int v , int w) {
        adj[v].push_back(w);
    }

    void BFS (int s) {
        bool* visited = new bool[V];
        for (int i = 0 ; i < V ; i++)
            visited[i] = false ;

        list<int> que ;
        visited[s] = true ;
        que.push_back(s) ;

        list<int> :: iterator i ;

        while (!que.empty()){
            s = que.front();
            cout << s << " " ;
            que.pop_front();

            for (i = adj[s].begin() ; i != adj[s].end() ; ++i) {
                if(!visited[*i]){
                    visited[*i] = true ;
                    que.push_back(*i);
                }
            }
        }
    }


    void DFS (int s) {
        bool* visited = new bool[V];
        for (int i = 0 ; i < V ; i++)
            visited[i] = false ;

        list<int> stk ;

        visited[s] = true ;
        stk.push_back(s) ;

        list<int> :: iterator i ;

        while (!stk.empty()){
            s = stk.back() ;
            cout << s << " " ;
            stk.pop_back();

            for (i = adj[s].begin() ; i != adj[s].end() ; ++i){
                if (!visited[*i]){
                    visited[*i] = true ;
                    stk.push_back(*i);
                }
            }
        }

    }

    void DFSinit (int s , bool* visited){
        visited[s] = true ;
        cout << s << " " ;
        list<int> :: iterator i ;

        for (i = adj[s].begin() ; i != adj[s].end() ; ++i){
            DFSinit(*i , visited);
        }
    }

    void DFSrec (int s) {
        bool* visited = new bool[V];
        for (int i = 0 ; i < V ; ++i)
            visited[i] = false ;

        DFSinit(s,visited);
    }


};

int main()
{

    //   0-- 1
    //  || /
    //   2-- 3--
    //        |--|
    //
    // >> 2 0 3 1
    Graph g(7);
    g.addedges(0, 1);
    g.addedges(0, 2);
    g.addedges(1, 3);
    g.addedges(1, 4);
    g.addedges(2, 5);
    g.addedges(2, 6);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFSrec(0);
    return 0;
}
