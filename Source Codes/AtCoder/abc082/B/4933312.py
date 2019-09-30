s = input()
t = input()
#s_sorted = "".join(sorted(s))
#t_sorted = "".join(sorted(t,reverse=True))
s_sorted = sorted(s)
t_sorted = sorted(t,reverse=True)

if s_sorted < t_sorted:
    print("Yes")
else:
    print("No")