H,W = map(int,input().split())
A = [input() for _ in range(H)]                                               

c = 0
for a in A:
    c += a.count("#")
if c==H+W-1:
    print("Possible") 
else:
    print("Impossible")