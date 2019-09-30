from collections import deque
n,k = map(int,input().split())
a = [int(input())-k for i in range(n)]
rui = [0]*(n+1)
for i in range(n):
    rui[i+1] = rui[i] + a[i]
import bisect
def press(a):
    n = len(a)
    b = set(a)
    b = list(b)
    b.sort()
    c = [0] * n
    for i in range(n):
        c[i] = bisect.bisect_left(b,a[i])
    return b,c
b,c = press(rui)
class BIT:
    def __init__(self, node_size):
        self._node = node_size+1
        self.bit = [0]*self._node

    def add(self, index, add_val):
        while index < self._node:
            self.bit[index] += add_val
            index += index & -index

    def sum(self, index):
        res = 0
        while index > 0:
            res += self.bit[index]
            index -= index & -index
        return res
bit = BIT(n+2)
ans = 0
for i in c:
    ans += bit.sum(i+1)
    bit.add(i+1,1)
print(ans)