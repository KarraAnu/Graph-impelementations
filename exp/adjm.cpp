#include "adjm.hpp"

void Adjmatrix::add_node(int name){
    for (int i = 0; i < this->names.size() ; i++){
        this->mat[i].push_back(-1);
    }
    std::vector<int> new_row(this->mat.size()+1, -1);
    this->mat.push_back(new_row);
    this->names.push_back(name);

}

void Adjmatrix::add_edge(int from, int to, int cost){
    if (from < this->names.size() && from >= 0){
        std::cout << "Error\n";
        return;
    }
    if (to < this->names.size() && to >= 0){
        std::cout << "Error\n";
        return;
    }
    this->mat[to][from] = cost;
}

int Adjmatrix::qedge(int from, int to){
    if (from < this->names.size() && from >= 0){
        std::cout << "Error\n";
        return;
    }
    if (to < this->names.size() && to >= 0){
        std::cout << "Error\n";
        return;
    }
    return mat[to][from];
}

void Adjmatrix::print_graph(){
    for(int i = 0 ; i < this->mat.size(); i++){
        for(int j = 0 ; j < this->mat[0].size(); j++){
            if (this->mat[j][i] != -1){
                std::cout << j << "--" << this->mat[j][i] << "--" << i << "\n";
            }
        }
    }
}

