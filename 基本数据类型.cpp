基本数据类型
整型
sizeof(long)>=sizeof(int)>=sizeof(short)
void bool char int long long long float double unsigned 
有符号整数计算时防止溢出
无符号整数计算是防止发生反转
浮点型
float 4字节 7位有效数字 double 8字节 15个有效数据  long double 16字节 19个有效数据
近似表示
float = (pow(-1,sign)+fraction)*pow(2,exponent-127)

void  0字节
Bool  1字节
指针 * 4/8字节

枚举型:若干个常量的集合，如果一个变量只有几种常量值，用枚举类型可读性会高很多

默认4字节大小
可以指定枚举类型
enum Fruit:long long {
	APPLE = 0x0000000000000001，
	BANANA = 2,
	ORANGE = 3,
};
类作用域枚举类型，强枚举类型 10.6.2
enum egg{SMALL,MEDIUM,LARGER,XLARGE};
enum class t_shirt{SMALL,MEDIUM,LARGER,XLARGE};
使用枚举名来限定枚举量

常规枚举可以自动提升为整型，如将其赋给int变量后者用于比较表达式时
但强枚举类型不能隐式地转换为整型
上述例子
egg one = MEDIUM;
t_shirt rolf = t_shirt::Large;
int king =one  //ok，隐式转换
int king1 = rolf //wrong
if(king<Jumbo) //ok的
if(king1<t_shirt::MEDIUM) //not allowed
但可以显示进行转换
int Frodo = int(t_shirt::SMALL);
默认情况下，C++作用域枚举的底层类型为int，当然可以提供指定类型
enum class: short Pizza {SMALL,MEDIUM,LARGER,XLARGE};

union联合体的概念
所有的成员中只可以取一个，所以成员的偏移都是0，union大小要保证和做大的成员对齐 共用体

指针和引用
指针是一个地址，其值是另一个变量的地址
int var =20;
int *ip = &var;

引用是已存在变量的另一个别名，指向同一块地址，引用一定不为空，无法改变指向对象，必须在创建时初始化

特殊关键字
const 固定值，常量，在程序执行期间不会改变
constexpr 编译时常量，编译时优化运行时性能比const好
常量表达式不能包含函数调用或者对象构造
constexpr函数的返回值不能是void类型，不能声明变量或新类型

typedef 用来为一个已有的类型取一个新的名字
volatile 易变量  每次都需要从内存，而不是缓存来读取这个数据





