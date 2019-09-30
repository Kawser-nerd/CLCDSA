import math
N,H = map(int,input().split())
A,B,C,D,E = map(int,input().split())
flag = False
ans = float('inf')
for x in range(N):
    ansx = -1
    ansy = -1
    y = math.ceil((-(B+E)*x/(D+E))+((E*N-H)/(D+E)))
    if y != ((-(B+E)*x/(D+E))+((E*N-H)/(D+E))):
        if y <= 0:
            ansy = 0
            ansx = x
        else:
            if x+y <= N:
                ansy = y
                ansx = x
    else:
         if y <= 0:
            ansy = 1
            ansx = x
         else:
             if x+y <= N-1:
                ansy = y+1
                ansx = x
    if 0 <= ansx+ansy <= N and 0 <= ansx <= N and 0 <= ansy <= N:
        if ans >= A*ansx+C*ansy:
            ans = A*ansx+C*ansy
print(ans)