n=list(map(int, input().split()))
n.sort(reverse = True)
count=0
while True:
    if n[1]>=n[0]:
        break
    n[1]+=2
    count+=1
while True:
    if n[2]>=n[0]:
        break
    n[2]+=2
    count+=1
n.sort(reverse=True)
if len(set(n))==1:
    print(count)
elif n.count(n[0])==2:
    print(count-1)
else:
    print(count+1)