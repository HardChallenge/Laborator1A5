#include<iostream>
using namespace std;
struct A {
virtual bool Odd(int x) = 0;
};
struct B : public A {
virtual bool Odd(int x) override { return x % 2 == 0; }
};
struct C : public B {
virtual bool Odd(int x) { return x % 3 == 0; }
};
int main() {
A* a = new C();
printf("%d\n", a->Odd(3));
return 0;
}



