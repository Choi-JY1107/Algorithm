#include<iostream>
#include<vector>
using namespace std;

void normalize(vector <int> & num){
    num.push_back(0);

    for(int i=0;i+1<num.size();i++){
        num[i+1] += num[i]/10;
        num[i] %= 10;
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

int main(){
    vector <int> a, b, ans;
    a = {3,2,1};
    b = {6,5,4};

    ans = multiply(a,b);

    for(int i=0;i<ans.size();i++)
        cout << ans[i];
}
