s = input()
t = input()
 
s_c = []
t_c = []
for c in 'abcdefghijklmnopqrstuvwxyz':
    s_c.append(s.count(c))
    t_c.append(t.count(c))
s_c.sort()
t_c.sort()
if s_c == t_c:
  print('Yes')
else:
  print('No')