N = int(input())
a = [int(_) for _ in input().split()]
num = []

for i, j in enumerate(a, 1):
    num.append([i, j])

num = sorted(num, key = lambda x: -x[1])

for i in num:
    print(i[0])