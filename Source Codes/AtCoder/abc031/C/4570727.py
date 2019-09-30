n = int(input())
a = [int(m) for m in input().split()]
ans = -float("INF")
Aans = -float("INF")
keep = 0
for i in range(n):#T
    for j in range(n):#A
        if i != j:
            if i < j:
                if Aans < sum(a[i + 1:j + 1:2]):
                    Aans = sum(a[i + 1:j + 1:2])
                    keep = j
            else:
                if Aans < sum(a[j + 1:i + 1:2]):
                    Aans = sum(a[j + 1:i + 1:2])
                    keep = j
    if i <= keep:
        ans = max(ans, sum(a[i:keep + 1:2]))
    else:
        ans = max(ans, sum(a[keep:i + 1:2]))
    Aans = -float("INF")
    keep = 0
print(ans)