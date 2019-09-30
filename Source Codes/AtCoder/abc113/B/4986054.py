N = int(input())
T,A = map(int,input().split())
H = [int(i) for i in input().split()]
for i in range(N):
  H[i] = abs(T - H[i] * 0.006 - A)
print(H.index(min(H))+1)