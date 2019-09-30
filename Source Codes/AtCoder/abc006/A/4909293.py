N = input()
numN = int(N)
flag = False
if("3" in N):
    flag = True
if(numN%3==0):
    flag = True

if(flag):
    print("YES")
else:
    print("NO")