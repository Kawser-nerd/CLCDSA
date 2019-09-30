N = int(input())
for i in range(N, 1000):
  if i % 111 == 0:
    print(i)
    exit()