# include <iostream>
using namespace std;
class i{
    int x;
    public:
    i(int n){
        x=n;
    }
    friend int operator !(i&);
    
 void d(){
     cout<<"Factorial is"<<x;
 }
};
 int operator !(i &ob){
     int f=1;
     for(int i = 1; i <=ob.x; ++i) {
            f *= i;
        }
        return f;
     
 }
int main(){
    i ob1(6);
  int fact;
    fact=!ob1;
    cout<<fact;
    return 0;

}
