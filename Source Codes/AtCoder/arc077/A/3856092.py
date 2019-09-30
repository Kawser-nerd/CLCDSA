a = int(input())
ar = list(map(int,input().split(" ")))
br = []
if a % 2 == 0:
    for i in range(len(ar)-1,0,-2):
        br.append(ar[i])
    for i in range(0,len(ar)-1,+2):
        br.append(ar[i])
else:
    for i in range(len(ar)-1,-1,-2):
        br.append(ar[i])
    for i in range(1,len(ar)-1,+2):
        br.append(ar[i])
for i in range(a-1):
    print(str(br[i]),end = " ")
print(str(br[a-1]))