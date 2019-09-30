N = int(input())
t = [int(input()) for _ in range(N)]
ans = 10**10
for i in range(1<<N):
    li1 = []
    li2 = []
    for j in range(N):
        if((i>>j&1)==1):
            li1.append(t[j])
        else:
            li2.append(t[j])
    ans = min(max(sum(li1),sum(li2)),ans)
print(ans)