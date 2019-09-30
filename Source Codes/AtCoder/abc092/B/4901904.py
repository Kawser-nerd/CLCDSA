N=int(input())

D,X =map(int,input().split())
ans =0
for i in range(N):
    A =int(input())
    ans += (D-1)//A +1
print(ans+X)