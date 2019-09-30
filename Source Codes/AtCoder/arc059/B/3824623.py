import sys
input = sys.stdin.readline

sys.setrecursionlimit(10000)

S = input()

for i in range(len(S)):
    if i <= len(S) -2:
        if S[i] == S[i+1]:
            print("{} {}".format(i+1,i+2))
            break
    if i <= len(S) -3:
        if S[i] == S[i+2]:
            print("{} {}".format(i+1, i+3))
            break
else:
    print("-1 -1")