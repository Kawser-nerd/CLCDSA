[r,c] = [int(i) for i in input().split()]
[sy,sx] = [int(i)-1 for i in input().split()]
[gy,gx] = [int(i)-1 for i in input().split()]
c = []
s = ""
for i in range(r):
    s = input()
    c.append([])
    for j in range(len(s)):
        c[i].append(s[j])
#print(c)
done = [[sy,sx]]
next = [[sy,sx]]
next1 = []
x = sx
y = sy
counter = 1
while [gy,gx] not in done:
    for i in range(len(next)):
        y = next[i][0]
        x = next[i][1]
        if [y,x+1] not in done and c[y][x+1]=="." :
            done.append([y,x+1])
            next1.append([y,x+1])
            c[y][x+1] = str(counter)
        if [y,x-1] not in done and c[y][x-1]=="." :
            done.append([y,x-1])
            next1.append([y,x-1])
            c[y][x-1] = str(counter)
        if [y+1,x] not in done and c[y+1][x]=="." :
            done.append([y+1,x])
            next1.append([y+1,x])
            c[y+1][x] = str(counter)
        if [y-1,x] not in done and c[y-1][x]=="." :
            done.append([y-1,x])
            next1.append([y-1,x])
            c[y-1][x] = str(counter)

    next = next1
    next1 = []
    counter += 1
#    print(next)

print(int(c[gy][gx]))
#for i in range(r):
#    print(c[i])