N = int(input())
x = [i*100 +i* 10+i for i in range(1, 10)]
for i in x:
  if i >= N:
    print(i)
    break