运算符重载时一种形式的C++多态。
运算符重载的格式如下
operator op(argument list)

operator+()重载加法运算符
operator*() 重载乘法运算符
op必须是C++有效的运算符。
假设有类对象SalesPerson，重载+号运算符使两个对象的业绩相加。
则
Total = john + oliver

Total = john.opertor+(oliver)  object1.operator+(object2)
该函数实际上隐式调用了john，显式的使用了oliver，前者是调用了方法，后者则使用了参数传递。

一个生动的例子，时间计算，分为小时hours和分钟minutes

int a, b, c;
c= a+b;
Time A,B,C
C=A+B;

t4=t1+t2+t3;

t4= t1.operator+(t2+t3);
t4= t1.operator+(t2.operator+(t3));

运算符重载的概念

重载的运算符不必是成员函数，但至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。
因此，不能将减法运算符-重载为计算两个double的和，而不是他们的差。

使用运算符是不能违反运算符原来的句法规则。例如，不能将求模运算符%重载成一个成使用一个操作数。
也就是说，重载不能改变原来运算符的操作数。

同样，重载不能更改运算符的优先级。不能创建新的运算符。

不能重载的运算符
sizeof . .* :: ?: typeid const_cast dynamic_cast reinterpret_cast static_cast 强制类型转换运算符

下列运算符只能通过成员函数重载，也就是说只能在类中进行重载
=赋值运算符 ()调用运算符 []下标运算符 -> 指针访问运算符


