//Undirected Graph Lecture
//-------------------------------------

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;




class Node{

public:
    explicit Node(int n){
        this->index=n;
    }
    int index;
    vector<int> adjacent;
    void connect_node(int n);

};

class Graph{
    vector<Node> nodes;
    int lastNode=0;

public:
    void add_node();
    void connect_nodes(int n, int m);
    void print_edges();
};


Graph build_graph(){
    Graph g;
    int v,e,n,m;
    ifstream myfile;
    myfile.open ("/Users/jimstewart/Git/UndirectedGraphCpp/graph_data.txt");
    if(!myfile.is_open())
        return g;
    myfile >> v;
    myfile>>e;
    while(v--)
        g.add_node();

    while(e--){
        myfile>>n>>m;
        g.connect_nodes(n,m);
    }

    myfile.close();
    return g;

}





void Node::connect_node(int n){
    adjacent.push_back(n);
}

void Graph::add_node(){
    Node n(lastNode++);
    nodes.push_back(n);
}

void Graph::connect_nodes(int n, int m){
    nodes[n].connect_node(m);
    nodes[m].connect_node(n);
}

void Graph::print_edges(){
    for(Node n:nodes){
        cout<<n.index<<": ";
        for(int a:n.adjacent){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}

int main() {
    Graph g = build_graph();

    g.print_edges();

}
