s = ''.join(sorted(list(input())))
t = ''.join(sorted(list(input()),reverse=True))


if  s != t and s == sorted([s,t])[0]:
 print("Yes")
else:
 print("No")