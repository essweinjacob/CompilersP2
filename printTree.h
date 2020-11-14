#ifndef PRINTTREE_H
#define PRINTTREE_H
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "node.h"
using namespace std;

void printPreorder(Node *node, int depth = 0, string dent = "", bool last = true);

#endif