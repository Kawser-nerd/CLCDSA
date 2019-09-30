N = int(input())
s = input()
t = input()

if s == t:
    print(N)
else:
    flag = False
    for i in range(1, N):
        if s[i:] == t[:-i]:
            flag = True
            break
    print(N+i if flag else N+N)