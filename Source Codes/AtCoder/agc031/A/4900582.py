_,s=open(0);a=1
for i in set(s):a*=s.count(i)+1
print(a//2%(10**9+7)-1)