s = input()

pre=""
cnt=0
res=""
for x in s:
    if x!=pre:
        if pre!="":
            res+=pre+str(cnt)
        pre = x
        cnt = 1

    else:
        cnt+=1
res += pre+str(cnt)
print(res)