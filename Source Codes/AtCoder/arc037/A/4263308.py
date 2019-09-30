N = int(input())
m = input().split(" ")
m = [int(i) for i in m]
ans = 0
for i in range(N):
    if m[i] < 80:
        ans += abs(80-m[i])
print(ans)