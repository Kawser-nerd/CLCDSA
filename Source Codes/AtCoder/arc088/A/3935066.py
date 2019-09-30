x, y = map(int, input().split())
cnt = 0;
while x <= y:
    cnt += 1
    x *= 2
print(cnt)