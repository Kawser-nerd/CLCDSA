a,b=[int(i) for i in input().split()]
print("Ant" if abs(a)<abs(b) else ("Bug" if abs(a)>abs(b) else "Draw"))