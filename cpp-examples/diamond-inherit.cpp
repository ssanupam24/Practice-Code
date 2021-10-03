#include <bits/stdc++.h>

using namespace std;

class A {
    public:
    virtual void func1() {cout <<"A::func1";}
    virtual void func2() {cout <<"A::func2";}
};

class B : public virtual A {
    public:
    void func1() {cout <<"B::func1";}
    void func3();
};

class C : public virtual A {
    public:
    void func1() {cout <<"C::func1";}
    void func4();
};

class D : public B, public C {
    public:
    void func1() {cout <<"D::func1";}
    void func2() {cout<<"D::func2";}
    void func3() {cout<<"D::func3";}
    void func4() {cout<<"D::func4";}
};

int main() {
    A* d = new D();
    d->func1();
    return 0;
}