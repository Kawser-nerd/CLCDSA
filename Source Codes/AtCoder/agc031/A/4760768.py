from collections import Counter
n,s=int(input()),input();c=[s[i]for i in range(n)];a=Counter(c);ans=1
for i in a:ans*=a[i]+1
print((ans-1)%(10**9+7))