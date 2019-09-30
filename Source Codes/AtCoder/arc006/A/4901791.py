E = list(map(int,input().split()))
B = int(input())
L = list(map(int,input().split()))

same = len(set(E) & set(L))
if same == 6:
    print(1)
elif same == 5:
    print(2 if B in L else 3)
elif same == 4:
    print(4)
elif same == 3:
    print(5)
else:
    print(0)