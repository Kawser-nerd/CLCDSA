N=int(input())

S=input()

x=0
X=[0]

for s in S:
    if s=='I':
        x+=1
    if s=='D':
        x-=1
    X.append(x)

print(max(X))