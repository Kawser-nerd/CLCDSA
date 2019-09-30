S = list(input())
T = list(input())
S.sort(reverse=False)
T.sort(reverse=True)
S_sort = "".join(S)
T_sort = "".join(T)

if (S_sort < T_sort):
    print("Yes")
else:
    print("No")