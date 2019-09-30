n = int(input())
s = int(n**0.5)
best = 10**9
for i in range(s, 0, -1):
    q, m = divmod(n, i)
    best = min(best, abs(i-q)+m)
print(best)