m=int(input())
km=m/1000
if km<0.1:
    vv=('00')
elif km<=5:
    if km<1:
        vv='0'+str(int(km*10))
    else:
        vv=int(km*10)
elif km<=30:
    vv=int(km+50)
elif km<=70:
    vv=int(((km-30)/5)+80)
else:
    vv=int(89)
print((vv))