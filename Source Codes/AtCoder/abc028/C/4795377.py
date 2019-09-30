num = [int(_) for _ in input().split()]
ans = []


for i in range(3):
    for j in range(i+1, 4):
        for k in range(j+1, 5):
            ans.append(num[i]+num[j]+num[k])

ans = sorted(list(set(ans)))
print(ans[-3])