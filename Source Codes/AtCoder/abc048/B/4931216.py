a, b, x = map(int, input().split())

c = a//x if a % x != 0 else a//x-1
ans = b//x-c

print(ans)