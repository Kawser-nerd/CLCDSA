s = input().split("T")
x, y = map(int, input().split())
x -= len(s[0])
s.pop(0)

list_yoko = [len(s[i]) for i in range(1, len(s), 2)]
list_tate = [len(s[i]) for i in range(0, len(s), 2)]

if list_yoko == []:
	list_yoko = [0]

if list_tate == []:
	list_tate = [0]
	
set_yoko = {list_yoko[0], -list_yoko[0]}
set_tate = {list_tate[0], -list_tate[0]}

for i in list_yoko[1:]:
	sy = set()
	for j in set_yoko:
		sy |= {j + i, j - i}
	set_yoko = sy

for i in list_tate[1:]:
	st = set()
	for j in set_tate:
		st |= {j + i, j - i}
	set_tate = st

if (x in set_yoko) and (y in set_tate):
	print("Yes")
else:
	print("No")