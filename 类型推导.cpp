类型推导
auto关键字
auto关键字能够让编译器在编译期间自动推导出变量的类型
这样我们就不用手动指明变量的数据类型。
使用auto类型的变量必须马上初始化，否则编译器无能为力。

auto n= 10;
auto f = 12.8;
auto p =&n;

decltyoe关键字 也是做编译时的类型推导，
//但是decltype是以一个普通表达式作为参数
返回该表达式的类型，相比较auto，dectype更加灵活，但是使用起来稍显繁琐。

int i =4;
decltype(i) a;
using size_t = decltype(sizeof(0)) //和using一起定义一个新的类型
//匿名结构体重用 重新定义了一个匿名的结构体
struct {int d;double b;} anon_s;
decltype(anon_s) as;

//结合泛型编程，获得函数返回值类型
template<typename _Tx, typename _Ty>
auto multioly(_Tx x, _Ty y)->decltype(x*y){return x*y}

decltype推导规则
decltype(e)，如果e是一个没有带括号的标记符表达式或者类成员访问表达式，那么就是e所命名的实例类型
如果e是一个被重载的函数，则会导致编译错误
否则，假设e的类型是T，如果e是一个将亡值， 则decltype(e)的类型为T&&
否则，假设e的类型是T，如果e是一个左值，则decltype(e)的类型为T&
否则，假设e的类型是T，那么decltype(e)的就是T

int arr[5] ={0};
int *ptr = arr;
int&& RvalvRef();
//规则1，推导为其实体类型
decltype(arr) var1 //var1 is int
decltype(ptr) var2 // var 2 is int*
//规则2，将亡值，推导值为类型的右值引用
decltype(RvalvRef()) var5 = 1; //var5 is int&&;

//规则3，左值，推导为类型的引用
decltype(true?i:i) var7 = i; //var7 is int&, 条件表达式返回左值
decltype(++i) var8 = i; //var8 is int &   ++i的返回值是i，i是左值

//规则4，以上都不是，则返回本类型
decltype(1) var9  //var is const int


其根基都是模板类型推导
template<typename T>
void f(ParamType param);

调用方式： f(expr);
T和ParamType是不一样的，ParamType可能包含const，引用或者其他的修饰符
例如：
template<typename T>
void f(const T& param);
int x = 0;
f(x);
在这里，T就是int， 而ParamType是const int&

模板类型推导分为三种情况
情况一：如果ParamType的类型是一个引用，忽略引用部分，
然后剩下的部分决定T，然后T与形参匹配得出最终ParamType
template<typename T>
void f(const T& param);
int x = 27;  //x的类型是int
const int cx =x; //cx是const int
const int& rx =cx； //rx是const int&
f(x) //T是int paramType 是int&
f(cx) //T是const int，param的类型是const int &
f(rx) //T是const int，param的类型是const int &

情况二：如果ParamType的类型是一个通用引用&&，
如果expr是左值，T和ParamType都会推导为左值引用，
若果expr是右值，就使用情况一的规则
template<typename T>
void f(const T&& param);
int x = 27;  //x的类型是int
const int cx =x; //cx是const int
const int& rx =cx； //rx是const int&
f(x) //T是int& paramType 是int&
f(cx) //T是const int&，param的类型是const int &
f(rx) //T是const int&，param的类型是const int &
f(27) //27是右值，所以T是int, param的类型是int&&

情况三，如果ParamType既不是引用也不是指针
如果表达式expr的类型是一个引用，忽略这个引用部分
如果忽略引用后expr是一个const，那就再忽略const，如果它是volatile，它也会被忽略
template<typename T>
void f(const T param);
int x = 27;  //x的类型是int
const int cx =x; //cx是const int
const int& rx =cx； //rx是const int&

f(x)  //T和paramType都是int
f(cx) //T和paramType都是int
f(rx) //T和paramType都是int

auto类型的推导规则基于模板类型推导，实际上，auto可以直接被看成T，而变量的实际类型是ParamType

const int N =2 ；
auto x =10 ; // auto是 int  x实际是int
const auto cx = x // auto是int，符合情形3，实际类型是const int
const auto& rx = x //情况1，忽略应用部分 auto是int 实际是 const int&
auto y=N //情况3 忽略const auto 是int y是实际类型也是int

auto&& y1 =x; //左值：情况二，expr是左值，则T和ParamType均被推导为左值引用，int&
auto&& y2 =cx; // 同上， int&
auto&& y3 =10; //右值的话，符合情况一，就是auto为int 实例类型是 int&&





