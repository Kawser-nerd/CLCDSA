n = int(input())
h = [0 for i in range(n)]
s = [0 for i in range(n)]
for i in range(n):
    h[i], s[i] = map(int, input().split())


def min_point(x):
    array = [(x - h[i]) // s[i] for i in range(n)]
    array.sort()
    for i in range(n):
        if array[i] < i:
            return False
    return True


a = 0
b = 10 ** 20
while b - a > 1:
    c = (a + b) // 2
    if min_point(c):
        b = c
    else:
        a = c

print(b)