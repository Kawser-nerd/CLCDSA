n,l=map(int,input().split())
line=[]
line.append(" ")
for i in range(l+1):
    line.append(list(input()))
    
    
pos_ld=line[l+1].index("o")
def route_amida(line,length,width,n):
    if width==1:
        return 1
    else:
        if length==1:
            return int((n+2)/2)
    
        else:
            if n==0:
                if line[length-1][1]=='-':
                    n+=2


            elif n==2*width-2:
                if line[length-1][2*width-3]=='-':
                    n-=2


            else:
                if line[length-1][n+1]=='-':
                    n+=2
                elif line[length-1][n-1]=='-':
                    n-=2
    


    
            return route_amida(line[:length-1],(length-1),width,n)

print(route_amida(line[:l+1],l+1,n,pos_ld))