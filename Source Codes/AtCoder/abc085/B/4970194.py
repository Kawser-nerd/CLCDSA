N=int(input())
a=[]
stage=0

for i in range(N):
    inp = int(input())
    if  inp not in a :
        a.append(inp)
        stage+=1
print(stage)