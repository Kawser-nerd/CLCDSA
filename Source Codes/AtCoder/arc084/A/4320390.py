import bisect
N = int(input())
J = list(map(int,input().split()))
K = list(map(int,input().split()))
L = list(map(int,input().split()))
J.sort()
K.sort()
L.sort()
S = 0
for i in range(N):
  k = bisect.bisect_left(J,K[i])
  l = N - bisect.bisect_right(L,K[i])  
  S += k*l
print(S)