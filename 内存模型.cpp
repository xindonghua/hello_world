C++ 11 6种内存相关的枚举值 实际上是4类内存模型
从一致性要求逐渐变弱
Sequential Consistency  memory_order_seq_cst

Acquire-Release   memory_order_acquire  memory_order_release

Release-Consume   memory_order_consume

Relaxed;          memory_order_relaxed