#pragma once
#include <iostream>
#include "vertex.h"
using namespace std;
class Node {
    public:
        Vertex curr = Vertex();
        Vertex pre = Vertex();
        double dist = 0;
        Node(Vertex given1, double given2, Vertex given3) {
            curr = given1;
            dist = given2;
            pre = given3;
        }
        Node() {}
};
