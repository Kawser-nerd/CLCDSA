N = int(input())
A = list(map(int, input().split()))

l = [0]*(10**5+1)

for i in A:
    l[i] += 1

ans = 0
for a, b, c in zip(l, l[1:], l[2:]):
    ans = max(ans, a+b+c)

print(ans)