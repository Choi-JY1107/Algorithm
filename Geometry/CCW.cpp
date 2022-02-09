#include <iostream>
using namespace std;

int main() {
  cout << "점1, 점2, 점3를 순서대로 이은 선분의 방향성 판별하는 알고리즘" << endl; 
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	
	int temp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(temp > 0) cout << "반시계 방향";
	if(temp < 0) cout << "시계 방향";
	if(temp == 0) cout << "일직선";
	
	return 0;
}
