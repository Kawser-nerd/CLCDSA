N=int(input())
A=list(map(int, input().split()))
A.append(0)

prev = 0
l = 0
partial=[]

for i, a in enumerate(A):
  if a > prev:
    prev = a
  else:
    partial.append(i-l)
    l=i
    prev = a
#print(partial)
print(sum([(n+1)*n//2 for n in partial]))