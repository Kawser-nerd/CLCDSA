N = int(input())

ans = []
for x in [8, 4, 2, 1]:
    while N >= x and N != 0:
        N -= x
        ans.append(x)

print(len(ans))
for x in ans:
    print(x)