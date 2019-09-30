a,*s,g=input()
c=s.count
if a==g:
  if(len(s)-c(a)*2)%2:
    print('Second')
  else:
    print('First')
else:
  if(len(s)-max(c(a),c(g))*2)%2:
    print('First')
  else:
    print('Second')