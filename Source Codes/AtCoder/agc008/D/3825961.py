N = int(input())
X = list(map(int,input().split()))
Y = sorted([(x-1,i+1) for i,x in enumerate(X)])

ans = [None] * (N*N)
must = []
for i,n in Y:
    ans[i] = n
    must += [n]*(n-1)
must.reverse()

used = [0] * (N+1)
free = [1]
for i in range(N*N):
    if ans[i]:
        a = ans[i]
        if used[a] != a-1:
            print('No')
            exit()
        free += [a]*(N-a)
    elif must:
        a = must.pop()
        ans[i] = a
    else:
        if free:
            a = free.pop()
            ans[i] = a
        else:
            print('No')
            exit()
    used[ans[i]] += 1

for i in range(1,N+1):
    if used[i] != N:
        print('No')
        exit()

print('Yes')
print(*ans)