s = input()
t = input()

s_sorted = "".join(sorted(s))
t_sorted = "".join(sorted(t, reverse=True))

print('Yes' if s_sorted < t_sorted else 'No')