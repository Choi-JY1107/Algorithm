#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int Start, End;
int Arr[5] = {1,2,3,4,5};
vector <int> SegmentTree;

int Make_SegmentTree(int Node, int Start, int End)
{
    if (Start == End) return SegmentTree[Node] = Arr[Start];
    
    int Mid = (Start + End) / 2;
    int Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
    int Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
    SegmentTree[Node] = Left_Result + Right_Result;
 
    return SegmentTree[Node];
}

int Sum(int Node, int Start, int End, int Left, int Right)
{
    if (Left > End || Right < Start) return 0;
    if (Left <= Start && End <= Right) return SegmentTree[Node];
 
    int Mid = (Start + End) / 2;
    int Left_Result = Sum(Node * 2, Start, Mid, Left, Right);
    int Right_Result = Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
    return Left_Result + Right_Result;
}
void Update_SegmentTree(int Node, int Start, int End, int Index, int Diff)
{
    if (Index < Start || Index > End) return;
    SegmentTree[Node] = SegmentTree[Node] + Diff;
 
    if (Start != End)
    {
        int Mid = (Start + End) / 2;
        Update_SegmentTree(Node * 2, Start, Mid, Index, Diff);
        Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, Diff);
    }
}
 
int main(void)
{
  //N 수열의 크기
   int N = 5;
   int Tree_Height = (int)ceil(log2(N));
   int Tree_Size = (1 << (Tree_Height + 1));
  
   SegmentTree.resize(Tree_Size);
  //세그먼트 트리 생성
   Make_SegmentTree(1, 0, N - 1);
  //세그먼트 트리 프린트
  /*
   for(int i=0; i<SegmentTree.size(); ++i)
     cout << SegmentTree[i] << endl;
  */
   
   
   //3부터 5까지 숫자 합
   cout << Sum(1, 0, N - 1, 2, 4) << endl;
   //3번 index를 10으로 바꾸기
   Update_SegmentTree(1, 0, N - 1, 3, 10 - Arr[3]);
   //3부터 5까지 숫자 합
   cout << Sum(1, 0, N - 1, 2, 4) << endl;
}
