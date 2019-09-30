import sys
fastinput=sys.stdin.readline
N,T=map(int,fastinput().split())
p=[int(_) for _ in fastinput().split()]
oyumin=0
oyumax=0
Showertime=0
for i in p:
    if i>oyumax:
        Showertime+=oyumax-oyumin
        oyumin=i
        oyumax=i+T
    else:
        oyumax=i+T
Showertime+=oyumax-oyumin
print(Showertime)