s=[]
k=["LOSE","WIN"]
for i in range(int(input())):
    d=input()
    if i==0:
        s.append(d)
    elif d in s or s[-1][-1]!=d[0]:
        print(k[i%2])
        break
    else:
        s.append(d)
else:
    print("DRAW")