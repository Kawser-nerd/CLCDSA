c=0
for i in range(int(input())):
    a=list(map(int,input().split()))
    c=max(c,sum(a)-a[4]*790/900)
print(c)