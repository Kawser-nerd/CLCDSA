n = int(input())

cnt1 = 0
cnt2 = 0
cnt4 = 0

for d in map(int,input().split()):
    if d%4==0:
        cnt4+=1
        continue
    if d%2==0:
        cnt2+=1
        continue
    cnt1+=1
res = True
if cnt2>0:
    res = (cnt1<=cnt4)
else:
    res = (cnt1<=(cnt4+1))

if res:
    print("Yes")
else:
    print("No")