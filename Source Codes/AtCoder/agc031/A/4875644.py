# coding: utf-8
# Your code here!
N = int(input())
S = input()
MOD = 1000000007

ans = 1
for e in set(S):
    cnt = 0
    
    for i in range(N):
        if S[i] == e:
            cnt += 1
    ans *= cnt+1
    
print((ans-1) % MOD)