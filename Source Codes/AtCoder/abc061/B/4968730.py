n,m = map(int,input().split())
a = [0]*n

for i in range(m):
    b,c = map(int, input().split())
    a[b-1]+=1
    a[c-1]+=1

for i in a:
    print(i)