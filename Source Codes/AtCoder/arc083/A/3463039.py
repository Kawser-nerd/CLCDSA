a,b,c,d,e,f=map(int, input().split())
x,y,z=100*a,0,0
for i in range(31):
    for j in range(31):
        mizu=(a*i+b*j)*100
        if mizu==0 or mizu>f:break
        for k in range(int((f-mizu)//c)+1):
            for l in range(int((f-mizu)//d)+1):
                sato=c*k+d*l
                noudo=100*sato/(mizu+sato)
                if mizu+sato>f or mizu/100*e<sato:break
                if noudo>z: z,x,y = noudo,mizu+sato,sato
print(x,y)