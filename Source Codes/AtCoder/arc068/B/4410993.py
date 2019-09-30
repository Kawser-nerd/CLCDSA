n = int(input())
a = list(map(int,input().split()))
d = {}
for i in a:
    d[i] = d.get(i,0)+1
k = len(d)
k -= (sum(d.values()) - k) % 2
print(k)