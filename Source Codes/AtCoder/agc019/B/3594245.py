import collections
A = input()
Ac = collections.Counter(A)
ans = len(A)*(len(A)-1)//2
for i in Ac.values():
    ans -= i*(i-1)//2

print(ans+1)