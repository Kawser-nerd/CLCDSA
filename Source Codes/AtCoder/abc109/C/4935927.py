N, X = map(int, input().split())
x = list(map(int, input().split()))
x = x + [X]
x.sort()
# ?????
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)
diff = [x[i+1] - x[i] for i in range(N)]
if len(diff) == 1:
    print(diff[0])
    exit()
ans = gcd(diff[0], diff[1])
for i in range(2, N):
    ans = gcd(ans, diff[i])
print(ans)