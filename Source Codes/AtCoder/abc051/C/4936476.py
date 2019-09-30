sx,sy,tx,ty = map(int,input().split())
x=tx-sx
y=ty-sy

S=''
S+='R'*x
S+='U'*y
S+='L'*x
S+='D'*y

S+='D'
S+='R'*(x+1)
S+='U'*(y+1)
S+='L'

S+='U'
S+='L'*(x+1)
S+='D'*(y+1)
S+='R'

print(S)