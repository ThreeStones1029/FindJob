[TOC]

# C/C++面向对象程序设计
## 第一章：c/c++数据结构
### 1、数据类型分类



### 2、基本数据类型长度

**long double:16个字节** （64位）、12个字节（32位）

float：4个字节

double：8个字节

char：1个字节

int：4个字节

unsigned int：4个字节

可用sizeof()运算符获取类型长度

### 3、枚举类型定义和使用场景

### 4、数据类型定义和赋值

### 5、结构体类型定义和使用场景

### 6、类型转换

### 7、内存对齐

* 第一个成员在于结构体偏移量为0处
* 

内存对齐的原因：

（1）平台的原因

（2）性能原因

## 第二章：程序的控制结构

### 1、程序结构

### 2、结构化程序设计核心思想

### 3、算法的概念

### 4、算法的表示方法

⾃然语⾔、传统流程图、N-S结构化流程图、伪代码、计算机语⾔

### 5、三大基本控制结构

### 6、分支结构语句

### 7、循环结构语句

## 第三章：函数

### 1、函数的定义

### 2、函数的调用

### 3、函数间的参数传递：传值、引用

### 4、lambda表达式

Lambda表达式是C++11引入的一种语法，用于定义匿名函数（即没有名字的函数）。它通常用于需要简短的回调函数或传递给其他函数的情况下。

举例

~~~cpp
template<typename ForwardIt> // ForwardIt是
auto sum(ForwardIt first, ForwardIt last){
    using value_type = std::iter_value_t<ForwardIt>;
    std::size_t num_threads = std::thread::hardware_concurrency();
    std::ptrdiff_t distance = std::distance(first, last);

    if(distance > 1024000){
        // 计算每个线程处理的元素数量
        std::size_t chunk_size = distance / num_threads;
        std::size_t remainder = distance % num_threads;

        // 存储每个线程的结果
        std::vector<value_type> results { num_threads };

        // 存储关联线程的线程对象
        std::vector<std::thread> threads;

        // 创建并启动线程
        auto start = first;
        for (std::size_t i = 0; i < num_threads; ++i) {
            auto end = std::next(start, chunk_size + (i < remainder ? 1 : 0));
            threads.emplace_back([start, end, &results, i] {
                results[i] = std::accumulate(start, end, value_type{});
            });
            start = end; // 开始迭代器不断向前
        }

        // 等待所有线程执行完毕
        for (auto& thread : threads)
            thread.join();

        // 汇总线程的计算结果
        value_type total_sum = std::accumulate(results.begin(), results.end(), value_type{});
        return total_sum;
    }

    value_type total_sum = std::accumulate(first, last, value_type{});
    return total_sum;
}
~~~

一些关键解释：

* ForwardIt：这是模板参数，表示任何类型的前向迭代器。这个函数可以与任何支持前向遍历的迭代器类型一起使用（比如指针或容器的迭代器，如`std::vector`或`std::list`的迭代器）。

* `emplace_back()` 是在向量的末尾“原地”构造元素，避免了不必要的拷贝或移动操作。

## 第四章：面向对象的基本概念

### 1、类与对象的关系

### 2、现实世界实体的抽象

### 3、面向对象三大特征：封装、集成、多态

## 第五章：类和对象

### 1、类的定义

### 2、构造函数

### 3、析构函数



## 第六章：STL

### 1、模板

内联函数：直接嵌入到

**`template <>`**: 这是模板特化的语法

~~~cpp

~~~

函数模板

模板参数是有传递模板

### 2、迭代器

迭代器最重要的思想是容器和算法分离

~~~cpp
std::vector<int> iterot
~~~

### 3、操作符重载

不可以用operator定义新的操作符

## 七、多线程编程



### 7.1.进程实例Ps - A

* Idle (PID = 0)，相当于内核入口main，也是唯一一个不走fork的进程

* Init (PID = 1)：所有应用进程的祖先

* kthreadd(PID=3): 内核线程祖先

### 7.2.进程的终止

终止进程条件：

（1）正常退出

（2）错误退出：业务逻辑异常，主动退出

（3）严重错误：系统错误，必须退出

（4）被其他进程杀死

### 7.3.进程通信

进程通信是指操作系统中，不同进程之间传递信息或数据的机制

管道：半双工、单向

共享内存、信号、

消息队列：客服信号传递信息少、管道只能承载无格式字节流

信号量

套接字

Socket进程通信：基于客户端-服务器模型

### 7.4.多线程的优缺点

（1）优点

* 避免IO阻塞

* 提升效率

* 避免资源浪费

（2）缺点

* 大量线程可能影响性能
* 更多线程需要更多的内存空间
* 程序设计更加复杂，例如线程间的通信，多线程的数据共享
* 线程终止需要考虑对程序运行的影响

### 7.5.thread库

join与detach区别

* join
* detach
* 启动线程后（也就是构造 `std::thread` 对象）我们必须在线程对象的生存期结束之前，即 [`std::thread::~thread`](https://zh.cppreference.com/w/cpp/thread/thread/~thread) 调用之前，决定它的执行策略，是 [`join()`](https://zh.cppreference.com/w/cpp/thread/thread/join)（合并）还是 [`detach()`](https://zh.cppreference.com/w/cpp/thread/thread/detach)（分离）。

### 7.6.线程池、多线程的区别

（1）多线程

* 需要手动创建线程
* 需要管理线程生命周期
* 高开销：频繁创建和销毁线程都会带来较高的系统开销，每次创建线程，操作系统需要为新线程分配资源

（2）线程池

* 预创建线程：线程池在程序启动时或第一次使用时就创建好一定数量的线程，这些线程保持空闲状态，等待任务分配。
* 任务队列：当有新任务时，线程池会将任务放入任务队列中，然后空闲的线程从队列中取出任务执行。任务完成，线程会返回池中，等待下一个任务。
* 低开销：因为线程池中的线程是复用的，避免了频繁线程创建和销毁。

多线程案例

# 网络编程

## 8.1.分层

网络接口层、链路层：网络接口层是TCP/IP协议软件的最底层，负责将二进制转换为数据帧，并进行数据帧的发送和接收，数据帧是网络传输的基本单元

网络层：负责在主机之间的通信中选择数据报的传输路径，即路由。

传输层：负责提供应用程序间的通信服务

应用层：

## 8.2.一些概念

（1）快速重传

依赖于接收端的冗余ACK机制和发送端对冗余ACK的检测

（2）超时重传

依赖发送端的定时器，在定时器超时后触发重传。对网络延迟和超时时间的设置敏感，设置不当可能导致性能下。降。

当网络发生拥堵，需要降低重发速度时，超时重传降低的速度更多。

（3）什么是协议？

（4）TCP和UDP的特点以及区别？

* TCP传输控制协议



* UDP用户数据报协议

## 8.3.

### 8.3.1.字节序

（1）大端序

最高有效位存于最低内存地址处，最低有效位存于最高内存处。

~~~bash
地址 | 内容
---------------
0x00 | 0x12  (最高字节)
0x01 | 0x34
0x02 | 0x56
0x03 | 0x78  (最低字节)
~~~

（2）小端序

最高有效位存于最高内存地址处，最低有效位存于最低内存处。

字节序都是基于字节的。

~~~bash
地址 | 内容
---------------
0x00 | 0x78  (最低字节)
0x01 | 0x56
0x02 | 0x34
0x03 | 0x12  (最高字节)
~~~

（3）如何判断本机是大端序还是小端序？

（4）epoll

epoll是增强版的poll，可以看做event poll，通过红黑树和内核维护的等待队列等结构实现的事件触发等机制实现的高并发，解决了select和poll未能解决的遍历所有fd来查找响应的缺陷，同时可以通过非阻塞IO模式实现更高的服务性能。



# 安卓基础知识



# 操作系统

## 1、操作系统的认识

操作系统是一种软件，但是操作系统是一种非常复杂的软件，操作系统提供几种抽象模型

* 文件：对I/O设备的抽象

* 虚拟内存：对程序储存器的抽象

* 进程：对一个正在运行程序的抽象

* 虚拟机：对整个操作系统的抽象

## 2、计算机硬件

* 运算器：主要的功能对数据和信息进行加工和运算

* 控制器：完成协调和指挥整个计算机系统的操作
  PS：运算器和控制器共同组成CPU

* 存储器：分为主存（内存）和外存

* 输入设备：包括键盘和鼠标

* 输出设备：显示器和打印机等
他们的关系如下：
![](https://cdn.jsdelivr.net/gh/ThreeStones1029/blogimages/img/20240819085114.png)

## 3、进程与线程

## 4、进程间的通信

![](https://cdn.jsdelivr.net/gh/ThreeStones1029/blogimages/img/20240819094945.png)

### 4.1.管道

### 4.2.共享内存

### 4.3.socket套接字通信

# C++性能提高

## 1、指针使用常用陷阱

### 1.1.内存泄漏

内存泄漏是指程序运行过程中动态分配的内存没有被释放或者无法释放，导致这部分内存不能被重新利用，从而逐渐耗尽可用内存的现象。

example

~~~cpp
#include <iostream>

void memoryLeakExample() {
    int* ptr = new int[100]; // 动态分配内存给100个int

    // 程序的其他操作...
    std::cout << "Memory allocated but not freed!" << std::endl;

    // 假设函数结束时我们忘记释放内存
    // delete[] ptr; // 这行代码被遗忘或注释掉
}

int main() {
    while (true) {
        memoryLeakExample(); // 不断调用这个函数，内存泄漏会越来越严重
    }

    return 0;
}
~~~

对于new []一般需要delete[]配对释放内存

### 1.2.悬空指针

#### 1.2.1.定义与示例

悬空指针一般是指一个指针已经指向的内存已经被释放或者不再有效，但指针仍然指向原来的区域，再次访问会导致未定义行为，引发程序崩溃和其他严重错误。

example

~~~cpp
#include <iostream>

void createDanglingPointer() {
    int* ptr = new int(10); // 动态分配内存
    std::cout << "Value: " << *ptr << std::endl; // 打印值：10

    delete ptr; // 释放内存

    // 现在 ptr 是一个悬空指针
    std::cout << "Value after delete: " << *ptr << std::endl; // 未定义行为，可能会崩溃或输出垃圾值
}

int main() {
    createDanglingPointer();
    return 0;
}
~~~

#### 1.2.2.其他常见悬空指针问题

（1）局部变量的使用

~~~cpp
int* createPointer() {
    int localVar = 42;
    return &localVar; // 返回局部变量的地址，局部变量在函数结束时被销毁
}
~~~

函数放回内存被释放，会有悬空指针

（2）删除指针后继续使用

~~~cpp
void example() {
    int* ptr = new int(20);
    delete ptr;
    ptr = nullptr; // 将悬空指针设为 nullptr 可以避免使用
}

~~~

#### 1.2.3.预防悬空指针

（1）指针释放内存后，设置为NULL

（2）使用智能指针

~~~cpp
std::unique_ptr<int> ptr = std::make_unique<int>(30);
// 自动管理内存，无需手动 delete
~~~

### 1.3.野指针



### 1.4.缓存区溢出

## 2、智能指针

智能指针主要分为三种，包含在<memory.h>，智能指针主要解决的问题



### 2.1.unique_ptr



### 2.2.shared_ptr



### 2.3.weak_ptr



## 3、内联函数优化

内联函数在编译阶段直接嵌入函数，消除函数调用的开销



## 4、IO优化



## 5、容器选择优化

set/multiset、红黑树

## 6、









