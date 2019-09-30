a, b, c = map(int,input().split())

a_mod_b = a % b

flg = False
while a_mod_b > 0:
	a_mod_b = ( a_mod_b + a ) % b
	if a_mod_b == c :
		flg = True
		break
if flg:
	print("YES")
else:
	print("NO")