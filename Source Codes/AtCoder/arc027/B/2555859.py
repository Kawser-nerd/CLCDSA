n = int(input())
uni = [-1 for i in range(10+26)]
def root(a):
    if uni[a] < 0:
        return a
    else:
        uni[a] = root(uni[a])
        return uni[a]

def num_check(a):
    if uni[a] < 0:
        return a
    else:
        uni[a] = root(uni[a])
        return uni[a]

def connect(a, b):
    a, b = root(a), root(b)
    if a == b:
        return False
    if uni[a] > uni[b]:
        a, b = b, a
    uni[a] += uni[b]
    uni[b] = a
    return False

s = []
for i in range(2):
    s.append(list(input()))

for i in range(n):
    for j in range(2):
        if s[j][i].isalpha():
            s[j][i] = ord(s[j][i])-64+9
        else:
            s[j][i] = int(s[j][i])
    connect(s[0][i], s[1][i])


dig_root = []
for i in range(10):
    dig_root.append(root(i))
t = []
for i in range(n):
    t.append(root(s[0][i]))
ini = root(s[0][0])
ans = 1
for i in list(set(t)):
    if i in dig_root:
        ans *= 1
    else:
        if s[0][0] == i:
            ans *= 9
        else:
            ans *= 10
print(ans)