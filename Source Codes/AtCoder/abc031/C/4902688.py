N = int(input())
al = list(map(int,input().split()))
ans = (-1) * 10 ** 4
# T?i????????????
for i in range(N):
    # A?j????????????
    a = (-1) * 10 ** 4
    ta = -1
    # A???????????????
    for j in range(N):
        if i > j:
            if a < sum(al[j+1:i+1:2]):
                a = sum(al[j+1:i+1:2])
                ta = j
        elif j > i:
            if a < sum(al[i+1:j+1:2]):
                a = sum(al[i+1:j+1:2])
                ta = j
    if i > ta:
        ans = max(ans,sum(al[ta:i+1:2]))
    else:  
        ans = max(ans,sum(al[i:ta+1:2]))
print(ans)