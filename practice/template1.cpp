#include<iostream>
using namespace std;
template <class X>
 X big(X a,X b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    cout<<big(3,4)<<"\n";
    cout<<big(4.4,5.6)<<"\n";
    string s("Hello");
    int b;
    b=s.find("lo");
    cout<<b;
}
