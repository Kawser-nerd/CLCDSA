N = int(input())

for i in range(7):
  if 2**i <= N < 2**(i+1):
    print(2**i)