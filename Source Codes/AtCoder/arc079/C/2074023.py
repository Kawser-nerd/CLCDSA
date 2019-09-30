N = int(input())
a = list(map(int,input().split()))

ans = 0
while any(map(lambda x: x >= N, a)):
    a.sort(reverse=True)
    k = (a[0] - N)//N + 1
    ans += k
    a[0] -= k*N
    for i in range(1,N):
        a[i] += k

print(ans)