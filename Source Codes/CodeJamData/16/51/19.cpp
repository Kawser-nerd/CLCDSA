#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int tt;
string s;
int n;
char a[20010];
int top;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	cin >> tt;
	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d: ",ii);
		cin >> s;
		n=s.size();
		top=0;
		int ans=0;
		for (int i=0;i<n;++i)
			if (top==0 || a[top-1]!=s[i]) a[top++]=s[i];
			else {
				top--;
				ans+=10;
			} 
		ans+=top/2*5;
		printf("%d\n",ans);
	}
}