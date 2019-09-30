N = int(input())
a = [int(i) for i in input().split()]
b = set()
for x in a:
    while 1:
        if x%2 == 0:
            x = x//2
        else:
            b.add(x)
            break
print(len(b))