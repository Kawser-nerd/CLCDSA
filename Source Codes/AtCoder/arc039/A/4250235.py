A,B = input().split()
C = A.replace(A[0],'9',1)
D = A[:1]+'9'+A[2:]
E = A[:2]+'9'
F = B.replace(B[0],'1',1)
G = B[:1]+'0'+B[2:]
H = B[:2]+'0'
I = [int(A),int(C),int(D),int(E)]
J = [int(B),int(F),int(G),int(H)]
ans = -999
for i in range(4):
  if I[i]-int(B) >= ans:
    ans = I[i]-int(B)
for j in range(4):
  if int(A)-J[j] >= ans:
    ans = int(A)-J[j]
print(ans)