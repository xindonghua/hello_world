类和动态内存分配
动态内存和类  深拷贝和浅拷贝  隐式和显式赋值构造函数 以及只能在成员函数中被重载的赋值运损福 operator = 
让程序在运行时分配内存  配套的使用new 和delete
//定义的时候就不需要关键字了
int StringBad::num_string = 0; //不能在类声明中初始化静态成员变量，静态成员在类声明中声明，在类外定义
//如果静态成员变量是const类型或者枚举类型，则可以在类中初始化

class Barkery{
private:
	enum {Months =12};
	double costs[Months];
}
//使用这种方式并不会创建类的数据成员，所以对象中都不包含枚举，Months只是一个符号名称，符号常量，在类
//的作用域内遇到Months，就用12来代替

class Barkery{
private:
	static const int Months = 12
	double costs[Months];
}
该静态常量与其他静态变量存储在一起，而不是存储在对象中。

析构函数分析
str成员指向new分配的内存，当StringBad对象过期时，str指针也将过期，但str指向的内存仍然被分配
所以要用delete将其释放。删除对象可以释放对象本身所占用的内存，但并不能自动释放属于对象成员的指针指向的内存。

本质是指针也占据一部分内存，是这个意思吗？

深拷贝与浅拷贝

复制构造函数
class_name (const Class_name &);
StringBad (const StringBad&);

StringBad ditto(motto);
StringBad ditto = motto;
StringBad also = StringBad(motto);
SringBad * pstring = new StringBad(motto); 

第一种是显示直接调用复制函数
第二中可能直接使用复制，也可能先使用复制构造函数生成临时对象，在赋值给相应对象
第三种是使用motto声明了一个匿名对象，并将新对象的地址赋给pstring指针

默认复制构造函数是浅拷贝 需要定义一个显示的复制构造函数；

同样的，赋值构造函数也存在浅拷贝问题，需要显式定义重载赋值运算符
SringBad& StringBad::operator=(const StingBad& st);
当然赋值构造函数还需要注意一些其他问题
函数返回一个指向调用对象的引用，链式赋值
避免将对象赋值给自身




