�����Ƶ�
auto�ؼ���
auto�ؼ����ܹ��ñ������ڱ����ڼ��Զ��Ƶ�������������
�������ǾͲ����ֶ�ָ���������������͡�
ʹ��auto���͵ı����������ϳ�ʼ�����������������Ϊ����

auto n= 10;
auto f = 12.8;
auto p =&n;

decltyoe�ؼ��� Ҳ��������ʱ�������Ƶ���
//����decltype����һ����ͨ���ʽ��Ϊ����
���ظñ��ʽ�����ͣ���Ƚ�auto��dectype����������ʹ���������Է�����

int i =4;
decltype(i) a;
using size_t = decltype(sizeof(0)) //��usingһ����һ���µ�����
//�����ṹ������ ���¶�����һ�������Ľṹ��
struct {int d;double b;} anon_s;
decltype(anon_s) as;

//��Ϸ��ͱ�̣���ú�������ֵ����
template<typename _Tx, typename _Ty>
auto multioly(_Tx x, _Ty y)->decltype(x*y){return x*y}

decltype�Ƶ�����
decltype(e)�����e��һ��û�д����ŵı�Ƿ����ʽ�������Ա���ʱ��ʽ����ô����e��������ʵ������
���e��һ�������صĺ�������ᵼ�±������
���򣬼���e��������T�����e��һ������ֵ�� ��decltype(e)������ΪT&&
���򣬼���e��������T�����e��һ����ֵ����decltype(e)������ΪT&
���򣬼���e��������T����ôdecltype(e)�ľ���T

int arr[5] ={0};
int *ptr = arr;
int&& RvalvRef();
//����1���Ƶ�Ϊ��ʵ������
decltype(arr) var1 //var1 is int
decltype(ptr) var2 // var 2 is int*
//����2������ֵ���Ƶ�ֵΪ���͵���ֵ����
decltype(RvalvRef()) var5 = 1; //var5 is int&&;

//����3����ֵ���Ƶ�Ϊ���͵�����
decltype(true?i:i) var7 = i; //var7 is int&, �������ʽ������ֵ
decltype(++i) var8 = i; //var8 is int &   ++i�ķ���ֵ��i��i����ֵ

//����4�����϶����ǣ��򷵻ر�����
decltype(1) var9  //var is const int


���������ģ�������Ƶ�
template<typename T>
void f(ParamType param);

���÷�ʽ�� f(expr);
T��ParamType�ǲ�һ���ģ�ParamType���ܰ���const�����û������������η�
���磺
template<typename T>
void f(const T& param);
int x = 0;
f(x);
�����T����int�� ��ParamType��const int&

ģ�������Ƶ���Ϊ�������
���һ�����ParamType��������һ�����ã��������ò��֣�
Ȼ��ʣ�µĲ��־���T��Ȼ��T���β�ƥ��ó�����ParamType
template<typename T>
void f(const T& param);
int x = 27;  //x��������int
const int cx =x; //cx��const int
const int& rx =cx�� //rx��const int&
f(x) //T��int paramType ��int&
f(cx) //T��const int��param��������const int &
f(rx) //T��const int��param��������const int &

����������ParamType��������һ��ͨ������&&��
���expr����ֵ��T��ParamType�����Ƶ�Ϊ��ֵ���ã�
����expr����ֵ����ʹ�����һ�Ĺ���
template<typename T>
void f(const T&& param);
int x = 27;  //x��������int
const int cx =x; //cx��const int
const int& rx =cx�� //rx��const int&
f(x) //T��int& paramType ��int&
f(cx) //T��const int&��param��������const int &
f(rx) //T��const int&��param��������const int &
f(27) //27����ֵ������T��int, param��������int&&

����������ParamType�Ȳ�������Ҳ����ָ��
������ʽexpr��������һ�����ã�����������ò���
����������ú�expr��һ��const���Ǿ��ٺ���const���������volatile����Ҳ�ᱻ����
template<typename T>
void f(const T param);
int x = 27;  //x��������int
const int cx =x; //cx��const int
const int& rx =cx�� //rx��const int&

f(x)  //T��paramType����int
f(cx) //T��paramType����int
f(rx) //T��paramType����int

auto���͵��Ƶ��������ģ�������Ƶ���ʵ���ϣ�auto����ֱ�ӱ�����T����������ʵ��������ParamType

const int N =2 ��
auto x =10 ; // auto�� int  xʵ����int
const auto cx = x // auto��int����������3��ʵ��������const int
const auto& rx = x //���1������Ӧ�ò��� auto��int ʵ���� const int&
auto y=N //���3 ����const auto ��int y��ʵ������Ҳ��int

auto&& y1 =x; //��ֵ���������expr����ֵ����T��ParamType�����Ƶ�Ϊ��ֵ���ã�int&
auto&& y2 =cx; // ͬ�ϣ� int&
auto&& y3 =10; //��ֵ�Ļ����������һ������autoΪint ʵ�������� int&&





