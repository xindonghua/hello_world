ָ��Ͷ���

ʹ�ó����ʾ��������ָ������ָ��
String *glamour;
���Խ�ָ���ʼ��Ϊָ�����ж���
String *first = &sayings[0]��
����ʹ��new����ʼ��ָ�룬����һ���µĶ���
String *favorite = new String(sayings[choice]);

����ʹ��new����������Ӧ���๹�캯������ʼ���´����Ķ���
String *gleep = new String;//����Ĭ�Ϲ��캯��
String *glop = new String("mymymy");//�����вι��캯��
String *favorite = new String(sayings[choice]) //���ø��ƹ��캯��

��ʹ��new��λ��������ڴ��������ʱ��������ʾ�ĵ�����������

1.
class String
{
private:
	char *str;   //˽���������ַ�ָ��str�������ڴ�������ʱ����ͨ�����캯�����ַ�ָ����ж�̬��ʼ��
	int len;
	String();
	~String();
}

String::String(){}   //Ĭ�Ϻ�������str��ʼ��Ϊ��ָ�� String(str=nullptr)

String::String(cosnt char *s)
{
	str = s;           //ֻ�ǽ�strָ��s����������ǳ������������ڴ��ظ�ɾ������
	len =strlen(s);
}

String::String(cosnt char *s)
{
	strcpy(str,s);    //str��û����ȷ��ָ��ȷ���Ĵ洢��Ԫ�����첻��ȫ Ӧ����Ϊstr��̬�����ڴ�ռ�
	len = strlen(s);
}

��ȷ��
String::String(cosnt char *s)
{
	len = strlen(s);
	str = new char[len+1];
	strcpy(str,s);
}

2.
�������ݳ�Աʹ��new���ж�̬�洢������ܳ���3�����⣬�������٣����ƹ���͸�ֵ��
���ȣ�ʹ��new���ж�̬�洢�����������������ⱻ���ٺ󣬶���ĳ�Աָ��ָ������ݵ�Ԫ���ܻ��������ڴ���
����ڴ�й¶����ξ��Ǹ��ƹ��캯���͸�ֵ���캯�����ڵ�ǳ�������⡣


3.
Ĭ������ Ĭ�Ϲ��캯���� �������������ƹ��캯������ֵ���캯������������ǳ������
���е�ַ���������ʽ��ַ��������ص��ö���ĵ�ַ����thisָ���ֵ

4.

