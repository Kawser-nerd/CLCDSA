k=[]
for i in range(4):
    l = list(map(int, input().split()))
    k.append(l)
s=0
for i in range(4):
    for j in range(1,4):
        #print(k[i][j-1],k[i][j])
        if k[i][j-1] == k[i][j]:s+=1
for i in range(4):
    for j in range(1,4):
        #print(k[j-1][i],k[j][i])
        if k[j-1][i] == k[j][i]:s+=1
if s >0:
    print("CONTINUE")
else:print("GAMEOVER")