import fractions
n = int(input())
t = []
for i in range(n):
    t.append(int(input()))

ans = t[0]
for i in range(1,n):
    ans = ans * t[i] // fractions.gcd(ans, t[i])
print(ans)