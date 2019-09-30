a,b,c,d=map(str,input())
p=['+','-']
for i in p:
    for j in p:
        for x in p:
            s=a+i+b+j+c+x+d
            if eval(s)==7:
                print(s+'=7')
                exit()