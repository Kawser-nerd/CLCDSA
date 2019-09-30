n = int(input())
sum = 0
bmin = []
for _ in range(n):
    a, b = map(int,input().split())
    sum += a
    if a > b:
        bmin.append(b)
if len(bmin)==0:
    print(0)
else:
    print(sum - min(bmin))