dic = {"b":1,"c":1,"d":2,"w":2,"j":3,"t":3,"f":4,"q":4,"g":4,"l":5,"v":5,"s":6,"x":6,"m":7,"p":7,"h":8,"k":8,"g":9,"n":9,"r":0,"z":0}
vow = ["a","i","o","u","e","y",".",","]
n = int(input())
s = [i.lower() for i in input().split()]
ans = []
for i in range(n):
	ss = ""
	for j in s[i]:
		if j in vow: pass
		else: ss+=str(dic[j])
	if ss: ans.append(ss)
print(" ".join(ans))