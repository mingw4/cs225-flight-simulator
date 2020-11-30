#include "dataloader.h"
#include <cstring>
#include <set>
#include <math.h>
double toRadians(double angdeg)
{
    double E = 2.7182818284590452354;
    double PI = 3.14159265358979323846;
    return angdeg / 180.0 * PI;
}
//根据经纬度算距离
double getDistance(Port n1, Port n2)
{
    double longitude1=n1.Longitude, latitude1=n1.Latitude, longitude2=n2.Longitude, latitude2=n2.Latitude;
    //维度
    double  lat1 = toRadians(latitude1);
    double  lat2 = toRadians(latitude2);
    //经度
    double  lng1 = toRadians(longitude1);
    double  lng2 = toRadians(longitude2);
    //纬度之差
    double  a = lat1 - lat2;
    //精度之差
    double  b = lng1 - lng2;
    //计算两点距离之差
    double s = 2*asin(sqrt(pow(sin(a/2),2)+cos(lat1)*cos(lat2)*pow(sin(b/2),2)));
    s = s * 6371;//地球半径单位千米
    return s;
}
FILE * FileOpen(string fileName)
{
    FILE *fp = NULL;
    fp = fopen(fileName.c_str(), "r");
    if(fp==NULL)
    {
        cout << fileName << ":File 404..." << endl;
        exit(-1);
    }
    return fp;
}
Dataloader::Dataloader(string fileRoute, string filePorts)
{
    // 读取机场信息
    FILE *fp = FileOpen(filePorts);
    char tempC[400];
    Port tempP;
    for(;;)
    {
        fgets(tempC,400,fp);
        if(feof(fp))
            break;
        char *p;
        p = strtok(tempC, ",");
        for (int i = 0; i < 8; i++)
        {
            if(i==0)
                tempP.PortID = atoi(p);
            else if(i==1)
                tempP.PortName = string(p);
            else if(i==2)
                tempP.City = string(p);
            else if(i==3)
                tempP.Country = string(p);
            else if(i==6)
                tempP.Latitude = atof(p);
            else if(i==7)
                tempP.Longitude = atof(p);
            p = strtok(NULL, ",");
        }
        Ports.insert(pair<int, Port>(tempP.PortID, tempP));
    }
    cout << "PortsNum:" << Ports.size() << endl;
    fclose(fp);
    // 读取航线信息
    fp = FileOpen(fileRoute);
    Route tempR;
    map<int, Port>::iterator itera;
    map<int, Port>::iterator iterb;
    for(;;)
    {
        fgets(tempC,400,fp);
        if(feof(fp))
            break;
        char *p;
        p = strtok(tempC, ",");
        bool flag = false;
        for (int i = 0; i < 6; i++)
        {
            if(p[0]=='\\')
            {
                flag = true;
                continue;
            }
            if(i==3)
                tempR.SourcePortID = atoi(p);
            else if(i==5)
                tempR.DestPortID = atoi(p);
            p = strtok(NULL, ",");
        }
        if(flag)
            continue;
        itera = Ports.find(tempR.SourcePortID);
        iterb = Ports.find(tempR.DestPortID);
        if(itera == Ports.end() || iterb == Ports.end())
            continue;
        tempR.weight = getDistance(itera->second, iterb->second);
        Routes.insert(tempR);
    }
    cout << "RouteNum:" << Routes.size() << endl;
}