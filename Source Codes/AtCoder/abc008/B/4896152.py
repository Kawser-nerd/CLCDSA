import collections
N = int(input())
z1 = []

for i in range(N):
    A = input()
    z1.append(A)

z2 = collections.Counter(z1)
print(z2.most_common()[0][0])