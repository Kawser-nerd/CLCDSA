n = int(input())
t,a = map(int,input().split())
h = list(map(int,input().split()))
x = []
for i in range(n):
    x.append(abs(t-h[i]*0.006-a))
print(x.index(min(x))+1)