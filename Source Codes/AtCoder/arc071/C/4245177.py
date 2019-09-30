def getN():
    return int(input())

def getMN():
    a = input().split()
    b = [int(i) for i in a]
    return b[0],b[1]

def getlist():
    a = input().split()
    b = [int(i) for i in a]
    return b

astr = input()
bstr = input()
n = getN()
queries = []
for i in range(n):
    queries.append(getlist())
s1 = 1 if astr[0] == "A" else 2
t1 = 1 if bstr[0] == "A" else 2
s_acc = [0]
t_acc = [0]
tmp = 0
for s in astr:
    if s == "A":
        s_acc.append(s_acc[-1] + 1)
    else:
        s_acc.append(s_acc[-1] + 2)

for s in bstr:
    if s == "A":
        t_acc.append(t_acc[-1] + 1)
    else:
        t_acc.append(t_acc[-1] + 2)


for q in queries:
    x,y,z,w = q

    if (s_acc[y] - s_acc[x-1]) % 3 == (t_acc[w] - t_acc[z-1])%3:
        print("YES")
    else:
        print("NO")