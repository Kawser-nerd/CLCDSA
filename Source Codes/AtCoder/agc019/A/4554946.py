Q,H,S,D = map(int,input().split())
N = int(input())

a = min(8*Q,4*H,2*S,D)
ans = 0

ans += a * (N//2)
if N % 2 :
    ans += min(4*Q,2*H,S)
print(ans)