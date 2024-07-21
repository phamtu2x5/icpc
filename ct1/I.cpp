#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define N 1000005
using namespace std;
int kt(string s1,string s2){
	if(s1.size()>s2.size())
		return 1;
	if(s1.size()<s2.size())
		return 0;
	if(s1>=s2)
		return 1;
	return 0;
}
string add(string a, string b) {
    if (a.length() < b.length())
        swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string kQ = "";
    int nho = 0;
    for (int  i = 0; i < b.length(); ++i) {
        int tong = (a[i] - '0') + (b[i] - '0') + nho;
        kQ.push_back(tong % 10 + '0');
        nho = tong / 10;
    }
    for (int i = b.length(); i < a.length(); ++i) {
        int tong = (a[i] - '0') + nho;
        kQ.push_back(tong % 10 + '0');
        nho = tong / 10;
    }
    if (nho)
        kQ.push_back(nho+'0');
    reverse(kQ.begin(), kQ.end());
    return kQ;
}
string s1,s2,s,ans="0";
signed main() {
    fastIO
    s1=to_string(INT_MAX);
    s2=to_string(LONG_LONG_MAX);
    while(cin>>s){
    	int i=0;
    	while(i<s.size()){
    	int tmp=0;
    	while(0<=s[i] && s[i]<='9'){
    		tmp=tmp*10+(s[i]-'0');
    		i++;
    		if(i==s.size())
    			break;
    	}
    	if(tmp>0)
    		{
    			string s3=to_string(tmp);
    			if(kt(s3,s1) && kt(s2,s3))
    				ans=add(ans,s3);
    		}
    	i++;
    	}
    }
    cout<<ans;
    return 0;
}
