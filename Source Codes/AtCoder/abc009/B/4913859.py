n=int(input()) 
a=[int(input()) for i in range(n)]
a.sort()
m=a.count(a[-1])
if m==1:
    print(a[-2])
else:
    print(a[-1-m])