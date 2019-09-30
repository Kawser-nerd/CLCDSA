H,W = map(int,input().split())
Ss = [["."]+[j for j in input()]+["."] for i in range(H)]
Ss.insert(0,["."]*len(Ss[0]))
Ss.append(["."]*len(Ss[0]))
ans = []
for i in range(1,len(Ss)-1):
    nums = []
    for j in range(1,len(Ss[i])-1):
        num = 0
        if Ss[i][j]==".":
            if Ss[i+1][j]=="#":
                num+=1
            if Ss[i+1][j+1]=="#":
                num+=1
            if Ss[i+1][j-1]=="#":
                num+=1
            if Ss[i-1][j]=="#":
                num+=1
            if Ss[i-1][j+1]=="#":
                num+=1
            if Ss[i-1][j-1]=="#":
                num+=1
            if Ss[i][j+1]=="#":
                num+=1
            if Ss[i][j-1]=="#":
                num+=1
            nums.append(str(num))
        else:
            nums.append("#")
    print("".join(nums))