����leetcode�ܽ�0605
1����������λ��
��Ҫ�˽��˶��ַ����ص㣬�ص����ڶԱ߽�ֵ��ȷ��
�߽�ֵ��ȷ����Ҫ��left middle rigth ��1 �Լ�����Ŀ���

һ����ԣ��������Ŀ��������Կ����������������Կ��Ƕ���
int left =0;
int right = vector.size()-1;
int middle = left + (right-left)/2;��Ȼ��ʱ��������Ϊʲô�ܷ�ֹ���
while(left<=right){
	�����������ж�
} Ϊʲô��С�ڵ��ڣ�����Ϊ��left����rightʱ����������Ч��

2��ѧϰ�˹�ϣ���ʹ�ã���leetcode��һ�⣬���Ƿ��ظ����ٵ�����֮��
��ϣ��
��leetcode��һ���ǲ���unordered_map ��unordered_set ʵ�֣�ͨ��Ӧ���ڲ鿴Ԫ���Ƿ��ظ�ʱ������ʹ�㷨��ʱ�临�Ӷȵõ��Ż�

unordered_map <int,int> m; map��Ҫȷ��key��valueֵ
if(m.find(value)!=m.end()){
	//������Ӧ����
}
	m[key]=value;
	
unordered_set<int> s;
if(s.find(value)=s.end()){
	������Ӧ����
}
s.insert(value);
3����̨�����⣬��̬�滮�����ܽ�
�ݹ��ʱ̫����������Ҫ�ᵼ��ʱ�䳬�����ƣ�
������Ҫʹ�ö�̬�滮����̬�滮�ҵ����ĵĹ�ʽ��Ȼ����Ҫ��ֹ���ӷ�ʱ���ݵ������
	