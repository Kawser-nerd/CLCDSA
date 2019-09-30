ai = lambda: list(map(int, input().split()))

n = int(input())
a = ai()

ans = 0
start = 0
s = 0
for i in range(n):
    for j in range(start, n):
        if s + a[j] == s ^ a[j]:
            s += a[j]
        else:
            s -= a[i]
            start = j
            ans += j-i
            break
        if j == n-1:
            for k in range(i,n):
                ans += n-k
            print(ans)
            import sys
            sys.exit()
print(ans)