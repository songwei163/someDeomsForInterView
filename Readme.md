散列表的插入、删除、查找的时间复杂度都可以做到常量级的O(1)，非常高效，而二叉查找树在比较平衡的情况下，插入、删除、查找操作时间复杂度才是 O(logn)，相对散列表，好像并没有什么优势，那我们为什么还要用二叉查找树呢？

1. 散列表中的数据是**无序**存储的，如果需要输出有序的数据，需要先排序。对于二叉查找树来说，则只需要进行中序遍历，就可以在O(n)的时间复杂度内，输出有序的数据。
2. 散列表扩容耗时很多，当遇到散列冲突时，**性能不稳定**，尽管二叉查找树的性能不稳定，但在工程中，我们最常用的平衡二叉查找树的性能非常稳定，时间复杂度稳定在O(logn)。
3. 笼统地说，尽管散列表的查找等操作的时间复杂度是常量级的，但因为哈希冲突的存在，这个常量不一定比logn小，所以实际查找的速度可能不一定比O(logn)快，加上哈希函数的耗时，也不一定就比平衡二叉查找树的效率高。
4. 哈希表的构造比二叉查找树要**复杂**，需要考虑的东西很多。比如散列函数的设计、冲突解决办法、扩容、缩容等。平衡二叉查找树只需要考虑平衡性这一个问题，而且这个问题的解决方案比较成熟、固定。

### 进程

#### 程序执行

1. 顺序执行
2. 并发执行

#### 进程的定义

* 进程是程序的一次执行
* 进程是一个程序及其数据再处理机上顺序执行时所发生的活动
* 进程是具有独立功能的程序再一个数据集合上运行的过程，它是系统进行`资源分配`和`调度`的独立单位

#### 进程的特征

* 动态性
* 并发性
* 独立性
* 异步性

#### 进程的基本状态

Ready状态

Running状态

Block状态

创建状态、终止状态

挂起操作的引入

#### 进程控制块PCB

#### 进程同步的基本概念

##### 两种形式的制约关系

- 间接相互制约关系

系统临界资源，互斥访问，统一分配，申请使用

- 直接相互制约关系

多个进程相互合作，引发的同步问题



##### 临界资源

许多硬件资源如打印机、磁带机等，都属于临界资源，诸进程间应采取互斥方式，实现对这种资源的共享。

##### 临界区

无论是硬件临界资源还是软件临界资源，多个进程必须互斥地对它进行访问。人们习惯把每个进程中访问临界资源的那段代码称为临界区

##### 同步机制应遵循的规则

**空闲让进**

当无进程处于临界区时，表示临界资源处于空闲状态，应允许一个请求进入临界区的进程立即进入自己的临界区，以有效地利用临界资源。

**忙则等待**

当已有进程进入临界区时，表明临界资源正在被访问，因而其他试图进入临界区的进程必须等待，以保证对临界资源的互斥访问。