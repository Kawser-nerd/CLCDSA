s = [list(map(int,input().split())) for i in range(3)]
t = []
for i in range(3):
    t.append([s[i][0]-s[i][1],s[i][0]-s[i][2]])
if t[0] == t[1] and t[0] == t[2]:
    print("Yes")
else:
    print("No")