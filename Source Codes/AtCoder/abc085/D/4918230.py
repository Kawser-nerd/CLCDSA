import sys
input = sys.stdin.readline

n, h = map(int, input().split())

a = []
b = []

for _ in range(n):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)

a.sort(reverse=True)
b.sort(reverse=True)
a_max = a[0]

b_nage = [i for i in b if i>a_max]

count = 0
for i in b_nage:
    h -= i
    count += 1
    if h<=0:
        print(count)
        exit()

count += -(-h//a_max)

print(count)