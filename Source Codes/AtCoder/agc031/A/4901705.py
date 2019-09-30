N = input()
S = input()
X = [0 for i in range(26)]
for s in S:
    X[ord(s) - 97] += 1
ret = 1
for x in X:
    ret *= x + 1
print((ret - 1) % (10 ** 9 + 7))