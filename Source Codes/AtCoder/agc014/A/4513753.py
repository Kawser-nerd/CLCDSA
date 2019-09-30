a, b, c = map(int, input().split())
cnt = 0
if a == b == c and  a % 2 == 0 and b % 2 == 0 and c % 2 == 0:
    cnt = -1
else:
    while a % 2 == 0 and b % 2 == 0 and c % 2 == 0:
        a, b, c = b // 2 + c // 2, a // 2 + c // 2, a // 2 + b // 2
        cnt += 1
print(cnt)