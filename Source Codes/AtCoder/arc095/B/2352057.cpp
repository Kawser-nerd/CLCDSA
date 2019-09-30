#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

double abs1(double a){
   if(a<0.0) return -a;
   return a;
}

int main(){
   ll n, a[100000];
   scanf("%lld", &n);
   for(ll i = 0; i < n; i++) scanf("%lld",&a[i]);
   sort(a, a + n);
   ll ans1 = a[n-1];
   ll ans2 = 100000000000;
   for(ll i = 0; i < n - 1; i++) if(abs1((double)ans2-(double)ans1/2)>abs1((double)a[i]-(double)ans1/2)) ans2 = a[i];
   printf("%lld %lld\n", ans1, ans2);
}