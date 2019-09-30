import sys

n,m,x,y = list(map(int, input().split()))

xl = list(map(int, input().split()))
yl = list(map(int, input().split()))

for i in range(x+1, y+1):
    if (max(xl) < i and min(yl) >= i):
        print ("No War")
        sys.exit()

print("War")