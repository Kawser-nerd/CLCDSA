s=input()
a="AC"
if s[0] != "A":
	a="WA"

cnt=0
for i in range(2, len(s)-1):
	if s[i]=="C":
		cnt+=1

if cnt!=1:
	a="WA"

for i in range(1, len(s)):
	if s[i]!="C" and ord(s[i]) < ord("a"):
		a="WA"

print(a)