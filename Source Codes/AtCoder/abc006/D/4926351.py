from bisect import bisect_left
N = int(input())
c = [int(input()) for i in range(N)]
r = 0
x = [c[0]]
for i in c:
    if i > x[r]:
        x.append(i)
        r += 1
    else:
        x[bisect_left(x,i)]=i
        
print(N-(r+1))