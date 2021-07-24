智能指针unique_ptr shared_ptr  weak_ptr

手动管理动态内存的方式很容易出错
忘记delete内存，导致内存泄露
使用已经释放掉的对象
重复释放同一种内存

C++11开始引入智能指针，可以方便管理内存，与传统指针相比，智能指针负责自动释放所指向的对象
unique_ptr 独占所指向的对象
shared_ptr 允许多个指针指向同一个对象
以及一个weak_ptr伴随类，指向shared_ptr所管理的对象，所有指针都定义在头文件memory中

两种智能指针均支持的操作
构建一个空智能指针  shared_ptr<T> sp   智能指针也是模板，创建时需要指定类型信息T
                    unique_ptr<T> up
将p用作一个条件判断，若p指向一个对象，则为true
*p 解引用 获取p指向的对象
p.get() 返回p中所保存的指针
swap(p,q)   交换p和q中的指针
p.swap(q)

std::shared_ptr<std::string> p1;
if(!p1){
	std::cout<<"empty"<<std::endl;
}

智能指针的其中一个好处是即使程序发生异常，内存也能被回收
智能指针作为局部对象被销毁时会检查资源使用情况，并正确释放

unique_ptr 独占所指向的对象某个时刻只能有一个unqiue_ptr指向一个给定的对象
当unique_ptr销毁时，它所指向的对象也被销毁

make_unique(args)  通过对象参数构造一个unique_ptr智能指针  since C++ 14
unique_ptr<T,D> u2  使用类型为D的可调用对象来释放指针   默认使用delete释放对象
unique_ptr<T,D> u2(d)  使用类型为D的对象d来代替delete

u.release()  u放弃指向的对象的控制权，返回指针，并将u置为空
u.reset()  释放u所指向的对象

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
	assert(!p) //断言成功
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
引入计数的方式管理资源，如果资源的计数值变为0，则释放资源

make_shared(args)  通过对象参数构造一个shared_ptr智能指针
shared_ptr<T> p(q)  p是shared_ptr q的拷贝值，此操作会递增q中的计数器  q中的指针必须转换为T*
p = q    此操作会递减p的引用计数，递增q的引用计数
p.use_count() 返回与p共享对象的智能指针数量，主要用于调试

使用make_unique和make_share的好处

写法更简洁
auto upw1(std::make_unique<Widgt>());
std::unique_ptr<Widgt> upw2(new Widgt);

auto spw1(std::make_shared<Widgt>());
std::shared_ptr<Widgt> spw2(new Widgt);

提升异常安全
如果传递的参数存在函数，可能会导致内存泄露

生产的代码更小，更快
new的方式做两次分配，一次在堆上分配Widget对象，一次分配ControlBlock

make_shared也有不能适用的场景，用户指定deleters，传递初始化列表


weak_ptr
是一种不控制所指向对象生存期的智能指针
它指向一个shared_ptr管理的对象
不会改变绑定的shared_ptr的引用计数
即使有weak_ptr指向对象，对象还是会被释放

weak_ptr<T> w 空weak_ptr可以指向类型T的对象
weak_ptr<T> w(sp) 与shared_ptr sp指向相同的对象的weak_ptr
w=p 赋值后w与p共享对象 p可以是一个weak_ptr，也可以是一个shared_ptr
w.use_count() 与w共享对象的shared_ptr数量
w.expired() 若w.use_count() ==0 返回true
w.lock() 如果expired为true 则返回一个空sp ，否则返回一个指向w对象的sp

