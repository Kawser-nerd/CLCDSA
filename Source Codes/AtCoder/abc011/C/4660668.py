n,*g=eval('int(input())+4,'*4);d=[0]*500
for i in range(5,n+1):d[i]=100*(i in g)-~min(d[i-3:i])
print('YNEOS'[d[n]>100::2])