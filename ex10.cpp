�������

1��ʲô���ࣿ

�������ı��˼�뽫������Ƶ��ص�ӳ�������еĹ��̡����輰��ֽ����ϣ�ת���˷������������ݵ����Ժ����ݵĲ�����
��ʹ��C++����ǿ�����ݵĳ������ơ�

�������һ���û��Զ���Ĺ������ݵĳ������ϣ��������˳����еĻ��������Լ������ݵķ��ʺͲ�����
����Ļ����Ͽ���ͨ���������ݶ������Ϻ����ݶ�������Ϣ���������������Ӧ�ó�������ʵ�ֹ�����Ŀ�ꡣ

����ͨ�õ��뵼����ʵҲ��������

2.�������ʵ�ֳ��󣬷�װ���������ء�

��Ķ��屾�����Ƕ����ݵ�һ�ֳ�����̣����ֳ���һ����Ѹ��ӵ����ݽṹ�ֽ�Ϊ�����������͵���ϣ�һ���涨���ʵ���˶Ը����������͵Ĳ�����
��ˣ���Ķ�����ǰѳ����е����ݻ�ԭ��һ�ֻ�������ģ�ͺ���Ӧ������ʽ�ĳ��󻯹��̡�
C++�������������������3�ֻ������ʿ���public��private��protected���������ݷ�װ��
������ⲿ�޷�������Ļ������ݣ���ֻ��ͨ����Ķ���ʵ������ڵĹ��г�Ա���ܹ����ʣ��������ʵ���˻������������غͷ�װ��

3.�������֮��Ĺ�ϵ��ʲô��

�������ĳ�������У�����һ�����ݼ��������ģ�Ͷ��壬Ҳ����һ�����ݵĳ���
ͨ������������ܶ����ʵ�壬ͬһ�������ɵ�ÿһ������ʵ�嶼�ܹ��ڴ洢�ռ���ӵ���Լ��Ĵ洢�ռ䵥Ԫ��ʵ�ֶ����ݵĴ洢�ͷ��ʲ�����
��˿�����Ϊ���ǳ���ģ�ͣ�������������������ݳ���ģ��ʵ����֮�󴴽�����ʵ���ݵ�Ԫ��

4.��ĳ�Ա������������ݳ�Ա֮����ɶ��ͬ��
���ȣ���Ա�����Ǻ����������ݳ�Ա�ǻ������ݡ��������Ͽ���������ݳ�Ա������������Ļ������ݹ��ɣ������˴洢�ռ�����ͣ���������Ա������Ĳ������ܶ��塣
�Ӵ洢�Ͽ�������������ÿ���¶������Լ��Ĵ洢�ռ䣬������ݳ�Ա��ÿһ�������������ģ���̬��Ա�������⣩��
��ͬһ��������ж�����ͬһ�麯����Ա��ÿ�ַ����������ж���ֻ��һ��������

5.�����˻���

class BankAccount{
	public:
	
	BankAccount();
	BankAccount(const string name, const string id,double deposit);
	~BankAccount();
	void show() const{};
	void initAcount(const string name,const string id, double deposit);
	void save(const &saving){};
	void getout(const &saving){};
		
	
	private:
		string accountName_;
		string account_;
		double savings_;
};

6.��Ĺ��캯��ʲôʱ�򱻵��ã����������أ�
���캯�����ഴ������ʱ�����ã�������ʼ�������ڸ����ݳ�Ա��ͨ���������������������һ����ֱ�Ӵ�������һ����ͨ��new����������
��������������Զ����ù��캯�������������Ƕ����ڱ����٣��ڱ�����ʱ�Զ����õġ�Ҳ�����������һ���Ǹñ����ڳ����������ڱ��Զ����ա�
��һ�о��Ƕ�̬����ͨ��delete�����Զ���������������

10��this��*this��ʾʲô

C++����Ķ��������ʹ��һ�������ָ��this����ָ����ָ���и��ഴ���Ķ�������ָ�롣��ָ��ָ�������ʵ���ָ�룬����������ࡣ
Ҳ����˵��this��������ÿһ�����������ĵ�ַ����*this,��������ַ�����ã����Ƕ�����������Ķ�������У�����ͨ��thisָ��
���ó�Ա�����Ķ���this��Ȼ����Ķ�����ʹ�ã��������������������ɶ���ʱ���ھ�������ָ�롣

