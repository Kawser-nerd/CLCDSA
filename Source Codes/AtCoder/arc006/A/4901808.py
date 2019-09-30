E = list(map(int, input().split()))
B = int(input())
L = list(map(int, input().split()))
e = set(E)
l = set(L)
res = len(e & l)
if res == 6:
    print(1)
elif res == 5 and B in L:
    print(2)
elif 6 > res >= 3:
    print(8 - res)
else:
    print(0)