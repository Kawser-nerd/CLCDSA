n = int(input())
m = list(map(int,input().split()))
res = 0
for i in m:
    if i < 80:
        res += 80 - i
print(res)