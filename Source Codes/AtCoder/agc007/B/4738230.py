n = int(input())
x = list(map(int, input().split()))

a = [20001*i for i in range(1,n+1)]
b = [20001*(n+1-i) for i in range(1,n+1)]

for i in range(n):
    b[x[i]-1] += i
    
for x in a:print(x, end=' ')
print()
for x in b:print(x, end=' ')