N=int(input().strip())
y=list(map(int, input().split()))

x=sorted(y)
xl=len(x)
for i in y:
    if i<(x[xl//2]):
        print(x[(xl//2)])
    else:
        print(x[(xl//2)-1])