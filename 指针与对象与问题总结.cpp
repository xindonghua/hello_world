指针和对象

使用常规表示法来声明指向对象的指针
String *glamour;
可以将指针初始化为指向已有对象
String *first = &sayings[0]；
可以使用new来初始化指针，创建一个新的对象
String *favorite = new String(sayings[choice]);

对类使用new将调用现象应的类构造函数来初始化新创建的对象：
String *gleep = new String;//调用默认构造函数
String *glop = new String("mymymy");//调用有参构造函数
String *favorite = new String(sayings[choice]) //调用复制构造函数

当使用new定位运算符用于创建类对象时，必须显示的调用析构函数

1.
class String
{
private:
	char *str;   //私有数据是字符指针str，所以在创建对象时必须通过构造函数对字符指针进行动态初始化
	int len;
	String();
	~String();
}

String::String(){}   //默认函数可让str初始化为空指针 String(str=nullptr)

String::String(cosnt char *s)
{
	str = s;           //只是将str指向s，这样就是浅拷贝，会造成内存重复删除问题
	len =strlen(s);
}

String::String(cosnt char *s)
{
	strcpy(str,s);    //str都没有明确的指向确定的存储单元，会造不安全 应该先为str动态申请内存空间
	len = strlen(s);
}

正确的
String::String(cosnt char *s)
{
	len = strlen(s);
	str = new char[len+1];
	strcpy(str,s);
}

2.
类内数据成员使用new进行动态存储管理可能出现3个问题，对象销毁，复制构造和赋值。
首先，使用new进行动态存储，对象在生命周期外被销毁后，对象的成员指针指向的数据单元可能还保留在内存中
造成内存泄露。其次就是复制构造函数和赋值构造函数存在的浅拷贝问题。


3.
默认生成 默认构造函数， 析构函数，复制构造函数，赋值构造函数，后两者是浅拷贝。
还有地址运算符。隐式地址运算符返回调用对象的地址，即this指针的值

4.

