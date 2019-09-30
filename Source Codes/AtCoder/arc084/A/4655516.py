from collections import defaultdict
A = defaultdict(int)
B = defaultdict(int)
C = defaultdict(int)

N = int(input())
a = [k for k in map(int, input().split())]
b = [k for k in map(int, input().split())]
c = [k for k in map(int, input().split())]

for k in range(N):
  A[a[k]] += 1
  B[b[k]] += 1
  C[c[k]] += 1

Aset = sorted(set(a))
Bset = sorted(set(b))
Cset = sorted(set(c))

cnt = 0
index_a = 0
index_c = 0
a = 0
c = N

for b in Bset:
  flag_a = False
  flag_c = False
  if a < N:
    for k in range(index_a, len(Aset)):
      if Aset[k] < b:
        a += A[Aset[k]] 
      else:
        index_a = k
        flag_a = True
        break
  for k in range(index_c, len(Cset)):
    if Cset[k] <= b:
      c -= C[Cset[k]]
    else:
      index_c = k
      flag_c = True
      break
  if flag_a == False:
    a = N
  if flag_c == False:
    break
  cnt += a*c*B[b]
print(cnt)