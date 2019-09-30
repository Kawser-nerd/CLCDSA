n = int(input())
h = list(map(int,input().split()))
ans = h[0]
for i in range(len(h)-1):
    if h[i+1]>h[i]:
        ans += h[i+1]-h[i]
print(ans)