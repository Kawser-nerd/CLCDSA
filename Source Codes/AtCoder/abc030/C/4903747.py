N, M = list(map(int, input().split()))
X, Y = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))


ai=0
bi=0
t=0

answer = 0

while ai<len(A) and bi<len(B):
  if A[ai]<t:
    ai+=1
    continue
  if B[bi] < A[ai] + X: #B???
    bi+=1
    continue
  answer +=1
  t = B[bi] + Y
  
print(answer)