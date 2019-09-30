#include<iostream>
    #include<algorithm>
    using namespace std;
    typedef long long LL;
    LL s[114514];
     
    int main() {
    	LL n, k;
    	cin >> n >> k;
    	int flg = 0;
    	for (int i = 0; i < n; i++) {
    		cin >> s[i];
    		if (!s[i])flg++;
    	}
    	int ans = 0;
    	if (flg)ans = n;
    	else {
    		for (int i = 0; i < n; i++) {
    			int c = 0;
    			LL kk = 1;
    			if (ans + i > n)break;
    			for (int j = i; j < n; j++) {
    				kk *= s[j];
    				if (kk > k)break;
    				c++;
    			}
    			ans = max(c, ans);
    		}
    	}
    	cout << ans << endl;
    	getchar();
    	getchar();
    	return 0;
    }