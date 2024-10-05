#include <iostream>
#include <memory>


// unique_str
// class MyClass {
// public:
//     MyClass() { std::cout << "MyClass constructor" << std::endl; }
//     ~MyClass() { std::cout << "MyClass destructor" << std::endl; }
//     void display() { std::cout << "Displaying MyClass" << std::endl; }
// };

// int main() {
//     std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(); // 创建一个 unique_ptr
//     ptr1->display(); // 使用 unique_ptr

//     std::unique_ptr<MyClass> ptr2 = std::move(ptr1); // 转移所有权
//     if (ptr1 == nullptr) {
//         std::cout << "ptr1 is null after move" << std::endl;
//     }

//     ptr2->display();
//     return 0;
// }


// shared_ptr

// class MyClass {
// public:
//     MyClass() { std::cout << "MyClass constructor" << std::endl; }
//     ~MyClass() { std::cout << "MyClass destructor" << std::endl; }
//     void display() { std::cout << "Displaying MyClass" << std::endl; }
// };

// int main() {
//     std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(); // 创建一个 shared_ptr
//     std::shared_ptr<MyClass> ptr2 = ptr1; // 共享所有权

//     ptr1->display();
//     ptr2->display();

//     std::cout << "Reference count: " << ptr1.use_count() << std::endl; // 引用计数为 2
//     return 0;
// }


// weak_ptr
// class MyClass {
// public:
//     MyClass() { std::cout << "MyClass constructor" << std::endl; }
//     ~MyClass() { std::cout << "MyClass destructor" << std::endl; }
//     void display() { std::cout << "Displaying MyClass" << std::endl; }
// };

// int main() {
//     std::shared_ptr<MyClass> shared = std::make_shared<MyClass>(); // 创建一个 shared_ptr
//     std::weak_ptr<MyClass> weak = shared; // 创建一个 weak_ptr，指向 shared_ptr 的对象

//     if (auto ptr = weak.lock()) { // 使用 lock() 获取 shared_ptr
//         ptr->display();
//     }

//     shared.reset(); // 重置 shared_ptr
//     if (weak.expired()) {
//         std::cout << "The object is no longer available" << std::endl;
//     }

//     return 0;
// }


// 循环引用
using namespace std;

template <typename T>
class Node
{
public:
	Node(const T& value)
		:_pPre(NULL)
		, _pNext(NULL)
		, _value(value)
	{
		cout << "Node()" << endl;
	}
	~Node()
	{
		cout << "~Node()" << endl;
		cout << "this:" << this << endl;
	}

	shared_ptr<Node<T>> _pPre;
	shared_ptr<Node<T>> _pNext;
	T _value;
};

void Funtest()
{
	shared_ptr<Node<int>> sp1(new Node<int>(1));
	shared_ptr<Node<int>> sp2(new Node<int>(2));

	cout << "sp1.use_count:" << sp1.use_count() << endl;
	cout << "sp2.use_count:" << sp2.use_count() << endl;

	sp1->_pNext = sp2; //sp2的引用+1
	sp2->_pPre = sp1; //sp1的引用+1

	cout << "sp1.use_count:" << sp1.use_count() << endl;
	cout << "sp2.use_count:" << sp2.use_count() << endl;
}
int main()
{
	Funtest();
	system("pause");
	return 0;
}
//输出结果
//Node()
//Node()
//sp1.use_count:1
//sp2.use_count:1
//sp1.use_count:2
//sp2.use_count:2

