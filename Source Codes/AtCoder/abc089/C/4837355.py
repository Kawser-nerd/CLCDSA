n = int(input())
march = [0] * 5
for i in range(n):
    s = input()
    if s[0] == "M":
        march[0] += 1
    elif s[0] == "A":
        march[1] += 1
    elif s[0] == "R":
        march[2] += 1
    elif s[0] == "C":
        march[3] += 1
    elif s[0] == "H":
        march[4] += 1
P = [0, 0, 0, 0, 0, 0, 1, 1, 1, 2]
Q = [1, 1, 1, 2, 2, 3, 2, 2, 3, 3]
R = [2, 3, 4, 3, 4, 4, 3, 4, 4, 4]
res = 0
for i in range(10):
    res += march[P[i]] * march[Q[i]] * march[R[i]]
print(res)