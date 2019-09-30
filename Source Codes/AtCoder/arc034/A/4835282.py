l=[]
for i in range(int(input())):
    a=list(map(int,input().split()))
    l.append(sum(a[:-1])+110*a[-1]/900)
print(max(l))