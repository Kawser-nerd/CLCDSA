n = int(input())
als = []
bls = []
for i in range(n):
    a, b = map(int, input().split())
    als.append(a)
    bls.append(b)
als.sort()
bls.sort()
als.append(1000001)
bls.append(1000001)
ai, bi, current = 0, 0, 0
lis = []
for i in range(n*2):
    if(als[ai] <= bls[bi]):
        current+=1
        ai += 1
    else:
        current-=1
        bi +=1
    lis.append(current)
print(max(lis))