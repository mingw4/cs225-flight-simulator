#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef struct route {
    int SourcePortID;
    int DestPortID;
    float weight;
    friend bool operator < (const route& n1, const route& n2)
    {
        if(n1.SourcePortID < n2.SourcePortID)
            return true;
        else if(n1.SourcePortID == n2.SourcePortID) {
            return n1.DestPortID < n2.DestPortID;
        }else 
            return false;
    }
}Route;

typedef struct airport {
    int PortID;
    string PortName;
    string City;
    string Country;
    float Latitude;
    float Longitude;
    friend bool operator < (const airport& n1, const airport& n2)
    {
        return n1.PortID < n2.PortID;
    }
}Port;

class Dataloader {
public:
    Dataloader(string fileName, string filePorts);
public:
    set<Route> Routes;
    map<int,Port> Ports;
};
