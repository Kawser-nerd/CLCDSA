n = int(input())
a = [int(i) for i in input().split()]
cnt = 0
for i in a:
  while i % 3 == 2 or i % 2 == 0:
    i -= 1
    cnt += 1
print(cnt)