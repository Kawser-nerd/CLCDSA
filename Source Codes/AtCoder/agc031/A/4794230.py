N=int(input())
s=input()

memo=[1]*26

for i in range(N):
    k=ord(s[i])-ord('a')
    memo[k]+=1

ans=1
for i in range(26):
    ans=ans*memo[i]%(1000000007)

print(ans-1)