// 回溯法+双端队列：
// 1.迷宫问题经典解法就是回溯
// 2.本题还要应用双端队列deque的原因在于：
  // a)寻找最短的路径，那肯定有的路径不合适，需要将新入队的不合适节点（队尾）退出；
    // 用queue并不能退出队尾元素，所以queue不合适；
    // 用stack是能退出栈顶元素，但是结果出来后，因为遵循先入后出，要是直接打印，将
    // 会是从终点到起点的最短路径，与答案的顺序刚好相反，需要额外操作才能输出正确
  // b)而使用双端队列就会简单很多，不合适的节点直接pop_back()即可。输出结果时仅需
    // push_front()即可。既有栈的特点，又有队的特点。何乐而不为？
// 该题思路：
// 1.四个方向，上下左右提前定义好
// 2.接下来就是回溯常规套路
  // a）到达终点，与现有结果比长短，短则更新，长则抛弃
  // b）四个方向去继续回溯，要进行剪枝，更新标志数组vis,不走重复道路
// 3.得到结果，打印即可
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
// class类的使用
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
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//右下左上 很关键，定义如何进行搜索
    if(x==m-1&&y==n-1){ 
        if(ans.empty()||dq.size()<ans.size()){ //在到终点值在判定
            ans=dq;
        }
        return;
    }
    for(int i=0;i<4;++i){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx>=m||ny>=n||nx<0||ny<0||map[nx][ny]||vis[nx][ny]){
            continue;//索引越界，map[][]=1障碍，或者已经走过的路；
        }
        vis[nx][ny] = true; //记录已经走过的路
        string temp = "("+to_string(nx)+","+to_string(ny)+")";
        dq.push_back(temp);  //在队列中加入
        BackTrack(map, nx, ny, dq, vis); //递归调用
        dq.pop_back();//回退,这个还不是特别理解；dq双端队列中的数据在回溯后要在尾端弹出一次 
						//回溯的用法，回到上一位置，看看还有没有没有走过的符合条件的路
        //看看还有没有其他符合条件的nx，ny；
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