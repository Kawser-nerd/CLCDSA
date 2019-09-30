L, X, Y, S, D = map(int, input().split())
ls = []
a = Y - X
b = D - S
if a <= 0:
    if S <= D:
        print(b/(X+Y))
    else:
        print((L+b)/(X+Y))
else:
    if S <= D:
        ls.append(b/(X+Y))
        ls.append((L-b)/a)
        print(min(ls))
    else:
        ls.append(-b/a)
        ls.append((L+b)/(X+Y))
        print(min(ls))