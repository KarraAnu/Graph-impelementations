#include <vector>
#include <map>
#include <string>
#include <iostream>

class Adjmatrix{
    public:
    std::vector<std::vector<int>> mat;
    std::vector<int> names;

    void add_node(int name);
    void add_edge(int from, int to, int cost);
    int qedge(int from, int to);

    void print_graph();

    void dfs();


};