s=input()
k=int(input())
l=[]
for i in range(1,k+1):
    for t in range(len(s)-i+1):
        l.append(s[t:t+i])
print(sorted(set(l))[k-1])