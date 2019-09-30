N = int(input())
a = [int(_) for _ in input().split()]
ans = [0]*(10**5+1)

for i in a:
    if i != 0:
        ans[i-1] += 1
        ans[i] += 1
        ans[i+1] += 1
    else:
        ans[i] += 1
        ans[i+1] += 1

print(max(ans))