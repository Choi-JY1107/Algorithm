#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coor{
	int x;
	int y;
};
vector < coor > coors;
vector < int > convex;

long long ccw(coor a, coor b, coor c) {
	int x1 = a.x;
	int y1 = a.y;
	int x2 = b.x;
	int y2 = b.y;
	int x3 = c.x;
	int y3 = c.y;
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}
bool init(coor a, coor b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool compare(coor a, coor b){
	return ccw(coors[0], a, b) > 0;
}

void findAns(int nowIndex){
	if(nowIndex == coors.size()) return;
	
	while(convex.size() > 1 && ccw(coors[convex[convex.size()-2]], 
								   coors[convex[convex.size()-1]],
								   coors[nowIndex]) <= 0)
		convex.pop_back();
		
	convex.push_back(nowIndex);
	findAns(nowIndex+1);
	
}
int main() {
	int n;
	coor temp;
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp.x >> temp.y;
		coors.push_back(temp);
	}
	
	sort(coors.begin(), coors.end(), init);
	convex.push_back(0);
	sort(coors.begin() + 1, coors.end(), compare);
	convex.push_back(1);
	findAns(2);
	/*
	for(int i = 0; i<convex.size(); i++)
		cout << "볼록 껍질 꼭짓점 좌표 : " << coors[convex[i]].x << ", " << coors[convex[i]].y << endl;*/
	cout << convex.size() << endl;
	
	return 0;
}
