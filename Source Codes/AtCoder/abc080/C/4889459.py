n = int(input())

bits = []
for i in range(n):
  bit = int(input().replace(" ", ""), 2)
  bits.append(bit)
p = [[int(item) for item in input().split()] for _ in range(n)]

ans = - 10**9
for i in range(1,2**10):
  val = 0
  for j,mise in enumerate(p):
    val += mise[bin(i & bits[j]).count("1")]
  ans = max(ans, val)
print(ans)