#16
s = input()
s = s.replace('ch','').replace('o','').replace('k','').replace('u','')
if s=='':
    print("YES")
else:
    print("NO")