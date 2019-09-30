n = int(input())
h = list(map(int,input().split()))
ans = h[0]
for i in range(1,len(h)):
  if h[i-1] < h[i]:
    ans += (h[i] - h[i-1])

print(ans)