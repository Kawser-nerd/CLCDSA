N=int(input())

red=[]
blue=[]

for i in range(N):
    a,b=map(int,input().split())
    red.append((a,b))

for i in range(N):
    c,d=map(int,input().split())
    blue.append((c,d))

red=sorted(red,key=lambda x:-x[1])
blue=sorted(blue,key=lambda x:x[0])

answer=0
for i,b in enumerate(blue):
    for j,r in enumerate(red):
        if r[0]<b[0] and r[1]<b[1]:
            answer+=1
            red.pop(j)
            break

print(answer)