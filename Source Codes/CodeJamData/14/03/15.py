def mines(r,c,m):
    if r==1:
        if m>=c:
            return "Impossible\n"
        else:
            return "c"+"."*(c-m-1)+"*"*m+"\n"
    elif c==1:
        if m>=r:
            return "Impossible\n"
        else:
            return "c\n"+".\n"*(r-m-1)+"*\n"*m
    elif m==c*r-1:
        return "c"+"*"*(c-1)+"\n"+("*"*c+"\n")*(r-1)
    elif (c==2 or r==2) and m//2*2!=m: #odd mines don't work with two wides
        return "Impossible\n"
    elif m>=c*r-3:
        return "Impossible\n"
    elif m>c*(r-2) or m==c*(r-2)-1:
       mineSurplus=m-c*(r-2)
       if mineSurplus//2*2 == mineSurplus:
            fullRows=r-2
            remainder=mineSurplus//2
            ret = ("."*(c-remainder)+"*"*remainder+"\n")*2+("*"*c+"\n")*fullRows
            return "c"+ret[1:]
       else:
            mineSurplus+=3
            fullRows=r-3
            remainder=mineSurplus//2
            if remainder>c-3:
                return "Impossible\n"
            ret = ("."*(c-remainder)+"*"*remainder+"\n")*2+("."*3+"*"*(c-3)+"\n")+("*"*c+"\n")*fullRows
            return "c"+ret[1:]
    elif (m+1)//c*c==m+1: #pinching left column
            fullRows=m//c
            remainder= m-fullRows*c-1
            #put a mine on far right of row above so we don't pinch
            ret = ("."*c+"\n")*(r-fullRows-2)+("."*(c-1)+"*"+"\n")+"."*(c-remainder)+"*"*remainder+"\n"+("*"*c+"\n")*fullRows
            return "c"+ret[1:]
    else:
            fullRows=m//c
            remainder= m-fullRows*c
            ret = ("."*c+"\n")*(r-fullRows-1)+"."*(c-remainder)+"*"*remainder+"\n"+("*"*c+"\n")*fullRows
            return "c"+ret[1:]
            
input_text = open("input.in")
lines = input_text.readlines()
input_text.close()
with open("output", "a") as outputfile:
    for num in range(0,int(lines[0])):
        line = lines[num+1].split(" ")
        outputfile.write("Case #"+str(num+1)+":\n"+mines(int(line[0]),int(line[1]),int(line[2])))
