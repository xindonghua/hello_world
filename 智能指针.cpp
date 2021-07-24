����ָ��unique_ptr shared_ptr  weak_ptr

�ֶ�����̬�ڴ�ķ�ʽ�����׳���
����delete�ڴ棬�����ڴ�й¶
ʹ���Ѿ��ͷŵ��Ķ���
�ظ��ͷ�ͬһ���ڴ�

C++11��ʼ��������ָ�룬���Է�������ڴ棬�봫ͳָ����ȣ�����ָ�븺���Զ��ͷ���ָ��Ķ���
unique_ptr ��ռ��ָ��Ķ���
shared_ptr ������ָ��ָ��ͬһ������
�Լ�һ��weak_ptr�����ָ࣬��shared_ptr������Ķ�������ָ�붼������ͷ�ļ�memory��

��������ָ���֧�ֵĲ���
����һ��������ָ��  shared_ptr<T> sp   ����ָ��Ҳ��ģ�壬����ʱ��Ҫָ��������ϢT
                    unique_ptr<T> up
��p����һ�������жϣ���pָ��һ��������Ϊtrue
*p ������ ��ȡpָ��Ķ���
p.get() ����p���������ָ��
swap(p,q)   ����p��q�е�ָ��
p.swap(q)

std::shared_ptr<std::string> p1;
if(!p1){
	std::cout<<"empty"<<std::endl;
}

����ָ�������һ���ô��Ǽ�ʹ�������쳣���ڴ�Ҳ�ܱ�����
����ָ����Ϊ�ֲ���������ʱ������Դʹ�����������ȷ�ͷ�

unique_ptr ��ռ��ָ��Ķ���ĳ��ʱ��ֻ����һ��unqiue_ptrָ��һ�������Ķ���
��unique_ptr����ʱ������ָ��Ķ���Ҳ������

make_unique(args)  ͨ�������������һ��unique_ptr����ָ��  since C++ 14
unique_ptr<T,D> u2  ʹ������ΪD�Ŀɵ��ö������ͷ�ָ��   Ĭ��ʹ��delete�ͷŶ���
unique_ptr<T,D> u2(d)  ʹ������ΪD�Ķ���d������delete

u.release()  u����ָ��Ķ���Ŀ���Ȩ������ָ�룬����u��Ϊ��
u.reset()  �ͷ�u��ָ��Ķ���

struct D
{
	D(){};
	~D(){};
	void bar(){};
};

std::unique_ptr<D> pass_through(std::unique_ptr<D>p)
{
	p->bar();
	return p;
}

void close_file(std::FILE* fp){std::fclose(fp)};

int main()
{
	auto p = std::make_unique<D>();
	auto q = pass_through(std::move(p));
	assert(!p) //���Գɹ�
	q->bar();
	
	std::cout<<"Custom Deleter"<<std::endl;
	std::ofstream("demo.txt")<<"x";
	{
		std::unique_ptr<std::FILE, decltype(&close_file)> fp(std::fopen("demo.txt","r"),
																		&close_file);
		if(fp)
		{
			
		}			
	}
}

shared_ptr
��������ķ�ʽ������Դ�������Դ�ļ���ֵ��Ϊ0�����ͷ���Դ

make_shared(args)  ͨ�������������һ��shared_ptr����ָ��
shared_ptr<T> p(q)  p��shared_ptr q�Ŀ���ֵ���˲��������q�еļ�����  q�е�ָ�����ת��ΪT*
p = q    �˲�����ݼ�p�����ü���������q�����ü���
p.use_count() ������p������������ָ����������Ҫ���ڵ���

ʹ��make_unique��make_share�ĺô�

д�������
auto upw1(std::make_unique<Widgt>());
std::unique_ptr<Widgt> upw2(new Widgt);

auto spw1(std::make_shared<Widgt>());
std::shared_ptr<Widgt> spw2(new Widgt);

�����쳣��ȫ
������ݵĲ������ں��������ܻᵼ���ڴ�й¶

�����Ĵ����С������
new�ķ�ʽ�����η��䣬һ���ڶ��Ϸ���Widget����һ�η���ControlBlock

make_sharedҲ�в������õĳ������û�ָ��deleters�����ݳ�ʼ���б�


weak_ptr
��һ�ֲ�������ָ����������ڵ�����ָ��
��ָ��һ��shared_ptr����Ķ���
����ı�󶨵�shared_ptr�����ü���
��ʹ��weak_ptrָ����󣬶����ǻᱻ�ͷ�

weak_ptr<T> w ��weak_ptr����ָ������T�Ķ���
weak_ptr<T> w(sp) ��shared_ptr spָ����ͬ�Ķ����weak_ptr
w=p ��ֵ��w��p������� p������һ��weak_ptr��Ҳ������һ��shared_ptr
w.use_count() ��w��������shared_ptr����
w.expired() ��w.use_count() ==0 ����true
w.lock() ���expiredΪtrue �򷵻�һ����sp �����򷵻�һ��ָ��w�����sp

