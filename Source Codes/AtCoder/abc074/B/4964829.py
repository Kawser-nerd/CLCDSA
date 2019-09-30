n = int(input())
k = int(input())
bo = list(map(int, input().split()))
ans = 0
for b in bo:
    ans += min(b, abs(b-k))
print(ans*2)