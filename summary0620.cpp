// ���ݷ�+˫�˶��У�
// 1.�Թ����⾭��ⷨ���ǻ���
// 2.���⻹ҪӦ��˫�˶���deque��ԭ�����ڣ�
  // a)Ѱ����̵�·�����ǿ϶��е�·�������ʣ���Ҫ������ӵĲ����ʽڵ㣨��β���˳���
    // ��queue�������˳���βԪ�أ�����queue�����ʣ�
    // ��stack�����˳�ջ��Ԫ�أ����ǽ����������Ϊ��ѭ��������Ҫ��ֱ�Ӵ�ӡ����
    // ���Ǵ��յ㵽�������·������𰸵�˳��պ��෴����Ҫ����������������ȷ
  // b)��ʹ��˫�˶��оͻ�򵥺ܶ࣬�����ʵĽڵ�ֱ��pop_back()���ɡ�������ʱ����
    // push_front()���ɡ�����ջ���ص㣬���жӵ��ص㡣���ֶ���Ϊ��
// ����˼·��
// 1.�ĸ���������������ǰ�����
// 2.���������ǻ��ݳ�����·
  // a�������յ㣬�����н���ȳ��̣�������£���������
  // b���ĸ�����ȥ�������ݣ�Ҫ���м�֦�����±�־����vis,�����ظ���·
// 3.�õ��������ӡ����
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
// class���ʹ��
class Soulution{ 
public:
    void solutionmap(const vector<vector<int>> &map)
{
    m=map.size();
    n=map[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    visited[0][0] = true;
    deque<string> dq;
    dq.push_back("(0,0)");
    BackTrack(map, 0, 0, dq, visited);
    while(!ans.empty()){
        cout<<ans.front()<<endl;
        ans.pop_front();
    }
}

public:
    void BackTrack(const vector<vector<int>> &map,int x,int y,deque<string> &dq,vector<vector<bool>> &vis)
{
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//�������� �ܹؼ���������ν�������
    if(x==m-1&&y==n-1){ 
        if(ans.empty()||dq.size()<ans.size()){ //�ڵ��յ�ֵ���ж�
            ans=dq;
        }
        return;
    }
    for(int i=0;i<4;++i){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx>=m||ny>=n||nx<0||ny<0||map[nx][ny]||vis[nx][ny]){
            continue;//����Խ�磬map[][]=1�ϰ��������Ѿ��߹���·��
        }
        vis[nx][ny] = true; //��¼�Ѿ��߹���·
        string temp = "("+to_string(nx)+","+to_string(ny)+")";
        dq.push_back(temp);  //�ڶ����м���
        BackTrack(map, nx, ny, dq, vis); //�ݹ����
        dq.pop_back();//����,����������ر���⣻dq˫�˶����е������ڻ��ݺ�Ҫ��β�˵���һ�� 
						//���ݵ��÷����ص���һλ�ã���������û��û���߹��ķ���������·
        //��������û����������������nx��ny��
    }
}
private:
    int m;
    int n;
    deque<string> ans;
};

int main(){
    int rows;
    int cols;
    Soulution S;
    int wor;
    while(cin>>rows>>cols){
        vector<vector<int>> map(rows,vector<int>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>map[i][j];
            }
        }
        S.solutionmap(map);
    }
    return 0;
}