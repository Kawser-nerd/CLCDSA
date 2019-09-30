N = int(input())

L = [list(map(int, input().split())) for _ in range(N)]

res = -1
for l in L:
    tmp = 0
    for i in range(5):
        if i == 4:
            tmp += l[i] * 110 / 900
        else:
            tmp += l[i]
            
    res = max(res, tmp)
    
print(res)