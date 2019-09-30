E = [int(_) for _ in input().split()]
B = int(input())
L = [int(_) for _ in input().split()]

t = sum(x in E for x in L)
b = B in L

if t == 6:
    result = 1
elif t == 5 and b:
    result = 2
elif t == 5:
    result = 3
elif t == 4:
    result = 4
elif t == 3:
    result = 5
else:
    result = 0

print(result)