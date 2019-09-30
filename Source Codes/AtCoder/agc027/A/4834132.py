N,x = (list(map(int,input().split())))
a = (list(map(int,input().split())))
a.sort()
out = 0
for i in a:
    if x>=i:
        x-=i
        out +=1
    else:
        break
else:
    if x != 0:
        out -=1
print(out)