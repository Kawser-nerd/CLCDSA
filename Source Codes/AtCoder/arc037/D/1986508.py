M = 10 ** 9 + 7
L = int(input())
# let v1, v2, v3 be the distinct vertices at corners
a = 1 # number of polygons
b1 = 1 # number of paths from v1 to v2 which include v3
b2 = 1 # number of paths from v1 to v2 which do not include v3
for i in range(L):
    b = b1 + b2
    d = b * b - b1 * b1
    a, b1, b2 = (3 * a + b * b * b) % M, (b1 * d) % M, (b * b + b2 * d) % M
print(a)