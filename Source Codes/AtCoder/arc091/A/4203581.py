N,M = map(int, input().split())
if N==M==1: print(1)
elif N<=2 and M<=2: print(0)
elif N==2 or M==2: print(0) 
else: print(max(1,N-2)*max(1,M-2))