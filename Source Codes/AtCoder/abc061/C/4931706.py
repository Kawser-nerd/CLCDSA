n,k = map(int,input().split())
l = [0]*(10**5+1)
for _ in range(n):
    a,b = map(int,input().split())
    l[a] += b
for i in range(1,len(l)):
    l[i] += l[i-1]
    if k<=l[i]:
        print(i)
        exit()