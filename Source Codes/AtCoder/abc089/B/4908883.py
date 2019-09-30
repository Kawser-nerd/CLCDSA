N = input()
S = list(set(list(input().split())))
ans = len(S)
if (ans == 3):
    print("Three")
else:
    print("Four")