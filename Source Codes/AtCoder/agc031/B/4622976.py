n = int(input())
c = [int(input()) for i in range(n)]
num,x = 1,[0]*(200001)
c.append(0)
x[c[0]]+=1
for i in range(1,n):
    if c[i]-c[i-1]: x[c[i]] = (x[c[i]]+num)%(10**9+7)
    if c[i]-c[i+1]: num = x[c[i]]
    else: num = 0
print(num)