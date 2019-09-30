l,h=map(int,input().split())
n = int(input())

for i in range(n):
    t=int(input())
    if t<l:
        print(l-t)
    elif l<=t and t<=h:
        print(0)
    else:
        print(-1)