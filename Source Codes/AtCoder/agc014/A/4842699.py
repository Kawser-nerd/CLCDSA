a, b, c = map(int, input().split())
if a == b == c and a % 2 == 0:
  print(-1)
else:
  cnt = 0
  while a%2 == b%2 == c%2 ==0:
    a, b, c = (b+c)//2, (a+c)//2, (a+b)//2
    cnt += 1
  print(cnt)