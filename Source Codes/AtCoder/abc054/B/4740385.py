N, M = map(int, input().split())
A,B = [],[]

for i in range(N):
  A.append(input())
for i in range(M):
  B.append(input())

ans = ""
for i in range(N-M+1):
#  print(A[i])
  if B[0] in A[i]:
    ans += "T"
    y = A[i].find(B[0])
#    print("{}???{}???".format(i+1, y+1))
    for j in range(1,M):
      
      if A[i+j][y:y+M] == B[j]:
        ans += "T"
      else:
        ans += "F"
#      print(i, j, ans)

if "T" * M in ans:
  print("Yes")
else:
  print("No")