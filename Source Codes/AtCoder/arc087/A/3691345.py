import collections 
def inpl(): return [int(i) for i in input().split()]

N= int(input())
A = collections.Counter(inpl())
ans = 0
for i in A.keys():
    if i > A[i]:
        ans += A[i]
    else:
        ans += A[i] - i
print(ans)