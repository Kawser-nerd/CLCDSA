N = int(input())
b = list(map(int, input().split()))
ans = []
for i in range(N):
    for j in range(len(b) - 1, -1, -1):
        if j + 1 == b[j]:
            ans.append(b.pop(j))
            break
    else:
        print(-1)
        exit()

ans = ans[::-1]
for i in ans:
    print(i)