n, x = map(int, input().split())

if x == 1 or x == 2*n-1:
  print('No')
else:
  print('Yes')
  if n == 2:
    print(*[1,2,3], sep='\n')
  elif x == 2:
    ans = [3, 2, 1, 4]
    remain = [i for i in range(5, 2*n)]
    ans = remain[:len(remain) // 2] + ans + remain[len(remain) // 2:]
    print(*ans, sep='\n')
  else:
    ans = [x-1, x, x+1, x-2]
    remain = [i for i in range(1, x-2)] + [i for i in range(x+2, 2*n)]
    ans = remain[:len(remain) // 2] + ans + remain[len(remain) // 2:]
    print(*ans, sep='\n')