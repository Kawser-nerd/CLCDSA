O = input()
E = input()
ans = ''
for i in range(len(O)):
	ans += O[i:i+1] + E[i:i+1]
print(ans)