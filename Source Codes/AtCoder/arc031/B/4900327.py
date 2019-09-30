a=[["x"]*12]+[list("x"+input()+"x")for i in range(10)]+[["x"]*12]
b=sum([i.count("o")for i in a])
for i in range(1,11):
    for j in range(1,11):
        if a[i][j]!="o":
            s=[i[:]for i in a]
            n=0
            d=[[i,j]]
            while len(d)>0:
                l=[]
                for p,q in d:
                    if s[p-1][q]=="o":
                        s[p-1][q]="x"
                        n+=1
                        l.append([p-1,q])
                    if s[p+1][q]=="o":
                        s[p+1][q]="x"
                        n+=1
                        l.append([p+1,q])
                    if s[p][q+1]=="o":
                        s[p][q+1]="x"
                        n+=1
                        l.append([p,q+1])
                    if s[p][q-1]=="o":
                        s[p][q-1]="x"
                        n+=1
                        l.append([p,q-1])
                else:
                    d=l
            else:
                if n==b:
                    print("YES")
                    exit()
else:
    print("NO")