O=input()
E=input()
s=''
if len(O)-len(E)==1:
    for o,e in zip(O[:-1],E):
        s+=o+e
    s+=O[-1]
else:
    for o,e in zip(O,E):
        s+=o+e
print(s)