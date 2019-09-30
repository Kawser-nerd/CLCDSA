import collections as col
s = list(input())
t = list(input())
s_1 = col.Counter(s)
t_1 = col.Counter(t)
s_2 = sorted(s_1.values())
t_2 = sorted(t_1.values())
if s_2 == t_2:
    print("Yes")
else:
    print("No")