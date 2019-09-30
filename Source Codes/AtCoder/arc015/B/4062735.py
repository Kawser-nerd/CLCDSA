n = int(input())

res = [0]*6
for i in range(n):
    x,y = map(float,input().split())
    if x >= 35:
        res[0]+=1
    elif x >= 30:
        res[1]+=1
    elif x >= 25:
        res[2]+=1
    if y >= 25:
        res[3]+=1
    if y<0 and x >= 0:
        res[4]+=1
    if x<0:
        res[5]+=1

print(res[0],res[1],res[2],res[3],res[4],res[5])