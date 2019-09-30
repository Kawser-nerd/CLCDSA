def getGrundyNumber(x):
    ans = 1
    while x % (ans * 2) == 0:
        ans *= 2
    return ans


N, L = map(int, input().split())
Ss = [input() for i in range(N)]

# ?????????
Trie = [[-1, -1]]
for S in Ss:
    iT = 0
    for c in map(int, S):
        if Trie[iT][c] == -1:
            Trie += [[-1, -1]]
            Trie[iT][c] = len(Trie) - 1
        iT = Trie[iT][c]

# ??????????
Hgts = {}
stack = [(0, L + 1)]
while stack:
    iT, Hgt = stack.pop()
    num = 0
    for c in Trie[iT]:
        if c != -1:
            stack.append((c, Hgt - 1))
            num += 1

    if num == 1:
        Hgts[Hgt - 1] = Hgts.get(Hgt - 1, 0) + 1

# Grundy??XOR????
ans = 0
for Hgt, num in Hgts.items():
    if num % 2:
        ans ^= getGrundyNumber(Hgt)

if ans:
    print('Alice')
else:
    print('Bob')