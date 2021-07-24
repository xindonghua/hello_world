1、 Stonewt & operator*(double n) const
    friend Stonewt& operator*(double n, Stonewt& st){return st*n;}
	假如说在.h头文件中有定义的话，那么是inline内联函数
	所以有inline的不一定是内联函数，而没有inline关键字的可能也是inline内联函数
	
2、友元函数和成员函数之间的区别
	成员函数是类中的成员，成员函数可以访问类的成员。
	友元函数在类中声明，在类外定义，友元函数可以作为访问类成员的另外一种方式。
	友元函数和成员函数在重载运算符上有区别
	
	
3、非成员函数必须是友元才能访问类成员吗？
    类对象也可以访问所有公有的数据接口

4、哪些成员运算符不能重载？
   sizeof typeid  . .* ::  ?static_cast dynamic_cast  const_cast reintepret_cast
   
5、 = () [] ->只能作为成员函数进行重载


6、转换函数的概念