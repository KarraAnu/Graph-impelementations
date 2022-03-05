#include <vector>
#include <map>
#include <string>
#include <set>
#include "node.hpp"
#include <iostream>

class Adjlist
{
    public:

    std::vector<Node*> lis;
    std::vector<int> names;
    void add_node(int name);
    void add_edge(int from, int to, int cost);
    int qedge(int from, int to);
    void print_list();
    void dfs_helper(int node, std::set<int>& vis);
    void dfs(int start);

};