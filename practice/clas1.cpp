#include<iostream>
using namespace std;
class shape
{
    public:
    int height;
    int width;
};
class rectangle :public shape
{
public:
    int area()
    {
        return(height*width);
    }
};
int main()
{
    shape p;
    rectangle r;
    r.height=2;
    r.width=3;
    cout<<r.area();
}
