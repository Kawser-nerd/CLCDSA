n = int(input())
t, a = list(map(int, input().split()))
h = list(map(int, input().split()))
av = []
tmp = 0
mp = 999
v = 0

for i in range(n):
  av.append(t - h[i] * 0.006)
  tmp = abs(a - av[i])
  if (tmp < mp) :
    mp = tmp
    v = i + 1

  
print(v)