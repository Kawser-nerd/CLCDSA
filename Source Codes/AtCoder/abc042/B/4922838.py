N, L = map(int, input().split())
s = [input() for i in range(N)]
s.sort()
ans = ""
for i in s:
    ans += i
print(ans)