N,a = map(int,input().split())
k = int(input())
b = list(map(int,input().split()))
d = {}
for i in range(N):
    d[i+1] = b[i]

c = [-1]*(N+1)

w = a
i = 0
while k > 0:
    if c[w] != -1:
        start = c[w]
        end = i
        k %= (end-start)
        break
    else:
        c[w]=i
    w = d[w]
    k -= 1
    i+=1
while k > 0:
    w = d[w]
    k -= 1
print(w)