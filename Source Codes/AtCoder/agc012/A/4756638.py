N = int(input())
A = list(map(int,input().split()))
     
A.sort(reverse = True)
B = A[1::2]
c = 0

for i in range(N):
  c += B[i]

print(c)