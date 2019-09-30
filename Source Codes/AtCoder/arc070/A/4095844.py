X = int(input())

ans = 0
pos = 0
while pos < X:
    ans += 1
    pos += ans
print(ans)