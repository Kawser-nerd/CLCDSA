N = int(input())
A = [int(i) for i in input().split()]

a = [20000*i+1 for i in range(N)]
b = [20000*(N-i) for i in range(N)]

for i in range(N):
  a[A[i]-1] += i

a = [str(i) for i in a]
b = [str(i) for i in b]

print(" ".join(a))
print(" ".join(b))