n=int(input())
a=list(map(int,input().split()))
a.append(0)


sums = abs(a[0])
flags = [0 for _ in range(n+1)]

for i in range(1,n+1):
    sums += abs(a[i]-a[i-1])

a.insert(0,0)

for i in range(1,len(a)-1):
    print(sums+abs(a[i+1]-a[i-1])-(abs(a[i+1]-a[i])+abs(a[i]-a[i-1])))