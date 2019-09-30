line=list(input())
i=0

while i<=(len(line))//2:
    if line[i]=="*" or line[len(line)-i-1]=="*" or line[i]==line[len(line)-i-1]:
        i=i+1
    else:
        print("NO")
        break

if i>(len(line))//2:
    print("YES")