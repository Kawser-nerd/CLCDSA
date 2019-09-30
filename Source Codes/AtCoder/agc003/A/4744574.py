s=input();ans=0
if"N"in s:ans+=1
if"S"in s:ans-=1
if"E"in s:ans+=2
if"W"in s:ans-=2
print("Yes"if ans==0else"No")