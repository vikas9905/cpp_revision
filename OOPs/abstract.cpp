#include<iostream>
using namespace std;
class Base{
public:
    Base(){
      cout<<"IN Base Class\n";
    }

    void virtual abstract()=0;
    void show(){
        cout<<"Abstract Class\n";
    }

};
class derived : public Base{
public:
  derived(){
     cout<<"In  derived\n";
  }

  void fun(){
     cout<<"Not implemented Base class hence it is also abstract class\n";
  }

};
class derived2:public derived{
    public:
    derived2(){
        cout<<"In derived2\n";
    }
      void virtual abstract(){
         cout<<"Implementation of abstract defination\n";
      }
};
int main(){
   //Base obj;//Error due to abstract
//   derived obj;
  derived2 obj;
   Base *b=&obj;
   b->abstract();
}
