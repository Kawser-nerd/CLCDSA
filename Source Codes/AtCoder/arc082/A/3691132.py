N = int(input())
def inpl(): return [int(i) for i in input().split()]
ctr = [0 for _ in range(10**5+2)]
a = inpl()
for i in a:
     ctr[i] += 1
subsum = ctr[0] + ctr[1] + ctr[2]
ans = subsum
for i in range(2,10**5+1):
    subsum = subsum - ctr[i-2] + ctr[i+1]
    ans = max(ans, subsum)
print(ans)