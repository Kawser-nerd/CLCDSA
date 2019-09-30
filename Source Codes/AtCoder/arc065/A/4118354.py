S=input()
i=len(S)
ans="NO"
while(True):
    if(i==0):
        ans="YES"
        break
    if(i>=5 and S[i-5:i]=="dream"):
        i-=5
    elif(i >=5 and S[i-5:i]=="erase"):
        i-=5
    elif(i>=6 and S[i-6:i]=="eraser"):
        i-=6
    elif(i>=7 and S[i-7:i]=="dreamer"):
        i-=7
    else:
        break
print(ans)