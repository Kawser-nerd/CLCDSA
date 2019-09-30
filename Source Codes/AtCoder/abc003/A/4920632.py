N = float(input())
if N % 2 == 0:
 print(int((N/2+0.5) * 10000))
else:
 print(int((N+1)/2*10000))