x = input()
S = list(input())
A = []
x = x[0]
for s in S:
    if s != x:
        A.append(s)

print(*A, sep="")