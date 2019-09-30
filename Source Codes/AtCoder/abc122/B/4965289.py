a=input()
k=0
ans=0
for b in a:
    if (b=='A')or(b=='C')or(b=='G')or(b=='T'):
        k=k+1
    
    else:
        if ans<k:
            ans=k
        k=0
if ans<k:
	ans=k
print(ans)