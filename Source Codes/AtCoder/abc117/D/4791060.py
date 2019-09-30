from collections import defaultdict
N,K = map(int,input().split())
A = list(map(lambda x:bin(int(x))[2:],input().split()))
l = 0
for i in range(N):
    l = max(l,len(A[i]))
count = defaultdict(lambda:0)
for i in range(N):
    for j in range(len(A[i])):
        if A[i][-j-1] == '1':
            count[j] += 1
l = max(count.keys())

def rec(x):
    if x=='':
        return 0
    if '0' not in x:
        res = 0
        for i in range(len(x)):
            res += max(count[i],N-count[i])*2**i
        return res
    if x[0] == '1':
        return max(rec('1'*(len(x)-1))+count[len(x)-1]*2**(len(x)-1),rec(x[1:])+(N-count[len(x)-1])*2**(len(x)-1))
    else:
        return rec(x[1:])+count[len(x)-1]*2**(len(x)-1)
ans = rec(bin(K)[2:])
for i in range(len(bin(K)[2:]),l+1):
    ans += count[i]*2**i
print(ans)