N = int(input())
A = list(map(int, input().split()))

t = A[0]
indices = [0]
seq = [t]
for i in range(1,N):
  if A[i] > t:
    t = A[i]
    indices.append(i)
    seq.append(t)

M = len(seq)
delta = [seq[0]]+[seq[i+1]-seq[i] for i in range(M-1)]

temp = [0]*M
count = [0]*M


from bisect import bisect_left
for a in A:
  p = bisect_left(seq, a)
  count[p] += a - seq[p]
  temp[p] += 1

t = 0
for i in reversed(range(M)):
  t += temp[i]
  temp[i] = t

for i in range(M):
  count[i] += temp[i]*delta[i]

result = [0]*N
for i,c in zip(indices,count):
  result[i] = c

for r in result:
  print(r)