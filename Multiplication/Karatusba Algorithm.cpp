#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void normalize(vector <int> & num){
    num.push_back(0);

    for(int i=0;i+1<num.size();i++){
		if(num[i]<0){
			int borrow = (abs(num[i]) + 9) / 10;
			num[i+1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i+1] += num[i]/10;
			num[i] %= 10;
		}
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b){
    vector<int> c(a.size() + b.size(), 0);
    for(int i=0;i<a.size();++i)
        for(int j=0;j<b.size();++j)
            c[i+j] += a[i] * b[j];
    
    normalize(c);
    return c;
}

void addTo(vector<int> &a, const vector<int>& b, int k){
	for(int i=k;i<a.size();++i)
		a[i] += b[i-k];
	normalize(a);
}

void subFrom(vector<int> &a, const vector<int>& b){
	for(int i=0;i<b.size();++i)
		a[i] -= b[i];
	normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
	int asize = a.size(), bsize = b.size();
	
	if(asize<bsize) return karatsuba(b,a);
	if(asize == 0 || bsize == 0) return vector<int> ();
	if(asize <= 50) return multiply(a,b);
	
	int half = asize/2;
	//a * b = (a0 * 10^half + a1) * (b0 * 10^half + b1)
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	
	//z2 = a1 * b1, z0 = a0 * b0
	vector<int> z2 = karatsuba(a1,b1);
	vector<int> z0 = karatsuba(a0,b0);
	addTo(a0,a1,0);addTo(b0,b1,0);
	vector<int> z1 = karatsuba(a0,b0);
	subFrom(z1,z0);subFrom(z1,z2);
	
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int main(){
    vector <int> a, b, ans;
	
    a = {3,2,1,2,3,4,5,6,7,7,8,9,0,1,2,3,4,5,6,7,8,9,3,1,3,5,1,2,3,5};
    b = {6,5,4,6,5,6,6,3,1,2,3,5,7,0,0,1,5,8,3,1,6,2,6,1,6,9,1,2,5,8};
	
    ans = karatsuba(a,b);
	reverse(ans.begin(), ans.end());

    for(int i=0;i<ans.size();++i)
        cout << ans[i];
	cout << endl;
}
