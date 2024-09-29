#include <memory>
#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "*";
    }

    ~A() {
        cout << "#";
    }
    unique_ptr<int> p1;
};


int main() {
    shared_ptr<A> pa(new A());
    unique_ptr<A> pb(new A());
    unique_ptr<A> pc = std::move(pb);
}

