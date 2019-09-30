N = int(input())
St = [0 for _ in range(N+1)]
for _ in range(N):
   i = int(input()) 
   St[i] = max(St[i-1]+1, 1)
print(N-max(St))