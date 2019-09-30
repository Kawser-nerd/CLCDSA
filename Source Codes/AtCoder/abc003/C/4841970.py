N,K = map(int,input().split())
R = sorted(map(int,input().split()))
C = 0
for i in range(-K,0):C = (C+R[i])/2
print(C)