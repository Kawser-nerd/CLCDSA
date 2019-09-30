n = int(input())
alist = list(map(int, input().split()))

adic = {}
for a in alist:
  if a in adic:
    adic[a] += 1
  else:
    adic[a] = 1

res = sum([v-1 for v in adic.values()])
print(n - res - res%2)