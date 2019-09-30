n=int(input())
t=[int(input()) for i in range(n)]
t.sort(reverse=True)
yaki1=0
yaki2=0
for i in t:
    if yaki1<=yaki2:
        yaki1+=i
    else:
        yaki2+=i
print(max(yaki1,yaki2))