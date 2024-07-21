#include<bits/stdc++.h>
using namespace std;
int n,a[100],c[100],dcx[200],dcn[200];
int cnt;
void Try(int i){
    for(int j=1;j<=n;j++)
        {
            if(c[j]==0&&dcx[i-j+n]==0&&dcn[i+j-1]==0)
                {
                    a[i]=j;
                    c[j]=1;
                    dcx[i-j+n]=1;
                    dcn[i+j-1]=1;
                    if(i==n)
                        {
                            cnt++;
                            
                        }
                    else Try(i+1);
                    c[j]=0;
                    dcx[i-j+n]=0;
                    dcn[i+j-1]=0;
                }
        }
}

int main(){
    cin>>n;
    Try(1);
    cout<<cnt;
}