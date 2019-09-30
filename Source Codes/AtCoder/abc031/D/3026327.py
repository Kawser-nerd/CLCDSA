k, n = map(int, input().split())
v, w = ['']*n, ['']*n
for i in range(n):
    v[i], w[i] = input().split()
    v[i] = list(map(lambda x:int(x)-1, list(v[i])))

def parse(pattern):
    ans = ['']*k
    for i in range(n):
        idx = 0
        for x in v[i]:
            l = pattern[x]
            if idx+l > len(w[i]):
                return None
            if ans[x] == '':
                ans[x] = w[i][idx:idx+l]
            else:
                if ans[x] != w[i][idx:idx+l]:
                    return None
            idx += l
        if idx != len(w[i]):
            return None
    return ans


from itertools import product
def solve():
    for x in product(range(1, 4), repeat=k):
        pattern = list(x)
        ans = parse(pattern)
        if ans:
            return ans

for a in solve():
    print(a)