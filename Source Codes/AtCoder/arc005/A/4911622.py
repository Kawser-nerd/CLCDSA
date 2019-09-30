n=int(input())
s=input()
l=s.split(' ')
c=0
c+=l.count('TAKAHASHIKUN')
c+=l.count('Takahashikun')
c+=l.count('takahashikun')
if l[-1]=='TAKAHASHIKUN.' or l[-1]=='Takahashikun.' or l[-1]=='takahashikun.':
  c+=1
print(c)