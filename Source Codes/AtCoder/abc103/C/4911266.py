N = int(input())
a = [int(x) for x in input().split()]
ans = 0

for i in a:
    ans += i-1

print(ans)