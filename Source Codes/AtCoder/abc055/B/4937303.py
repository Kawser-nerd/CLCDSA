N = int(input())
pow = 1
for i in range(1, N+1):
  pow = (pow * i) % 1000000007
print(pow)