from collections import Counter
N = int(input())
MODN = int(1e9+7)

T = [0] * 10001

for i in range(N):
  x = int(input())
  T[x] += 1

P = [1] * 10001
for i in range(1,10001):
  P[i] = P[i-1] * i % MODN
  
now_t, acm_t = 0,0
pat_n = 1
for i in range(1,10001):
  if T[i] == 0:
    continue
  acm_t += T[i]*now_t + i*(T[i]*(T[i]+1)//2)
  now_t += i*T[i]
  pat_n = pat_n * P[T[i]] % MODN

print(acm_t)
print(pat_n)