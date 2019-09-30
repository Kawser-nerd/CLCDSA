N = int(input())
K = int(input())
Xs = sorted(map(int,input().split()))
ans = 0
for x in Xs:
    ans+=min(2*x,2*abs(K-x))
print(ans)