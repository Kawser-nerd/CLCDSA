n = int(input())
a, b, c = [], [], []
for i in range(n):
    ab = list(map(int, input().split()))
    a.append(ab[0])
    b.append(ab[1])
    if(ab[0] > ab[1]):
        c.append(ab[1])
if(len(c) == 0):
    print(0)
else:
    print(sum(a) - min(c))