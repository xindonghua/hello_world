������������
����
sizeof(long)>=sizeof(int)>=sizeof(short)
void bool char int long long long float double unsigned 
�з�����������ʱ��ֹ���
�޷������������Ƿ�ֹ������ת
������
float 4�ֽ� 7λ��Ч���� double 8�ֽ� 15����Ч����  long double 16�ֽ� 19����Ч����
���Ʊ�ʾ
float = (pow(-1,sign)+fraction)*pow(2,exponent-127)

void  0�ֽ�
Bool  1�ֽ�
ָ�� * 4/8�ֽ�

ö����:���ɸ������ļ��ϣ����һ������ֻ�м��ֳ���ֵ����ö�����Ϳɶ��Ի�ߺܶ�

Ĭ��4�ֽڴ�С
����ָ��ö������
enum Fruit:long long {
	APPLE = 0x0000000000000001��
	BANANA = 2,
	ORANGE = 3,
};
��������ö�����ͣ�ǿö������ 10.6.2
enum egg{SMALL,MEDIUM,LARGER,XLARGE};
enum class t_shirt{SMALL,MEDIUM,LARGER,XLARGE};
ʹ��ö�������޶�ö����

����ö�ٿ����Զ�����Ϊ���ͣ��罫�丳��int�����������ڱȽϱ��ʽʱ
��ǿö�����Ͳ�����ʽ��ת��Ϊ����
��������
egg one = MEDIUM;
t_shirt rolf = t_shirt::Large;
int king =one  //ok����ʽת��
int king1 = rolf //wrong
if(king<Jumbo) //ok��
if(king1<t_shirt::MEDIUM) //not allowed
��������ʾ����ת��
int Frodo = int(t_shirt::SMALL);
Ĭ������£�C++������ö�ٵĵײ�����Ϊint����Ȼ�����ṩָ������
enum class: short Pizza {SMALL,MEDIUM,LARGER,XLARGE};

union������ĸ���
���еĳ�Ա��ֻ����ȡһ�������Գ�Ա��ƫ�ƶ���0��union��СҪ��֤������ĳ�Ա���� ������

ָ�������
ָ����һ����ַ����ֵ����һ�������ĵ�ַ
int var =20;
int *ip = &var;

�������Ѵ��ڱ�������һ��������ָ��ͬһ���ַ������һ����Ϊ�գ��޷��ı�ָ����󣬱����ڴ���ʱ��ʼ��

����ؼ���
const �̶�ֵ���������ڳ���ִ���ڼ䲻��ı�
constexpr ����ʱ����������ʱ�Ż�����ʱ���ܱ�const��
�������ʽ���ܰ����������û��߶�����
constexpr�����ķ���ֵ������void���ͣ���������������������

typedef ����Ϊһ�����е�����ȡһ���µ�����
volatile �ױ���  ÿ�ζ���Ҫ���ڴ棬�����ǻ�������ȡ�������





