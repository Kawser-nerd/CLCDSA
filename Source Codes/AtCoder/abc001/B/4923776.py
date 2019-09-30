m=int(input())
if m<100:
  VV="00"
elif m<1000:
  VV="0"+str(m/100)
elif m<=5000:
  VV=str(m/100)
elif m<=30000:
  VV=str(m/1000+50)
elif m<=70000:
  VV=str((m/1000-30)/5+80)
else:
  VV="89"
print(VV[:2])