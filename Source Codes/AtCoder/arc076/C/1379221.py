def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def rls(): return list(input())
def pli(a): return "".join(list(map(str, a)))


R, C, N = rli()
lis = []
idx = 0
i = 0
for j in range(N):
    x1, y1, x2, y2 = rli()
    if((x1 % R == 0 or y1 % C == 0) and (x2 % R == 0 or y2 % C == 0)):
        i += 1
        for _ in range(2):
            if(y1 == 0):
                lis.append([x1, i])
            elif(x1 == R):
                lis.append([R+y1, i])
            elif(y1 == C):
                lis.append([2*R+C-x1, i])
            elif(x1 == 0):
                lis.append([2*R+2*C-y1, i])
            x1 = x2
            y1 = y2
lis.sort()
stack = []
exist = [False for _ in range(2*i)]
ans = True
for k in range(2*i):
    if(exist[lis[k][1]]):
        if(lis[k][1] != stack.pop()):
            ans = False
            break
        exist[lis[k][1]] = False
    else:
        stack.append(lis[k][1])
        exist[lis[k][1]] = True
if(ans):
    print("YES")
else:
    print("NO")