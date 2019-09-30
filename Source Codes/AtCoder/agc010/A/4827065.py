n = int(input())
a = map(int, input().split())
cnt = 0
for i in a:
    if i % 2:
        cnt += 1
print("NO" if cnt % 2 else "YES")