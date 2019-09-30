n,v1,v2,l=map(int, input().split())
for i in range(n):
    time=l/v1
    l=v2*time
    if l<=1e-6:l=0
print(l)