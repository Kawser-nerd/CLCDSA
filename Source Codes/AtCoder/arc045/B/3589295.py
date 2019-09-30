from operator import itemgetter
N, M = map(int, input().split())
A = []
S = [0] * (N+2)
# imos
for i in range(M):
  L = list(map(int, input().split()))
  A.append(L)
  S[L[0]] += 1
  S[L[1]+1] -= 1

for i in range(1,len(S)):
  S[i] += S[i-1]

# accumSum counts of 0,1

T = [0] * (N+2)
for i in range(1,len(T)):
  T[i] = T[i-1] + (1 if S[i] <= 1 else 0)

#print(S)
#print(T)
#exit(0)
# QueryM
cnt = 0
ANS = []
for i in range(M):
  if T[A[i][0]-1] == T[A[i][1]]:
    #ANS.append(A[i])
    ANS.append(i+1)
    cnt += 1
    
print(cnt)
for i in range(cnt):
  print(ANS[i])
  #print(ANS[i][0], ANS[i][1])