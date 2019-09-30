N = int(input())
S = list(map(str, input().split()))
kind = len(set(S))
if kind == 3:
    print("Three")
elif kind == 4:
    print("Four")