#include "adjl.hpp"

void Adjlist::add_node(int name){
    this->lis.push_back(nullptr);
    this->names.push_back(name);
}

void Adjlist::add_edge(int from, int to, int cost){
    if (!(this->names.size() > from && from >= 0)){
        std::cout << "Error\n";
        return;
    }
    if (!(this->names.size() > to && to >= 0)){
        std::cout << "Error\n";
        return;
    }
    if (this->lis[from] == nullptr){
        Node* new_node = new Node;
        new_node->next = nullptr;
        new_node->to = to;
        new_node->cost = cost;
        this->lis[from] = new_node;
    }else{
        Node* cur = this->lis[from];
        Node* nex = cur->next;
        while (nex!=nullptr){
            cur = nex;
            nex = cur->next;
        }
        Node* new_node = new Node;
        new_node->next = nullptr;
        new_node->cost = cost;
        new_node->to = to;
        cur->next = new_node;
    }

}

int Adjlist::qedge(int from, int to){
    if (!(this->names.size() > from && from >= 0)){
        std::cout << "Error\n";
        return -1;
    }
    if (!(this->names.size() > to && to >= 0)){
        std::cout << "Error\n";
        return -1;
    }
    int flag = -1;
    Node* cur = this->lis[from];
    Node* nex = nullptr;
    while (cur!=nullptr){
        nex = cur->next;
        if (cur->to == to){
            flag = cur->cost;
        }
        cur = nex;
        
    }

    return flag;

}

void Adjlist::print_list(){
    for (int i = 0 ; i < this->names.size() ; i++){
        std::cout << this->names[i] << ": ";
        Node* cur = this->lis[i];
        Node* nex = nullptr;
        while (cur!=nullptr){
            nex = cur->next;
            std::cout << i << "--" << cur->cost << "--" << cur->to << " ";
            cur = nex;
            
        }
        std::cout << "\n";
    }
}

void Adjlist::dfs_helper(int node, std::set<int>& vis){
    std::cout<< "Visited: " << node << "\n";
    vis.insert(node);
    Node* cur = this->lis[node];
    Node* nex = nullptr;
    while (cur != nullptr){
        nex = cur->next;
        if (vis.count(cur->to) == 0){
            this->dfs_helper(cur->to, vis);
        }
        cur = nex;
    }
}

void Adjlist::dfs(int start){
    std::set<int> vis;
    this->dfs_helper(start, vis);

}


