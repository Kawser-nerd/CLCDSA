a = int(input())
x = list(map(int, input().split()))

x.sort()
x = x[::-1]
k = []
t = x[0]
for i in range(1,a):
    if t == x[i]:
        k.append(x[i])
        t = 0
    else:t = x[i]
if len(k)>=2:
    print(k[0]*k[1])
else:print(0)