// Your First C++ Program
#include "adjl.cpp"

#include <iostream>

int main() {
    Adjlist new_list;

    new_list.add_node(0);
    new_list.add_node(1);
    new_list.add_node(2);
    new_list.add_node(3);

    new_list.add_edge(0,3,1);
    new_list.add_edge(3,0,1);
    new_list.add_edge(1,1,1);
    new_list.add_edge(2,3,1);
    new_list.add_edge(3,1,1);
    new_list.print_list();
    new_list.dfs(1);
    return 0;
}