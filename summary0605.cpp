今日leetcode总结0605
1、搜索插入位置
主要了解了二分法的重点，重点在于对边界值的确定
边界值的确定主要是left middle rigth ±1 以及区间的开闭

一般而言，数组的题目，无序可以考虑先有序，有序后可以考虑二分
int left =0;
int right = vector.size()-1;
int middle = left + (right-left)/2;虽然暂时还不明白为什么能防止溢出
while(left<=right){
	进行条件的判断
} 为什么是小于等于，是因为当left等于right时，区间是有效的

2、学习了哈希表的使用，从leetcode第一题，到是否重复，再到四数之和
哈希表
在leetcode中一般是采用unordered_map 或unordered_set 实现，通常应用在查看元素是否重复时，往往使算法的时间复杂度得到优化

unordered_map <int,int> m; map需要确定key和value值
if(m.find(value)!=m.end()){
	//进行相应操作
}
	m[key]=value;
	
unordered_set<int> s;
if(s.find(value)=s.end()){
	进行相应操作
}
s.insert(value);
3、对台阶问题，动态规划做了总结
递归耗时太长，往往需要会导致时间超出限制；
所以需要使用动态规划，动态规划找到核心的公式，然后需要防止做加法时数据的溢出；
	