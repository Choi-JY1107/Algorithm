#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#define PI 3.14159
using namespace std;

struct coor{
	int x;
	int y;
};
struct vertex{
	int index;
	double angle;
};
vector < coor > coors;
stack < vertex > convex;
bool flag;


double findAngle(int now){
	int pre = convex.top().index;
	return atan2(coors.at(now).x - coors.at(pre).x, coors.at(now).y - coors.at(pre).y);
}
bool checkClock(double now){
	double pre = convex.top().angle;
	
	if(pre == 0){
		if(now > 0 && now != PI) return false;
		else return true;
	}
	else if(pre > 0){
		if(pre - PI <= now && pre >= now) return true;
		else return false;
	}
	else{
		if(PI + pre > now && pre < now) return false;
		else return true;
	}
}
bool init(coor a, coor b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool compare(coor a, coor b){
	coor stand = coors.at(0);
	double angle1 = atan2(a.x - stand.x, a.y - stand.y);
	double angle2 = atan2(b.x - stand.x, b.y - stand.y);
	if(angle1 == angle2){
		if(a.x == b.x) return a.y < b.y;
		else return a.x > b.x;
	}
	return angle1 < angle2;
}

void findAns(int nowIndex){
	flag = true;
	if(nowIndex == coors.size()){
		nowIndex = 0;
		flag = false;
	}
	double nowAngle = findAngle(nowIndex);
	
	while(convex.size() > 1 && checkClock(nowAngle)){
		convex.pop();
		nowAngle = findAngle(nowIndex);
	}
	if(flag) {
		convex.push({nowIndex, nowAngle});
		findAns(nowIndex+1);
	}
}
int main() {
	int n, cnt;
	coor temp;
	cin >> n;
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp.x, &temp.y);
		coors.push_back(temp);
	}
	
	sort(coors.begin(), coors.end(), init);
	convex.push({0,(double)(-100)});
	sort(coors.begin() + 1, coors.end(), compare);
	findAns(1);
	
	for(cnt=0;!convex.empty();cnt++,convex.pop()) cout << coors[convex.top().index].x << " " << coors[convex.top().index].y << endl;
	cout << cnt;
	
	return 0;
}
