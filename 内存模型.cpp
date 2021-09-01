C++ 11 6种内存相关的枚举值 实际上是4类内存模型
从一致性要求逐渐变弱
Sequential Consistency  memory_order_seq_cst

Acquire-Release   memory_order_acquire  memory_order_release

Release-Consume   memory_order_consume

Relaxed;          memory_order_relaxed

acquire用来修饰一个读操作，表示在本线程中，所有后续的内存操作都必须在本条内存完成后执行

release表示一个写操作，表示在本线程中，所有之前的的内存操作完成后才能执行本条原子操作