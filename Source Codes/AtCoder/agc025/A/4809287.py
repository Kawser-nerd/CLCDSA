n = int(input())
c = 100000000000000000
for i in range(1,int(n/2)+2):
    a = list(str(i))
    b = list(str(n-i))
    a1 = [int(s) for s in a]
    b1 = [int(s) for s in b]
    if sum(a1) + sum(b1) < c:
        c = sum(a1) + sum(b1)

print(c)