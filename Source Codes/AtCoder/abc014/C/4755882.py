n = int(input())
x = [0]*1000002
for i in range(n):
    l,r = map(int,input().split())
    x[l],x[r+1] = x[l]+1,x[r+1]-1
for i in range(1,len(x)):
    x[i] += x[i-1]
print(max(x))