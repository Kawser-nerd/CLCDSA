n,k=map(int,input().split())
d=list(input().split())
while n:
    p=str(n)
    c=0
    for i in range(len(p)):
        if p[i] in d:
            n+=1
            break
    else:
        break
print(n)