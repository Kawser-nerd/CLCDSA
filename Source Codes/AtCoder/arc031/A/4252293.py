s = list(str(input()))
c = 0
#print(s)
for i in range(int(len(s)/2)):
    if s[i] == s[len(s)-1-i]:
        c += 1
if c == int(len(s)/2):
    print("YES")
else:
    print("NO")