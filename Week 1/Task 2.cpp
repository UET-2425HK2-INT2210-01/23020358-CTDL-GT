#include <iostream>
using namespace std;
class Point {
    public:
        float x;
        float y;
    void getPoint(float a, float b) {
        x = a;
        y = b;
    }
};
class Line{
    public:
        Point a,b;
};
int check(Line m, Line n) {
    float h1 = (m.a.y-m.b.y)/(m.a.x-m.b.x);
    float h2 = (n.a.y-n.b.y)/(n.a.x-n.b.x);
    if (h1 != h2) return 1;
    else {
        if (m.a.y-h1*m.a.x != n.a.y-h2*n.a.x) 
            return 2;
        else 
            return 3;
    }
}
void Inter(Line m, Line n) {
    if (check(m,n) == 2) cout<<"NO";
    else if (check(m,n) == 3) 
        cout<<"MANY";
    else {
        float a1 = (m.a.y-m.b.y)/(m.a.x-m.b.x);
        float a2 = (n.a.y-n.b.y)/(n.a.x-n.b.x);
        float b1 = m.a.y-a1*m.a.x;
        float b2 = n.a.y-a2*n.a.x;
        float x = (b1 - b2) / (a2 - a1);
        float y = x*a1 + b1;
        printf("%.2f %.2f",x,y);
    }
};
int main(){
    Point list[4];
    for (int i = 0; i<4; i++){
        int a,b;
        cin>>a>>b;
        list[i].getPoint(a,b);
    }
    Line AB;
    Line CD;
    AB.a = list[0];
    AB.b = list[1];
    CD.a = list[2];
    CD.b = list[3];
    Inter(AB,CD);
}