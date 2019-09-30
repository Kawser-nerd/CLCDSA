s = input()
x, y = map(int, input().split())

MoveX, MoveY = [], []
dir = "X"
count = 0
for i in range(len(s)): 
    if s[i] == "T":
        if count:
            if dir == "X": MoveX.append(count)
            else: MoveY.append(count)
        count = 0
        dir = ("Y" if dir == "X" else "X")      
    else:
        count += 1
if s[-1] == "F":
    if dir == "X": MoveX.append(count)
    else: MoveY.append(count)

iniX = 0
if s[0] == "F":
    iniX = MoveX.pop(0)

def DP(i, z, ini, Move = list):
    canMove = set([ini])
    for j in range(i):
        temp = []
        for item in canMove:
            temp.append(item+Move[j])
            temp.append(item-Move[j])
        canMove = set(temp)
    return z in canMove

if DP(len(MoveX), x, iniX, MoveX) and DP(len(MoveY), y, 0, MoveY): print("Yes")
else: print("No")