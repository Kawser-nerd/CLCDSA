#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int tt;
int n,l;
string a[110];
string b;

int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d\n",&n,&l);
		for (int i=0;i<n;++i)
			cin >> a[i];
		cin >> b;
		printf("Case #%d: ",ii);
		bool flag=false;
		for (int i=0;i<n;++i)
			if (b==a[i]) {
				printf("IMPOSSIBLE\n");
				flag=true;
				break;
			}
		if (flag) continue;
	
		for (int i=0;i<l;++i)
			printf("%c?",'0'+((b[i]-'0')^1));
		printf(" ");
		for (int i=0;i<l;++i) {
			char ch='0'+((b[i]-'0')^1);
			printf("%c",ch);
			if (i!=l-1) printf("%c",b[i]);
		}
		printf("\n");
	}
}