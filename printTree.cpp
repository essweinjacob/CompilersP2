#include "printTree.h"

void printPreorder(Node *node, int depth, string indent, bool last){
    if(node == NULL){
        cout << "Here?" << endl;
        return;
    }

    string indentSign = "";
    if(depth > 0){
        indentSign = (last) ? "|_" : "|-";
    }else{
        indentSign = "";
    }
    cout << indent << indentSign << node->name << " ";

    for(unsigned int i = 0; i < node->tokens.size(); i++){
        cout << node->tokens[i].val;

        if(((i + 1) != node->tokens.size()) && (node->tokens[i].id != opTK)){
            cout << ",";
        }
        cout << " ";
    }
    cout << endl;

    indent += (last) ? "  " : "|  ";
    vector<Node*>nodes;
    if(node->n1 != NULL){
        nodes.push_back(node->n1);
    }
    if(node->n2 != NULL){
        nodes.push_back(node->n2);
    }
    if(node->n3 != NULL){
        nodes.push_back(node->n3);
    }
    if(node->n4 != NULL){
        nodes.push_back(node->n4);
    }

    for(unsigned int i = 0; i < nodes.size(); i++){
        printPreorder(nodes[i], depth + 1, indent, i == nodes.size() - 1);
    }
}