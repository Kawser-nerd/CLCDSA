N = int(input())
ans = 1
for i in range(1,N+1):
  a = i % (10 ** 9 + 7)
  ans *= a
  ans = ans % (10 ** 9 + 7)
print(ans)