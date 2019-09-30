x,y=[int(i) for i in input().split()]
cnt=0
for i in range(70):
    if x*(2**i)<=y:
        cnt+=1
print(cnt)